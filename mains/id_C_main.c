/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 10:51:45 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/29 16:11:46 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	int res;

	/*
	** Printing positive numbers with dash = 0
	*/

	res = printf("%7.5d|", 123);
	printf(" %d\n", res);
	res = printf("%7.2d|", 123);
	printf(" %d\n", res);
	res = printf("%4.3d|", 12345);
	printf(" %d\n", res);
	res = printf("%3.4d|", 12345);
	printf(" %d\n", res);
	res = printf("%6.7d|", 12345);
	printf(" %d\n", res);
	res = printf("%2.7d|", 12345);
	printf(" %d\n", res);

	/*
	** Printing negative numbers with dash = 0
	*/

	res = printf("%7.5d|", -123);
	printf(" %d\n", res);
	res = printf("%7.2d|", -123);
	printf(" %d\n", res);
	res = printf("%4.3d|", -12345);
	printf(" %d\n", res);
	res = printf("%3.4d|", -12345);
	printf(" %d\n", res);
	res = printf("%7.9d|", -12345);
	printf(" %d\n", res);
	res = printf("%2.9d|", -12345);
	printf(" %d\n", res);

	/*
	** Printing with equal parameters with dash = 0
	** The parameters are: field width, precision and number length.
	** The number length includes the '-' sign. 
	** Thus -123 has length 4.
	*/
	
	res = printf("%7.7d|", 123);
	printf(" %d\n", res);
	res = printf("%2.2d|", 123);
	printf(" %d\n", res);
	res = printf("%4.3d|", 1234);
	printf(" %d\n", res);
	res = printf("%3.4d|", 1234);
	printf(" %d\n", res);
	res = printf("%2.2d|", 12);
	printf(" %d\n", res);

	res = printf("%7.7d|", -123);
	printf(" %d\n", res);
	res = printf("%2.2d|", -123);
	printf(" %d\n", res);
	res = printf("%5.3d|", -1234);
	printf(" %d\n", res);
	res = printf("%3.5d|", -1234);
	printf(" %d\n", res);
	res = printf("%3.3d|", -12);
	printf(" %d\n", res);
	
	/*
	** Printing with 0 parameters with dash = 0
	*/

	res = printf("%0.5d|", 123);
	printf(" %d\n", res);
	res = printf("%7.0d|", 123);
	printf(" %d\n", res);
	res = printf("%0.3d|", 12345);
	printf(" %d\n", res);
	res = printf("%3.0d|", 12345);
	printf(" %d\n", res);
	res = printf("%6.0d|", 0);
	printf(" %d\n", res);
	res = printf("%0.7d|", 0);
	printf(" %d\n", res);
	res = printf("%0.0d|", 0);
	printf(" %d\n", res);
	res = printf("%0.d|", 0);
	printf(" %d\n", res);

	/*
	** Print extreme values
	*/


	return (0);
}
