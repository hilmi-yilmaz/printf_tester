#!/bin/bash

CC=clang
FLAGS="-Wall -Wextra -Werror"
OUTPUT=output
C_MAIN_FILES=("d_C_main.c" "i_C_main.c" "c_C_main.c" "s_C_main.c" "x_C_main.c")
FT_MAIN_FILES=("d_ft_main.c" "i_ft_main.c" "c_ft_main.c" "s_ft_main.c" "x_ft_main.c")

#Create the logs directory if it does not exist yet.

if [[ ! -d logs ]]; then
	#echo "logs directory does not exist. Creating one..."
	mkdir logs
fi

#Create the diff directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d logs/diff ]]; then
	#echo "logs/diff directory does not exists yet. Creating one..."
	mkdir logs/diff
else
	#echo "logs/diff directory exists. Deleting contents..."
	rm -f logs/diff/*
fi

#Create the results directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d logs/results ]]; then
	#echo "logs/results directory does not exists yet. Creating one..."
	mkdir logs/results
else
	#echo "logs/results directory exists. Deleting contents..."
	rm -f logs/results/*
fi

#Create the valgrind directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d logs/valgrind ]]; then
	#echo "logs/valgrind directory does not exists yet. Creating one..."
	mkdir logs/valgrind
else
	#echo "logs/valgrind directory exists. Deleting contents..."
	rm -f logs/valgrind/*
fi

#Create the tmp directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d tmp ]]; then
	#echo "tmp directory does not exists yet. Creating one..."
	mkdir tmp
else
	#echo "tmp directory exists. Deleting contents..."
	rm -f tmp/*
fi

#Run "make" and check whether the libftprintf.a file is created
make re -C source_files > /dev/null
if [[ ! -f source_files/libftprintf.a ]]; then
	echo "The library libftprintf.a is not created after running \"make\"."
	echo "Make sure your Makefile creates the library first."
	exit 1
fi

#Function which prints the testcases for which ft_printf didn't work
print_test_cases()
{
	cat -n logs/results/${c_prefix}_printed > tmp/c_printed
	cat -n logs/results/${ft_prefix}_printed > tmp/ft_printed
	diff tmp/c_printed tmp/ft_printed | grep "<" | tr -s " " | cut -d " " -f 2 | cut -f 1 > tmp/${spec_prefix}_line_numbers
	while read line_nb; do
		grep "//${line_nb}" mains/${FT_MAIN_FILES[$i]}
	done < tmp/${spec_prefix}_line_numbers
	return
}

#Loop over the "C_MAIN_FILES" and "FT_MAIN_FILES" arrays, execute the programs and check for differences.
for i in ${!C_MAIN_FILES[@]}; do
	
	#Create a variable which will store a prefix to be used for logs file names
	c_prefix=$(echo ${C_MAIN_FILES[$i]} | cut -d '_' -f -2)
	ft_prefix=$(echo ${FT_MAIN_FILES[$i]} | cut -d '_' -f -2)
	spec_prefix=$(echo ${FT_MAIN_FILES[$i]} | cut -d '_' -f 1)

	echo "Running $spec_prefix test..."
	
	#Run the program with the C function and redirect the output to the 'logs/results' directory
	$CC $FLAGS mains/${C_MAIN_FILES[$i]} -o $OUTPUT && ./$OUTPUT > logs/results/${c_prefix}_printed
	if [[ "$?" != 0 ]]; then
		echo "Error on compilation. Fix these errors before continuing."
		exit 1
	fi

	#Run the program with own function and redirect the output to the 'logs/results' directory
	$CC $FLAGS -fsanitize=address -g mains/${FT_MAIN_FILES[$i]} source_files/libftprintf.a -o $OUTPUT
	./$OUTPUT > logs/results/${ft_prefix}_printed
	if [[ "$?" != 0 ]]; then
		echo "Error on compilation. Fix these errors before continuing."
		echo "The error happens with the following test:"
		line_error=$((1 + $(cat logs/results/${ft_prefix}_printed | wc -l)))
		echo "$(grep "//$line_error" mains/${FT_MAIN_FILES[$i]})"
		#exit 1
	fi
	
	#Check differences in printed text
	diff -a logs/results/${c_prefix}_printed logs/results/${ft_prefix}_printed >> logs/diff/${spec_prefix}_printed_diff
	if [[ "$?" != 0 ]]; then
		echo "There are differences between your output and the C output. Check logs/diff/$spec_prefix."
		print_test_cases
	else
		echo "Passed $spec_prefix printed test."
	fi

	#Check differences in return values
	diff logs/results/${c_prefix}_return_val logs/results/${ft_prefix}_return_val >> logs/diff/${spec_prefix}_return_val_diff
	if [[ "$?" != 0 ]]; then
		echo "There are differences between your return values  and the C return values. Check logs/diff/."
	else
		echo "Passed $spec_prefix return-values test."
	fi
done


#Testing with %p specifier
echo "Running p test..."
$CC $FLAGS -fsanitize=address -g mains/p_ft_C_main.c source_files/libftprintf.a -o $OUTPUT
./$OUTPUT
echo "Check the output of the %p specifier."
echo "The first address is the output of printf, the second is from ft_printf. Same for the return values"
while [[ "$REPLY" != "y" ]]; do
	echo "Please type y to continue."
	read -s -n 1
done


#Run a test with specific main and valgrind to check for memory errors.

#Delete unnecessary files
rm -rdf $OUTPUT tmp

#Delete al object files
make fclean -C source_files/ > /dev/null
make fclean -C source_files/libft/ > /dev/null
