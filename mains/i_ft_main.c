/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   id_C_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 18:36:08 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/01/01 15:57:53 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../source_files/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	FILE *fd;
	int res;

	fd = fopen("logs/results/i_ft_return_val", "a+");
	if (fd == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}

	/*
	** Printing positive numbers
	*/
	
	res = ft_printf("%i\n", 999);//1
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7i\n", 999);//2
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.7i\n", 12345);//3
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.i\n", 12345);//4
	fprintf(fd, "%d\n", res);
	res = ft_printf("%010.i\n", 12345);//5
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.7i\n", 12345);//6
	fprintf(fd, "%d\n", res);

	res = ft_printf("%7.5i\n", 123);//7
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.2i\n", 123);//8
	fprintf(fd, "%d\n", res);
	res = ft_printf("%4.3i\n", 12345);//9
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.4i\n", 12345);//10
	fprintf(fd, "%d\n", res);
	res = ft_printf("%6.7i\n", 12345);//11
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.7i\n", 12345);//12
	fprintf(fd, "%d\n", res);

	res = ft_printf("%-7.5i\n", 123);//13
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-7.2i\n", 123);//14
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-4.3i\n", 12345);//15
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3.4i\n", 12345);//16
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-6.7i\n", 12345);//17
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.7i\n", 12345);//18
	fprintf(fd, "%d\n", res);

	res = ft_printf("%07.5i\n", 123);//19
	fprintf(fd, "%d\n", res);
	res = ft_printf("%07.2i\n", 123);//20
	fprintf(fd, "%d\n", res);
	res = ft_printf("%04.3i\n", 12345);//21
	fprintf(fd, "%d\n", res);
	res = ft_printf("%03.4i\n", 12345);//22
	fprintf(fd, "%d\n", res);
	res = ft_printf("%06.7i\n", 12345);//23
	fprintf(fd, "%d\n", res);
	res = ft_printf("%02.7i\n", 12345);//24
	fprintf(fd, "%d\n", res);

	/*
	** Printing negative numbers
	*/

	res = ft_printf("%7.5i\n", -123);//25
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.2i\n", -123);//26
	fprintf(fd, "%d\n", res);
	res = ft_printf("%4.3i\n", -12345);//27
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.4i\n", -12345);//28
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.9i\n", -12345);//29
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.9i\n", -12345);//30
	fprintf(fd, "%d\n", res);

	res = ft_printf("%-7.5i\n", -123);//31
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-7.2i\n", -123);//32
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-4.3i\n", -12345);//33
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3.4i\n", -12345);//34
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-7.9i\n", -12345);//35
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.9i\n", -12345);//36
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%07.5i\n", -123);//37
	fprintf(fd, "%d\n", res);
	res = ft_printf("%07.2i\n", -123);//38
	fprintf(fd, "%d\n", res);
	res = ft_printf("%04.3i\n", -12345);//39
	fprintf(fd, "%d\n", res);
	res = ft_printf("%03.4i\n", -12345);//40
	fprintf(fd, "%d\n", res);
	res = ft_printf("%07.9i\n", -12345);//41
	fprintf(fd, "%d\n", res);
	res = ft_printf("%02.9i\n", -12345);//42
	fprintf(fd, "%d\n", res);

	/*
	** Printing with equal parameters with dash = 0
	** The parameters are: field width, precision and number length.
	** The number length includes the '-' sign. 
	** Thus -123 has length 4.
	*/
	
	res = ft_printf("%7.7i\n", 123);//43
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.2i\n", 123);//44
	fprintf(fd, "%d\n", res);
	res = ft_printf("%4.3i\n", 1234);//45
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.4i\n", 1234);//46
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.2i\n", 12);//47
	fprintf(fd, "%d\n", res);

	res = ft_printf("%7.7i\n", -123);//48
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.2i\n", -123);//49
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.3i\n", -1234);//50
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.5i\n", -1234);//51
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.3i\n", -12);//52
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%-7.7i\n", 123);//53
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.2i\n", 123);//54
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-4.3i\n", 1234);//55
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3.4i\n", 1234);//56
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.2i\n", 12);//57
	fprintf(fd, "%d\n", res);

	res = ft_printf("%-7.7i\n", -123);//58
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.2i\n", -123);//59
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.3i\n", -1234);//60
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3.5i\n", -1234);//61
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3.3i\n", -12);//62
	fprintf(fd, "%d\n", res);

	res = ft_printf("%07.7i\n", 123);//63
	fprintf(fd, "%d\n", res);
	res = ft_printf("%02.2i\n", 123);//64
	fprintf(fd, "%d\n", res);
	res = ft_printf("%04.3i\n", 1234);//65
	fprintf(fd, "%d\n", res);
	res = ft_printf("%03.4i\n", 1234);//66
	fprintf(fd, "%d\n", res);
	res = ft_printf("%02.2i\n", 12);//67
	fprintf(fd, "%d\n", res);

	res = ft_printf("%07.7i\n", -123);//68
	fprintf(fd, "%d\n", res);
	res = ft_printf("%02.2i\n", -123);//69
	fprintf(fd, "%d\n", res);
	res = ft_printf("%05.3i\n", -1234);//70
	fprintf(fd, "%d\n", res);
	res = ft_printf("%03.5i\n", -1234);//71
	fprintf(fd, "%d\n", res);
	res = ft_printf("%03.3i\n", -12);//72
	fprintf(fd, "%d\n", res);

	/*
	** Printing with 0 parameters
	*/

	res = ft_printf("%0.5i\n", 123);//73
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.0i\n", 123);//74
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.3i\n", 12345);//75
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.0i\n", 12345);//76
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.5i\n", -123);//77
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.0i\n", -123);//78
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.3i\n", -12345);//79
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.0i\n", -12345);//80
	fprintf(fd, "%d\n", res);
	res = ft_printf("%6.0i\n", 0);//81
	fprintf(fd, "%d\n", res);
	res = ft_printf("%6.i\n", 0);//82
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.7i\n", 0);//83
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.0i\n", 0);//84
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.i\n", 0);//85
	fprintf(fd, "%d\n", res);

	res = ft_printf("%-7.0i\n", 123);//86
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3.0i\n", 12345);//87
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-7.0i\n", -123);//88
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3.0i\n", -12345);//89
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-6.0i\n", 0);//90
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-6.i\n", 0);//91
	fprintf(fd, "%d\n", res);

	res = ft_printf("%00.5i\n", 123);//92
	fprintf(fd, "%d\n", res);
	res = ft_printf("%07.0i\n", 123);//93
	fprintf(fd, "%d\n", res);
	res = ft_printf("%00.3i\n", 12345);//94
	fprintf(fd, "%d\n", res);
	res = ft_printf("%03.0i\n", 12345);//95
	fprintf(fd, "%d\n", res);
	res = ft_printf("%00.5i\n", -123);//96
	fprintf(fd, "%d\n", res);
	res = ft_printf("%07.0i\n", -123);//97
	fprintf(fd, "%d\n", res);
	res = ft_printf("%00.3i\n", -12345);//98
	fprintf(fd, "%d\n", res);
	res = ft_printf("%03.0i\n", -12345);//99
	fprintf(fd, "%d\n", res);
	res = ft_printf("%06.0i\n", 0);//100
	fprintf(fd, "%d\n", res);
	res = ft_printf("%06.i\n", 0);//101
	fprintf(fd, "%d\n", res);
	res = ft_printf("%00.7i\n", 0);//102
	fprintf(fd, "%d\n", res);
	res = ft_printf("%00.0i\n", 0);//103
	fprintf(fd, "%d\n", res);
	res = ft_printf("%00.i\n", 0);//104
	fprintf(fd, "%d\n", res);

	/*
	** Print extreme values
	*/
	
	res = ft_printf("%15.5i\n", 2147483647);//105
	fprintf(fd, "%d\n", res);
	res = ft_printf("%15.15i\n", 2147483647);//106
	fprintf(fd, "%d\n", res);
	res = ft_printf("%15.5i\n", -2147483647);//107
	fprintf(fd, "%d\n", res);
	res = ft_printf("%15.15i\n", -2147483647);//108
	fprintf(fd, "%d\n", res);

	res = ft_printf("%-15.5i\n", 2147483647);//109
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-15.15i\n", 2147483647);//110
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-15.5i\n", -2147483647);//111
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-15.15i\n", -2147483647);//112
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%015.5i\n", 2147483647);//113
	fprintf(fd, "%d\n", res);
	res = ft_printf("%015.15i\n", 2147483647);//114
	fprintf(fd, "%d\n", res);
	res = ft_printf("%015.5i\n", -2147483647);//115
	fprintf(fd, "%d\n", res);
	res = ft_printf("%015.15i\n", -2147483647);//116
	fprintf(fd, "%d\n", res);
	
	/*
	** Printing with extra zeros
	*/

	res = ft_printf("%i\n", 001);//117
	fprintf(fd, "%d\n", res);
	res = ft_printf("%i\n", -001);//118
	fprintf(fd, "%d\n", res);
	res = ft_printf("%15.5i\n", 001);//119
	fprintf(fd, "%d\n", res);
	res = ft_printf("%15.15i\n", -001);//120
	fprintf(fd, "%d\n", res);

	res = ft_printf("%-i\n", 001);//121
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-i\n", -001);//122
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-15.5i\n", 001);//123
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-15.15i\n", -001);//124
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%0i\n", 001);//125
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0i\n", -001);//126
	fprintf(fd, "%d\n", res);
	res = ft_printf("%015.5i\n", 001);//127
	fprintf(fd, "%d\n", res);
	res = ft_printf("%015.15i\n", -001);//128
	fprintf(fd, "%d\n", res);

	/*
	** Printing with '+'
	*/

	res = ft_printf("%i\n", +123);//129
	fprintf(fd, "%d\n", res);
	res = ft_printf("%i\n", +0);//130
	fprintf(fd, "%d\n", res);

	res = ft_printf("%-i\n", +123);//131
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-i\n", +0);//132
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%0i\n", +123);//133
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0i\n", +0);//134
	fprintf(fd, "%d\n", res);

	/*
	** Printing with * 
	*/

	res = ft_printf("%*.5i\n", 7, 123);//135
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.*i\n", 2, 123);//136
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*i\n", 4, 3, 12345);//137
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*i\n", -4, 3, 12345);//138
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*.*i\n", -4, 3, 12345);//139
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*i\n", -8, 3, 12345);//140
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*.*i\n", -8, 3, 12345);//141
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*i\n", -4, -3, 12345);//142
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*.*i\n", -4, -3, 12345);//143
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*i\n", -8, -3, 12345);//144
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*.*i\n", -8, -3, 12345);//145
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*i\n", -4, -10, 12345);//146
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*.*i\n", -4, -10, 12345);//147
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*i\n", -8, -10, 12345);//148
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*.*i\n", -8, -10, 12345);//149
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0*.*i\n", -8, -10, 12345);//150
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0*.*i\n", -8, -10, 12345);//151
	fprintf(fd, "%d\n", res);

	/*
	** Printing with text
	*/
	
	res = ft_printf("Hello i am %i years old and my length is %i cm\n", 22, 190);//152
	fprintf(fd, "%d\n", res);
	res = ft_printf("Hello i am %10i years old and my length is %10i cm\n", 22, 190);//153
	fprintf(fd, "%d\n", res);
	res = ft_printf("Hello i am %-10i years old and my length is %010i cm\n", 22, 190);//154
	fprintf(fd, "%d\n", res);
	res = ft_printf("Hello i am %.10i years old and my length is %-.15i cm\n", 22, 190);//155
	fprintf(fd, "%d\n", res);
	res = ft_printf("Hello i am %.i years old and my length is %-.i cm\n", 22, 190);//156
	fprintf(fd, "%d\n", res);
	res = ft_printf("Hello i am %-20.10i years old and my length is %-10.20i cm\n", 22, 190);//157
	fprintf(fd, "%d\n", res);
	res = ft_printf("Hello i am %20.10i years old and my length is %10.20i cm\n", 22, 190);//158
	fprintf(fd, "%d\n", res);

	return (0);
}
