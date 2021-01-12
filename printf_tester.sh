#!/bin/bash

#User defined variables
HEADER_PATH="/home/hilmi/Desktop/Codam/curriculum/printf_tester/src/src/" #the path to your ft_printf.h file. Make sure your headerfile is called ft_printf.h.

# Colors
GREEN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
CYAN_B="\033[1;46m"
BLUE_B="\033[1;44m"
RESET="\033[0m"

#Define variables
CC=clang
FLAGS="-Wall -Wextra -Werror"
OUTPUT=output
C_MAIN_FILES=("d_C_main.c" "i_C_main.c" "u_C_main.c" "c_C_main.c" "s_C_main.c" "x_C_main.c" "X_C_main.c")
FT_MAIN_FILES=("d_ft_main.c" "i_ft_main.c" "u_ft_main.c" "c_ft_main.c" "s_ft_main.c" "x_ft_main.c" "X_ft_main.c")

#Create the logs directory if it does not exist yet.

if [[ ! -d logs ]]; then
	mkdir logs
fi

#Create the diff directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d logs/diff ]]; then
	mkdir logs/diff
else
	rm -f logs/diff/*
fi

#Create the results directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d logs/results ]]; then
	mkdir logs/results
else
	rm -f logs/results/*
fi

#Create the valgrind directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d logs/valgrind ]]; then
	mkdir logs/valgrind
else
	rm -f logs/valgrind/*
fi

#Create the tmp directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d tmp ]]; then
	mkdir tmp
else
	rm -f tmp/*
fi

#Create the wrong_test_cases directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ -f logs/wrong_test_cases ]]; then
	rm -f logs/wrong_test_cases
fi

#Run "make" and check whether the libftprintf.a file is created
make re -C src > /dev/null
if [[ ! -f src/libftprintf.a ]]; then
	echo -e "${RED}An error occured. Fix it.${RESET}"
	echo -e "${RED}The library libftprintf.a is not created after running \"make\".${RESET}"
	echo -e "${RED}Make sure your Makefile creates the library first.${RESET}"
	exit 1
fi

#Function which prints the testcases for which ft_printf didn't work
#It takes 4 arguments:
#	$1: c_prefix
#	$2: ft_prefix
#	$3: spec_prefix
#	$4: name of the main

print_test_cases()
{
	#Redirect the printed data of the C and ft-test to tmp directory with the line numbers (-n option)
	cat -ne logs/results/$1_printed > tmp/c_printed
	cat -ne logs/results/$2_printed > tmp/ft_printed

	#Obtain the line numbers that are different. Redirect this data to tmp/${spec_prefix}_line_numbers
	diff -a tmp/c_printed tmp/ft_printed | grep -a "<" | tr -s " " | cut -d " " -f 2 | cut -f 1 > tmp/$3_line_numbers
	echo "Wrong test cases with $3 test:" >> logs/wrong_test_cases
	echo "----- KEEP IN MIND THAT THE RETURN VALUES ARE +1 BECAUSE A \\n WAS ALSO PRINTED -----" >> logs/wrong_test_cases
	echo "" >> logs/wrong_test_cases

	#Loop through the file, which contains the line numbers that are different.
	while read line_nb; do
		grep -F -w "//${line_nb}" mains/$4 >> logs/wrong_test_cases
		echo "		Your output: |$(cat -v logs/results/$2_printed | sed -n "${line_nb}p")|" >> logs/wrong_test_cases
		echo "		C    output: |$(cat -v logs/results/$1_printed | sed -n "${line_nb}p")|" >> logs/wrong_test_cases
		echo "		Your return: $(cat -v logs/results/$2_return_val | sed -n "${line_nb}p")" >> logs/wrong_test_cases
		echo "		C    return: $(cat -v logs/results/$1_return_val | sed -n "${line_nb}p")" >> logs/wrong_test_cases
		echo "" >> logs/wrong_test_cases
	done < tmp/$3_line_numbers
	return
}

#Loop over the "C_MAIN_FILES" and "FT_MAIN_FILES" arrays, execute the programs and check for differences.
for i in ${!C_MAIN_FILES[@]}; do
	
	#Create a variable which will store a prefix to be used for logs file names
	c_prefix=$(echo ${C_MAIN_FILES[$i]} | cut -d '_' -f -2)
	ft_prefix=$(echo ${FT_MAIN_FILES[$i]} | cut -d '_' -f -2)
	spec_prefix=$(echo ${FT_MAIN_FILES[$i]} | cut -d '_' -f 1)

	echo -e "${CYAN_B}Running $spec_prefix test...${RESET}"
	
	#Run the program with the C function and redirect the output to the 'logs/results' directory
	$CC $FLAGS mains/${C_MAIN_FILES[$i]} -o $OUTPUT && ./$OUTPUT > logs/results/${c_prefix}_printed

	#Run the program with own function and redirect the output to the 'logs/results' directory
	$CC $FLAGS -I$HEADER_PATH -fsanitize=address -g mains/${FT_MAIN_FILES[$i]} src/libftprintf.a -o $OUTPUT
	./$OUTPUT > logs/results/${ft_prefix}_printed
	if [[ "$?" != 0 ]]; then
		echo -e "	${RED}Compilation error. Fix these errors before continuing.${RESET}"
		echo -e "	${RED}The error happens with the following test:${RESET}"
		line_error=$((1 + $(cat logs/results/${ft_prefix}_printed | wc -l)))
		echo "$(grep -w "//$line_error" mains/${FT_MAIN_FILES[$i]})"
		#exit 1
	fi
	
	#Check differences in printed text
	diff -a logs/results/${c_prefix}_printed logs/results/${ft_prefix}_printed >> logs/diff/${spec_prefix}_printed_diff
	if [[ "$?" != 0 ]]; then
		echo -e "	${RED}Did not pass $spec_prefix printed test. Check logs/diff/${spec_prefix}_printed_diff.${RESET}"
		print_test_cases $c_prefix $ft_prefix $spec_prefix ${FT_MAIN_FILES[$i]}
	else
		echo -e "	${GREEN}Passed $spec_prefix printed test.${RESET}"
	fi

	#Check differences in return values
	diff logs/results/${c_prefix}_return_val logs/results/${ft_prefix}_return_val >> logs/diff/${spec_prefix}_return_val_diff
	if [[ "$?" != 0 ]]; then
		echo -e "	${RED}Did not pass $spec_prefix return-value test. Check logs/diff/${spec_prefix}_return_val_diff.${RESET}"
	else
		echo -e "	${GREEN}Passed $spec_prefix return-values test.${RESET}"
	fi
	echo ""
done


#Testing with %p specifier
echo -e "${CYAN_B}Running p test...${RESET}"
$CC $FLAGS -I$HEADER_PATH -fsanitize=address -g mains/p_main.c src/libftprintf.a -o $OUTPUT
./$OUTPUT > logs/results/p_ft_printed
	
#Check differences in printed text for %p
diff -a logs/results/p_C_printed logs/results/p_ft_printed >> logs/diff/p_printed_diff
if [[ "$?" != 0 ]]; then
	echo -e "	${RED}Did not pass p printed test. Check logs/diff/p_printed_diff.${RESET}"
	print_test_cases "p_C" "p_ft" "p" "p_main.c"
else
	echo -e "	${GREEN}Passed p printed test.${RESET}"
fi

#Check differences in return values for %p
diff logs/results/c_C_return_val logs/results/c_ft_return_val >> logs/diff/p_return_val_diff
if [[ "$?" != 0 ]]; then
	echo -e "	${RED}Did not pass p return-value test. Check logs/diff/p_return_val_diff.${RESET}"
else
	echo -e "	${GREEN}Passed p return-values test.${RESET}"
fi
echo ""


#Run a test with specific main and valgrind to check for memory errors.

#Delete unnecessary files
rm -rdf $OUTPUT tmp

#Delete al object files
make fclean -C src/ > /dev/null
