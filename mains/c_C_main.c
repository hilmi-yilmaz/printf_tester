/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_C_main.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/01 16:02:18 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/01/01 16:26:52 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	FILE *fd;
	int res;

	fd = fopen("logs/results/c_C_return_val", "a+");
	if (fd == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}

	/* 
	** Testing with basic characters
	*/

	res = printf("%c|\n", 'p');
	fprintf(fd, "%d\n", res);
	res = printf("%3c|\n", 'p');
	fprintf(fd, "%d\n", res);
	res = printf("%-3c|\n", 'p');
	fprintf(fd, "%d\n", res);
	res = printf("%5c|\n", 'p');
	fprintf(fd, "%d\n", res);
	res = printf("%-5c|\n", 'p');
	fprintf(fd, "%d\n", res);	
	res = printf("%*c|\n", 4, 'p');
	fprintf(fd, "%d\n", res);
	res = printf("%-*c|\n", 4, 'p');
	fprintf(fd, "%d\n", res);

	/*
	** Printing with text
	*/

	res = printf("I am a %c%c%c%c%c student|\n", 'c', 'o', 'd', 'a', 'm');
	fprintf(fd, "%d\n", res);
	res = printf("I am a %10c%c%-10c%c%*c student|\n", 'c', 'o', 'd', 'a', 40, 'm');
	fprintf(fd, "%d\n", res);
	
	return (0);
}
