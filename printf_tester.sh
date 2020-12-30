#!/bin/bash

CC=clang
FLAGS="-Wall -Wextra -Werror"
C_MAIN="mains/id_C_main.c"
OWN_MAIN="mains/id_ft_main.c"
OUTPUT=output
C_MAIN_FILES=("id_C_main.c")
FT_MAIN_FILES=("id_ft_main.c")

#Create the logs directory if it does not exist yet.

if [[ ! -d logs ]]; then
	echo "logs directory does not exist. Creating one..."
	mkdir logs
fi

#Create the diff directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d logs/diff ]]; then
	echo "logs/diff directory does not exists yet. Creating one..."
	mkdir logs/diff
else
	echo "logs/diff directory exists. Deleting contents..."
	rm -f logs/diff/*
fi

#Create the results directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d logs/results ]]; then
	echo "logs/results directory does not exists yet. Creating one..."
	mkdir logs/results
else
	echo "logs/results directory exists. Deleting contents..."
	rm -f logs/results/*
fi

#Create the valgrind directory inside the logs directory if it does not exists yet. If it does exists, delete the contents.

if [[ ! -d logs/valgrind ]]; then
	echo "logs/valgrind directory does not exists yet. Creating one..."
	mkdir logs/valgrind
else
	echo "logs/valgrind directory exists. Deleting contents..."
	rm -f logs/valgrind/*
fi

#Run "make" and check whether the libftprintf.a file is created
make re -C source_files > /dev/null
if [[ ! -f source_files/libftprintf.a ]]; then
	echo "The library libftprintf.a is not created after running \"make\"."
	echo "Make sure your Makefile creates the library first."
	exit 1
fi

#Loop over the "C_MAIN_FILES" and "FT_MAIN_FILES" arrays, execute the programs and check for differences.
for i in ${!C_MAIN_FILES[@]}; do
	
	#Create a variable which will store a prefix to be used for logs file names
	c_prefix=$(echo ${C_MAIN_FILES[$i]} | cut -d '_' -f -2)
	ft_prefix=$(echo ${FT_MAIN_FILES[$i]} | cut -d '_' -f -2)
	spec_prefix=$(echo ${FT_MAIN_FILES[$i]} | cut -d '_' -f 1)

	#Run the program with the C function and redirect the output to the 'logs/results' directory
	echo "Running the C program"
	$CC $FLAGS mains/${C_MAIN_FILES[$i]} -o $OUTPUT && ./$OUTPUT > logs/results/printed_${c_prefix}
	if [[ "$?" != 0 ]]; then
		echo "Error on compilation. Fix these errors before continuing."
		exit 1
	fi

	#Run the program with own function and redirect the output to the 'logs/results' directory
	echo "Running own program"
	$CC $FLAGS -fsanitize=address -g mains/${FT_MAIN_FILES[$i]} source_files/libftprintf.a -o $OUTPUT
	./$OUTPUT > logs/results/printed_${ft_prefix}
	if [[ "$?" != 0 ]]; then
		echo "Error on compilation. Fix these errors before continuing."
		exit 1
	fi
	
	#Check differences in printed text
	diff logs/results/printed_${c_prefix} logs/results/printed_${ft_prefix} >> logs/diff/${spec_prefix}
	if [[ "$?" != 0 ]]; then
		echo "There are differences between your output and the C output. Check logs/diff/$spec_prefix."
	else
		echo "Passed d, i printed test."
	fi

	#Check differences in return values
	diff logs/results/return_val_${c_prefix} logs/results/return_val_${ft_prefix} >> logs/diff/${spec_prefix}
	if [[ "$?" != 0 ]]; then
		echo "There are differences between your return values  and the C return values. Check logs/diff/."
	else
		echo "Passed d, i return values test."
	fi
done

#Delete the executable
rm $OUTPUT

#Delete al object files
make fclean -C source_files/ > /dev/null
make fclean -C source_files/libft/ > /dev/null
