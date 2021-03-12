#!/bin/bash

# Colors
GREEN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
CYAN_B="\033[1;46m"
BLUE_B="\033[1;44m"
RESET="\033[0m"

# Define variables
CC=clang
FLAGS="-Wall -Wextra -Werror"
OUTPUT=output
C_MAIN_FILES=("d_C_main.c" "i_C_main.c" "u_C_main.c" "c_C_main.c" "s_C_main.c" "x_C_main.c" "bigX_C_main.c" "percentage_C_main.c")
FT_MAIN_FILES=("d_ft_main.c" "i_ft_main.c" "u_ft_main.c" "c_ft_main.c" "s_ft_main.c" "x_ft_main.c" "bigX_ft_main.c" "percentage_ft_main.c")

# If commmand line arguments, run only a specific test
if [[ -n "$1" ]]; then
	if [[ "$1" == "d" || "$1" == "i" || "$1" == "u" || "$1" == "x" || "$1" == "X" || "$1" == "s" || "$1" == "c" || "$1" == "percentage" ]]; then
		C_MAIN_FILES=("${1}_C_main.c")
		FT_MAIN_FILES=("${1}_ft_main.c")
	elif [[ "$1" == "p" ]]; then
		C_MAIN_FILES=()
		FT_MAIN_FILES=()
	else
		echo "Run the tester as: ./printf_tester [d|i|u|x|X|s|c|p|percentage]"
		exit 1
	fi
fi
	

# Create the logs directory if it does not exist yet.

if [[ ! -d logs ]]; then
	mkdir logs
fi

# Create the diff directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d logs/diff ]]; then
	mkdir logs/diff
else
	rm -f logs/diff/*
fi

# Create the results directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d logs/results ]]; then
	mkdir logs/results
else
	rm -f logs/results/*
fi

# Create the tmp directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d tmp ]]; then
	mkdir tmp
else
	rm -f tmp/*
fi

# Create the wrong_test_cases file inside the logs directory if it does not exists yet.
[ -e logs/wrong_test_cases ] && rm -f logs/wrong_test_cases
touch logs/wrong_test_cases

# Run "make" and check whether the libftprintf.a file is created
make re -C src > /dev/null
if [[ ! -f src/libftprintf.a ]]; then
	echo -e "${RED}An error occured. Fix it.${RESET}"
	echo -e "${RED}The library libftprintf.a is not created after running \"make\".${RESET}"
	echo -e "${RED}Make sure your Makefile creates the library first.${RESET}"
	exit 1
fi

# Function which prints the testcases for which ft_printf didn't work
# It takes 4 arguments:
#	$1: c_prefix
#	$2: ft_prefix
#	$3: spec_prefix
#	$4: printed or return_val
#	$5: name of the main

print_test_cases()
{
	# Redirect the printed data of the C and ft-test to tmp directory with the line numbers (-n option)
	cat -ne logs/results/$1_$4 > tmp/c_$4
	cat -ne logs/results/$2_$4 > tmp/ft_$4

	# Obtain the line numbers that are different. Redirect this data to tmp/${spec_prefix}_line_numbers
	diff -a tmp/c_$4 tmp/ft_$4 | grep -a "<" | tr -s " " | cut -d " " -f 2 | cut -f 1 > tmp/$3_line_numbers
	if ! grep -Fq "Wrong test cases with $3 test:" logs/wrong_test_cases
	then
		echo "Wrong test cases with $3 test:" >> logs/wrong_test_cases
		echo "----- KEEP IN MIND THAT THE RETURN VALUES ARE +1 BECAUSE A \\n WAS ALSO PRINTED -----" >> logs/wrong_test_cases
		echo "" >> logs/wrong_test_cases
	fi


	# Loop through the file, which contains the line numbers that are different.
	while read line_nb; do
		test_case=$(grep -F -w "//${line_nb}" mains/$5)
		if grep -Fq "$test_case" logs/wrong_test_cases
		then
			continue
		fi
		echo "$test_case" >> logs/wrong_test_cases
		echo "		Your output: |$(cat -v logs/results/$2_printed | sed -n "${line_nb}p")|" >> logs/wrong_test_cases
		echo "		C    output: |$(cat -v logs/results/$1_printed| sed -n "${line_nb}p")|" >> logs/wrong_test_cases
		echo "		Your return: $(cat -v logs/results/$2_return_val | sed -n "${line_nb}p")" >> logs/wrong_test_cases
		echo "		C    return: $(cat -v logs/results/$1_return_val | sed -n "${line_nb}p")" >> logs/wrong_test_cases
		echo "" >> logs/wrong_test_cases
	done < tmp/$3_line_numbers
	return
}

# Loop over the "C_MAIN_FILES" and "FT_MAIN_FILES" arrays, execute the programs and check for differences.
for i in ${!C_MAIN_FILES[@]}; do
	
	# Create a variable which will store a prefix to be used for logs file names
	c_prefix=$(echo ${C_MAIN_FILES[$i]} | cut -d '_' -f -2)
	ft_prefix=$(echo ${FT_MAIN_FILES[$i]} | cut -d '_' -f -2)
	spec_prefix=$(echo ${FT_MAIN_FILES[$i]} | cut -d '_' -f 1)

	echo -e "${CYAN_B}Running $spec_prefix test...${RESET}"
	
	# Run the program with the C function and redirect the output to the 'logs/results' directory
	$CC $FLAGS mains/${C_MAIN_FILES[$i]} -o $OUTPUT && ./$OUTPUT > logs/results/${c_prefix}_printed

	# Run the program with own function and redirect the output to the 'logs/results' directory
	$CC $FLAGS -fsanitize=address -g mains/${FT_MAIN_FILES[$i]} src/libftprintf.a -o $OUTPUT
	./$OUTPUT > logs/results/${ft_prefix}_printed
	if [[ "$?" != 0 ]]; then
		echo -e "	${RED}Compilation error. Fix these errors before continuing.${RESET}"
		echo -e "	${RED}The error happens with the following test:${RESET}"
		line_error=$((1 + $(cat logs/results/${ft_prefix}_printed | wc -l)))
		echo "$(grep -w "//$line_error" mains/${FT_MAIN_FILES[$i]})"
		#exit 1
	fi
	
	# Check differences in printed text
	diff -a logs/results/${c_prefix}_printed logs/results/${ft_prefix}_printed >> logs/diff/${spec_prefix}_printed_diff
	if [[ "$?" != 0 ]]; then
		echo -e "	${RED}Did not pass $spec_prefix printed test. Check logs/diff/${spec_prefix}_printed_diff.${RESET}"
		print_test_cases $c_prefix $ft_prefix $spec_prefix "printed" ${FT_MAIN_FILES[$i]}
	else
		echo -e "	${GREEN}Passed $spec_prefix printed test.${RESET}"
	fi

	# Check differences in return values
	diff logs/results/${c_prefix}_return_val logs/results/${ft_prefix}_return_val >> logs/diff/${spec_prefix}_return_val_diff
	if [[ "$?" != 0 ]]; then
		echo -e "	${RED}Did not pass $spec_prefix return-value test. Check logs/diff/${spec_prefix}_return_val_diff.${RESET}"
		print_test_cases $c_prefix $ft_prefix $spec_prefix "return_val" ${FT_MAIN_FILES[$i]}
	else
		echo -e "	${GREEN}Passed $spec_prefix return-values test.${RESET}"
	fi
	echo ""
done


# Testing with %p specifier
if [[ -z "$1" || "$1" == "p" ]]; then
	echo -e "${CYAN_B}Running p test...${RESET}"
	$CC $FLAGS -fsanitize=address -g mains/p_main.c src/libftprintf.a -o $OUTPUT
	./$OUTPUT > logs/results/p_ft_printed
		
	# Check differences in printed text for %p
	diff -a logs/results/p_C_printed logs/results/p_ft_printed >> logs/diff/p_printed_diff
	if [[ "$?" != 0 ]]; then
		echo -e "	${RED}Did not pass p printed test. Check logs/diff/p_printed_diff.${RESET}"
		print_test_cases "p_C" "p_ft" "p" "printed" "p_main.c"
	else
		echo -e "	${GREEN}Passed p printed test.${RESET}"
	fi

	# Check differences in return values for %p
	diff logs/results/p_C_return_val logs/results/p_ft_return_val >> logs/diff/p_return_val_diff
	if [[ "$?" != 0 ]]; then
		echo -e "	${RED}Did not pass p return-value test. Check logs/diff/p_return_val_diff.${RESET}"
		print_test_cases "p_C" "p_ft" "p" "return_val" "p_main.c"
	else
		echo -e "	${GREEN}Passed p return-values test.${RESET}"
	fi
	echo ""
fi


# Amount of tests wrong depending on how the test is run
count_failed=$(grep -w "ft_printf" logs/wrong_test_cases | wc -l)
if [[ -z "$1" ]]; then
	total_tests=$(grep -r "//" ./mains/*C_main.c ./mains/p_main.c | wc -l)
elif [[ "$1"  == "p" ]]; then
	total_tests=$(grep -r "//" ./mains/p_main.c | wc -l)
else
	total_tests=$(grep -r "//" ./mains/${1}_C_main.c | wc -l)
fi

#Truncate the spaces
count_failed=$(echo "$count_failed" | tr -d ' ')
total_tests=$(echo "$total_tests" | tr -d ' ')

# Show the statistics to the user
if [[ "$count_failed" == "0" ]]; then
	echo -e "${GREEN}You passed all tests ($total_tests/$total_tests).${RESET}"
else
	echo -e "${RED}You failed $count_failed tests ($(($total_tests - $count_failed))/$total_tests). See logs/wrong_test_cases.${RESET}"
fi

# Delete unnecessary files and directories
rm -rdf $OUTPUT tmp

# Delete al object files
make fclean -C src/ > /dev/null
