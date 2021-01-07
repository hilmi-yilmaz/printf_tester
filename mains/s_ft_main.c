/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_ft_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/01 17:17:00 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/01/07 16:24:05 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../source_files/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	FILE *fd;
	int res;

	fd = fopen("logs/results/s_ft_return_val", "a+");
	if (fd == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}
	
	/*
	** Testing with single parameters
	*/

	res = ft_printf("%s\n", "codam");//1
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%10s\n", "codam");//2
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-10s\n", "codam");//3
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3s\n", "codam");//4
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3s\n", "codam");//5
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5s\n", "codam");//6
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5s\n", "codam");//7
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.3s\n", "codam");//8
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.3s\n", "codam");//9
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.7s\n", "codam");//10
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.7s\n", "codam");//11
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.5s\n", "codam");//12
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.5s\n", "codam");//13
	fprintf(fd, "%d\n", res);

	/*
	** Testing with length string longer than precesion and width
	*/

	res = ft_printf("%2.4s\n", "codam");//14
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%-2.4s\n", "codam");//15
	fprintf(fd, "%d\n", res);
	res = ft_printf("%4.2s\n", "codam");//16
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-4.2s\n", "codam");//17
	fprintf(fd, "%d\n", res);

	/*
	** Testing with length string in the middle of precesion and width
	*/

	res = ft_printf("%2.5s\n", "cod");//18
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%-2.5s\n", "cod");//19
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.2s\n", "cod");//20
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.2s\n", "cod");//21
	fprintf(fd, "%d\n", res);

	/*
	** Testing with length string smallest of precesion and width
	*/

	res = ft_printf("%4.5s\n", "cod");//22
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%-4.5s\n", "cod");//23
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.4s\n", "cod");//24
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.4s\n", "cod");//25
	fprintf(fd, "%d\n", res);

	/*
	** Testing with equal length: 
	** - string length = precision
	** - string length = width
	** - width = precision
	*/

	res = ft_printf("%4.4s\n", "codam");//26
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%-4.4s\n", "codam");//27
	fprintf(fd, "%d\n", res);
	res = ft_printf("%6.6s\n", "codam");//28
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-6.6s\n", "codam");//29
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.5s\n", "codam");//30
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.5s\n", "codam");//31
	fprintf(fd, "%d\n", res);
	res = ft_printf("%6.5s\n", "codam");//32
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-6.5s\n", "codam");//33
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.2s\n", "codam");//34
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.2s\n", "codam");//35
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.6s\n", "codam");//36
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.6s\n", "codam");//37
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.5s\n", "codam");//38
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.5s\n", "codam");//39
	fprintf(fd, "%d\n", res);

	/*
	** Test with empty string
	*/

	res = ft_printf("%-s\n", "");//40
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%s\n", "");//41
	fprintf(fd, "%d\n", res);
	res = ft_printf("%10s\n", "");//42
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-10s\n", "");//43
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3s\n", "");//44
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3s\n", "");//45
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5s\n", "");//46
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5s\n", "");//47
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.3s\n", "");//48
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.3s\n", "");//49
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.7s\n", "");//50
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.7s\n", "");//51
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.5s\n", "");//52
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.5s\n", "");//53
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.5s\n", "");//54
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.5s\n", "");//55
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.2s\n", "");//56
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.2s\n", "");//57
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.s\n", "");//58
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.s\n", "");//59
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.s\n", "");//60
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.s\n", "");//61
	fprintf(fd, "%d\n", res);

	/*
	** Testing with NULL
	*/

	res = ft_printf("%s\n", NULL);//62
	fprintf(fd, "%d\n", res);
	res = ft_printf("%10s\n", NULL);//63
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-10s\n", NULL);//64
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.5s\n", NULL);//65
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.2s\n", NULL);//66
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.6s\n", NULL);//67
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.7s\n", NULL);//68
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-10.3s\n", NULL);//69
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.10s\n", NULL);//70
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.s\n", NULL);//71
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.0s\n", NULL);//72
	fprintf(fd, "%d\n", res);

	/*
	** Testing with *
	*/

	res = ft_printf("%*s\n", 10, "codam");//73
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%*s\n", -10, "codam");//74
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%*s\n", 0, "codam");//75
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%.*s\n", 3, "codam");//76
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%*.*s\n", 2, 4, "codam");//77
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%-*.*s\n", -2, 4, "codam");//78
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.2s\n", 4, "codam");//79
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-4.*s\n", 2, "codam");//80
	fprintf(fd, "%d\n", res);

	/*
	** Testing with text
	*/

	res = ft_printf("We are %s students\n", "codam");//81
	fprintf(fd, "%d\n", res);	
	res = ft_printf("We are %s students and we love %s\n", "codam", "coding together");//82
	fprintf(fd, "%d\n", res);		
	res = ft_printf("We are %10s students\n", "codam");//83
	fprintf(fd, "%d\n", res);	
	res = ft_printf("We are %-10s students and we love %.4s\n", "codam", "coding together");//84
	fprintf(fd, "%d\n", res);	
	res = ft_printf("We are %*.*s students\n", 10, 3, "codam");//85
	fprintf(fd, "%d\n", res);	
	res = ft_printf("We are %*s students and we love %.*s\n", -10, "codam", 1, "coding together");//86
	fprintf(fd, "%d\n", res);

	/*
	** Extra tests
	*/

	res = ft_printf("%s\n", "(null)");//87
	fprintf(fd, "%d\n", res);
	res = ft_printf("%10s\n", "(null)");//88
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-10s\n", "(null)");//89
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.5s\n", "(null)");//90
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.2s\n", "(null)");//91
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.6s\n", "(null)");//92
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.7s\n", "(null)");//93
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-10.3s\n", "(null)");//94
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.10s\n", "(null)");//95
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.s\n", "(null)");//96
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.0s\n", "(null)");//72
	fprintf(fd, "%d\n", res);

	res = ft_printf("%*.*s is the best %*.*s\n", -15, -20, "utrecht", -1, -4, "yoooo");//73
	fprintf(fd, "%d\n", res);

	return (0);
}
