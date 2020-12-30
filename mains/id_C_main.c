/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 10:51:45 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/30 12:13:12 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	FILE *fd;
	int res;

	fd = fopen("logs/results/return_val_id_C", "a+");
	if (fd == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}

	/*
	** Printing positive numbers with dash = 0
	*/

	res = printf("%7.5d", 123);
	fprintf(fd, "%d\n", res);
	res = printf("%7.2d", 123);
	fprintf(fd, "%d\n", res);
	res = printf("%4.3d", 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%3.4d", 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%6.7d", 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%2.7d", 12345);
	fprintf(fd, "%d\n", res);

	/*
	** Printing negative numbers with dash = 0
	*/

	res = printf("%7.5d", -123);
	fprintf(fd, "%d\n", res);
	res = printf("%7.2d", -123);
	fprintf(fd, "%d\n", res);
	res = printf("%4.3d", -12345);
	fprintf(fd, "%d\n", res);
	res = printf("%3.4d", -12345);
	fprintf(fd, "%d\n", res);
	res = printf("%7.9d", -12345);
	fprintf(fd, "%d\n", res);
	res = printf("%2.9d", -12345);
	fprintf(fd, "%d\n", res);

	/*
	** Printing with equal parameters with dash = 0
	** The parameters are: field width, precision and number length.
	** The number length includes the '-' sign. 
	** Thus -123 has length 4.
	*/
	
	res = printf("%7.7d", 123);
	fprintf(fd, "%d\n", res);
	res = printf("%2.2d", 123);
	fprintf(fd, "%d\n", res);
	res = printf("%4.3d", 1234);
	fprintf(fd, "%d\n", res);
	res = printf("%3.4d", 1234);
	fprintf(fd, "%d\n", res);
	res = printf("%2.2d", 12);
	fprintf(fd, "%d\n", res);

	res = printf("%7.7d", -123);
	fprintf(fd, "%d\n", res);
	res = printf("%2.2d", -123);
	fprintf(fd, "%d\n", res);
	res = printf("%5.3d", -1234);
	fprintf(fd, "%d\n", res);
	res = printf("%3.5d", -1234);
	fprintf(fd, "%d\n", res);
	res = printf("%3.3d", -12);
	fprintf(fd, "%d\n", res);
	
	/*
	** Printing with 0 parameters with dash = 0
	*/

	res = printf("%0.5d", 123);
	fprintf(fd, "%d\n", res);
	res = printf("%7.0d", 123);
	fprintf(fd, "%d\n", res);
	res = printf("%0.3d", 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%3.0d", 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%6.0d", 0);
	fprintf(fd, "%d\n", res);
	res = printf("%6.d", 0);
	fprintf(fd, "%d\n", res);
	res = printf("%0.7d", 0);
	fprintf(fd, "%d\n", res);
	res = printf("%0.0d", 0);
	fprintf(fd, "%d\n", res);
	res = printf("%0.d", 0);
	fprintf(fd, "%d\n", res);

	/*
	** Print extreme values with dash = 0
	*/
	
	res = printf("%15.5d", 2147483647);
	fprintf(fd, "%d\n", res);
	res = printf("%15.15d", 2147483647);
	fprintf(fd, "%d\n", res);
	res = printf("%15.5d", -2147483647);
	fprintf(fd, "%d\n", res);
	res = printf("%15.15d", -2147483647);
	fprintf(fd, "%d\n", res);

	/*
	** Printing with extra zeros with dash = 0
	*/

	res = printf("%d", 001);
	fprintf(fd, "%d\n", res);
	res = printf("%d", -001);
	fprintf(fd, "%d\n", res);
	res = printf("%15.5d", 001);
	fprintf(fd, "%d\n", res);
	res = printf("%15.15d", -001);
	fprintf(fd, "%d\n", res);

	/*
	** Printing with '+' with dash = 0
	*/

	res = printf("%d", +123);
	fprintf(fd, "%d\n", res);
	res = printf("%d", +0);
	fprintf(fd, "%d\n", res);

	/*
	** Printing with * with dash = 0 and dash = 1 
	*/

	res = printf("%*.5d", 7, 123);
	fprintf(fd, "%d\n", res);
	res = printf("%7.*d", 2, 123);
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d", 4, 3, 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d", -4, 3, 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*d", -4, 3, 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d", -8, 3, 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*d", -8, 3, 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d", -4, -3, 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*d", -4, -3, 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d", -8, -3, 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*d", -8, -3, 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d", -4, -10, 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*d", -4, -10, 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d", -8, -10, 12345);
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*d", -8, -10, 12345);
	fprintf(fd, "%d\n", res);

	return (0);
}
