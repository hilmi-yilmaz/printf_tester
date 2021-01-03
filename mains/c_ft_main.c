/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_C_main.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/01 16:02:18 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/01/03 20:41:15 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../source_files/ft_printf.h"

int		main(void)
{
	int i;
	FILE *fd;
	int res;

	i = 0;
	fd = fopen("logs/results/c_ft_return_val", "a+");
	if (fd == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}

	/* 
	** Testing with basic characters
	*/
	
	res = ft_printf("%c\n", 40);//29
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3c\n", 40);//30
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3c\n", 40);//31
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5c\n", 40);//32
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5c\n", 40);//33
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*c\n", 4, 40);//34
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*c\n", 4, 40);//35
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%c\n", 50);//36
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3c\n", 50);//37
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3c\n", 50);//38
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5c\n", 50);//39
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5c\n", 50);//40
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*c\n", 4, 50);//41
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*c\n", 4, 50);//42
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%c\n", 60);//43
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3c\n", 60);//44
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3c\n", 60);//45
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5c\n", 60);//46
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5c\n", 60);//47
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*c\n", 4, 60);//48
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*c\n", 4, 60);//49
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%c\n", 70);//50
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3c\n", 70);//51
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3c\n", 70);//52
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5c\n", 70);//53
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5c\n", 70);//54
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*c\n", 4, 70);//55
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*c\n", 4, 70);//56
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%c\n", 80);//57
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3c\n", 80);//58
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3c\n", 80);//59
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5c\n", 80);//60
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5c\n", 80);//61
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*c\n", 4, 80);//62
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*c\n", 4, 80);//63
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%c\n", 90);//64
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3c\n", 90);//65
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3c\n", 90);//66
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5c\n", 90);//67
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5c\n", 90);//68
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*c\n", 4, 90);//69
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*c\n", 4, 90);//70
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%c\n", 100);//71
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3c\n", 100);//72
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3c\n", 100);//73
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5c\n", 100);//74
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5c\n", 100);//75
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*c\n", 4, 100);//76
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*c\n", 4, 100);//77
	fprintf(fd, "%d\n", res);
	
	/*
	** Printing with text
	*/

	res = ft_printf("I am a %c%c%c%c%c student\n", 'c', 'o', 'd', 'a', 'm');//78
	fprintf(fd, "%d\n", res);
	res = ft_printf("I am a %10c%c%-10c%c%*c student\n", 'c', 'o', 'd', 'a', 40, 'm');//79
	fprintf(fd, "%d\n", res);
	
	return (0);
}
