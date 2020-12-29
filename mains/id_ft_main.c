/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_main.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 10:53:11 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/29 16:11:43 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../source_files/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int res;

	/*
	** Printing positive numbers with dash = 0
	*/

	res = ft_printf("%7.5d|", 123);
	printf(" %d\n", res);
	res = ft_printf("%7.2d|", 123);
	printf(" %d\n", res);
	res = ft_printf("%4.3d|", 12345);
	printf(" %d\n", res);
	res = ft_printf("%3.4d|", 12345);
	printf(" %d\n", res);
	res = ft_printf("%6.7d|", 12345);
	printf(" %d\n", res);
	res = ft_printf("%2.7d|", 12345);
	printf(" %d\n", res);

	/*
	** Printing negative numbers with dash = 0
	*/

	res = ft_printf("%7.5d|", -123);
	printf(" %d\n", res);
	res = ft_printf("%7.2d|", -123);
	printf(" %d\n", res);
	res = ft_printf("%4.3d|", -12345);
	printf(" %d\n", res);
	res = ft_printf("%3.4d|", -12345);
	printf(" %d\n", res);
	res = ft_printf("%7.9d|", -12345);
	printf(" %d\n", res);
	res = ft_printf("%2.9d|", -12345);
	printf(" %d\n", res);

	/*
	** Printing with equal parameters with dash = 0
	** The parameters are: field width, precision and number length.
	** The number length includes the '-' sign. 
	** Thus -123 has length 4.
	*/
	
	res = ft_printf("%7.7d|", 123);
	printf(" %d\n", res);
	res = ft_printf("%2.2d|", 123);
	printf(" %d\n", res);
	res = ft_printf("%4.3d|", 1234);
	printf(" %d\n", res);
	res = ft_printf("%3.4d|", 1234);
	printf(" %d\n", res);
	res = ft_printf("%2.2d|", 12);
	printf(" %d\n", res);

	res = ft_printf("%7.7d|", -123);
	printf(" %d\n", res);
	res = ft_printf("%2.2d|", -123);
	printf(" %d\n", res);
	res = ft_printf("%5.3d|", -1234);
	printf(" %d\n", res);
	res = ft_printf("%3.5d|", -1234);
	printf(" %d\n", res);
	res = ft_printf("%3.3d|", -12);
	printf(" %d\n", res);
	
	/*
	** Printing with 0 parameters with dash = 0
	*/

	res = ft_printf("%0.5d|", 123);
	printf(" %d\n", res);
	res = ft_printf("%7.0d|", 123);
	printf(" %d\n", res);
	res = ft_printf("%0.3d|", 12345);
	printf(" %d\n", res);
	res = ft_printf("%3.0d|", 12345);
	printf(" %d\n", res);
	res = ft_printf("%6.0d|", 0);
	printf(" %d\n", res);
	res = ft_printf("%0.7d|", 0);
	printf(" %d\n", res);
	res = ft_printf("%0.0d|", 0);
	printf(" %d\n", res);
	res = ft_printf("%0.d|", 0);
	printf(" %d\n", res);

	/*
	** Print extreme values
	*/

	return (0);
}
