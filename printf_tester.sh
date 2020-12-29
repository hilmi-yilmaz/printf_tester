#!/bin/bash

FLAGS="-Wall -Wextra -Werror -fsanitize=address -g"
C_MAIN="mains/id_C_main.c"
OWN_MAIN="mains/id_ft_main.c"
OUTPUT=output

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
	echo "logs/diff directory exists. Deleting contents..."
	rm -f logs/results/*
fi

#Run "make" and check whether the libftprintf.a file is created
make -C source_files > /dev/null
if [[ ! -f source_files/libftprintf.a ]]; then
	echo "The library libftprintf.a is not created after running \"make\"."
	echo "Make sure your Makefile creates the library first."
	exit 1
fi

#Run the program with the C function and redirect the output to the results directory
echo "Running the C program"
gcc $FLAGS $C_MAIN -o $OUTPUT && ./$OUTPUT >> logs/results/result_1
if [[ "$?" != 0 ]]; then
	echo "Error on compilation."
	exit 1
fi

#Run the program with own function and redirect the output to the results directory
echo "Running own program"
gcc $FLAGS $OWN_MAIN source_files/libftprintf.a -o $OUTPUT && ./$OUTPUT >> logs/results/result_2

#Check differences
diff logs/results/result_1 logs/results/result_2 >> logs/diff/diff_1
if [[ "$?" != 0 ]]; then
	echo "There are differences between your output and the C output. Check logs/diff/."
fi

#Delete the executable
rm $OUTPUT

#Delete al object files
make fclean -C source_files/ > /dev/null
make fclean -C source_files/libft/ > /dev/null
