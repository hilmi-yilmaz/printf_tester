/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   id_C_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 18:36:08 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/30 20:58:42 by hyilmaz       ########   odam.nl         */
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
	** Printing positive numbers
	*/
	
	res = printf("%d\n", 999);//1
	fprintf(fd, "%d\n", res);
	res = printf("%7d\n", 999);//2
	fprintf(fd, "%d\n", res);
	res = printf("%.7d\n", 12345);//3
	fprintf(fd, "%d\n", res);
	res = printf("%.d\n", 12345);//4
	fprintf(fd, "%d\n", res);
	res = printf("%010.d\n", 12345);//5
	fprintf(fd, "%d\n", res);
	res = printf("%0.7d\n", 12345);//6
	fprintf(fd, "%d\n", res);

	res = printf("%7.5d\n", 123);//7
	fprintf(fd, "%d\n", res);
	res = printf("%7.2d\n", 123);//8
	fprintf(fd, "%d\n", res);
	res = printf("%4.3d\n", 12345);//9
	fprintf(fd, "%d\n", res);
	res = printf("%3.4d\n", 12345);//10
	fprintf(fd, "%d\n", res);
	res = printf("%6.7d\n", 12345);//11
	fprintf(fd, "%d\n", res);
	res = printf("%2.7d\n", 12345);//12
	fprintf(fd, "%d\n", res);

	res = printf("%-7.5d\n", 123);//13
	fprintf(fd, "%d\n", res);
	res = printf("%-7.2d\n", 123);//14
	fprintf(fd, "%d\n", res);
	res = printf("%-4.3d\n", 12345);//15
	fprintf(fd, "%d\n", res);
	res = printf("%-3.4d\n", 12345);//16
	fprintf(fd, "%d\n", res);
	res = printf("%-6.7d\n", 12345);//17
	fprintf(fd, "%d\n", res);
	res = printf("%-2.7d\n", 12345);//18
	fprintf(fd, "%d\n", res);

	res = printf("%07.5d\n", 123);//19
	fprintf(fd, "%d\n", res);
	res = printf("%07.2d\n", 123);//20
	fprintf(fd, "%d\n", res);
	res = printf("%04.3d\n", 12345);//21
	fprintf(fd, "%d\n", res);
	res = printf("%03.4d\n", 12345);//22
	fprintf(fd, "%d\n", res);
	res = printf("%06.7d\n", 12345);//23
	fprintf(fd, "%d\n", res);
	res = printf("%02.7d\n", 12345);//24
	fprintf(fd, "%d\n", res);

	/*
	** Printing negative numbers
	*/

	res = printf("%7.5d\n", -123);//25
	fprintf(fd, "%d\n", res);
	res = printf("%7.2d\n", -123);//26
	fprintf(fd, "%d\n", res);
	res = printf("%4.3d\n", -12345);//27
	fprintf(fd, "%d\n", res);
	res = printf("%3.4d\n", -12345);//28
	fprintf(fd, "%d\n", res);
	res = printf("%7.9d\n", -12345);//29
	fprintf(fd, "%d\n", res);
	res = printf("%2.9d\n", -12345);//30
	fprintf(fd, "%d\n", res);

	res = printf("%-7.5d\n", -123);//31
	fprintf(fd, "%d\n", res);
	res = printf("%-7.2d\n", -123);//32
	fprintf(fd, "%d\n", res);
	res = printf("%-4.3d\n", -12345);//33
	fprintf(fd, "%d\n", res);
	res = printf("%-3.4d\n", -12345);//34
	fprintf(fd, "%d\n", res);
	res = printf("%-7.9d\n", -12345);//35
	fprintf(fd, "%d\n", res);
	res = printf("%-2.9d\n", -12345);//36
	fprintf(fd, "%d\n", res);
	
	res = printf("%07.5d\n", -123);//37
	fprintf(fd, "%d\n", res);
	res = printf("%07.2d\n", -123);//38
	fprintf(fd, "%d\n", res);
	res = printf("%04.3d\n", -12345);//39
	fprintf(fd, "%d\n", res);
	res = printf("%03.4d\n", -12345);//40
	fprintf(fd, "%d\n", res);
	res = printf("%07.9d\n", -12345);//41
	fprintf(fd, "%d\n", res);
	res = printf("%02.9d\n", -12345);//42
	fprintf(fd, "%d\n", res);

	/*
	** Printing with equal parameters with dash = 0
	** The parameters are: field width, precision and number length.
	** The number length includes the '-' sign. 
	** Thus -123 has length 4.
	*/
	
	res = printf("%7.7d\n", 123);//43
	fprintf(fd, "%d\n", res);
	res = printf("%2.2d\n", 123);//44
	fprintf(fd, "%d\n", res);
	res = printf("%4.3d\n", 1234);//45
	fprintf(fd, "%d\n", res);
	res = printf("%3.4d\n", 1234);//46
	fprintf(fd, "%d\n", res);
	res = printf("%2.2d\n", 12);//47
	fprintf(fd, "%d\n", res);

	res = printf("%7.7d\n", -123);//48
	fprintf(fd, "%d\n", res);
	res = printf("%2.2d\n", -123);//49
	fprintf(fd, "%d\n", res);
	res = printf("%5.3d\n", -1234);//50
	fprintf(fd, "%d\n", res);
	res = printf("%3.5d\n", -1234);//51
	fprintf(fd, "%d\n", res);
	res = printf("%3.3d\n", -12);//52
	fprintf(fd, "%d\n", res);
	
	res = printf("%-7.7d\n", 123);//53
	fprintf(fd, "%d\n", res);
	res = printf("%-2.2d\n", 123);//54
	fprintf(fd, "%d\n", res);
	res = printf("%-4.3d\n", 1234);//55
	fprintf(fd, "%d\n", res);
	res = printf("%-3.4d\n", 1234);//56
	fprintf(fd, "%d\n", res);
	res = printf("%-2.2d\n", 12);//57
	fprintf(fd, "%d\n", res);

	res = printf("%-7.7d\n", -123);//58
	fprintf(fd, "%d\n", res);
	res = printf("%-2.2d\n", -123);//59
	fprintf(fd, "%d\n", res);
	res = printf("%-5.3d\n", -1234);//60
	fprintf(fd, "%d\n", res);
	res = printf("%-3.5d\n", -1234);//61
	fprintf(fd, "%d\n", res);
	res = printf("%-3.3d\n", -12);//62
	fprintf(fd, "%d\n", res);

	res = printf("%07.7d\n", 123);//63
	fprintf(fd, "%d\n", res);
	res = printf("%02.2d\n", 123);//64
	fprintf(fd, "%d\n", res);
	res = printf("%04.3d\n", 1234);//65
	fprintf(fd, "%d\n", res);
	res = printf("%03.4d\n", 1234);//66
	fprintf(fd, "%d\n", res);
	res = printf("%02.2d\n", 12);//67
	fprintf(fd, "%d\n", res);

	res = printf("%07.7d\n", -123);//68
	fprintf(fd, "%d\n", res);
	res = printf("%02.2d\n", -123);//69
	fprintf(fd, "%d\n", res);
	res = printf("%05.3d\n", -1234);//70
	fprintf(fd, "%d\n", res);
	res = printf("%03.5d\n", -1234);//71
	fprintf(fd, "%d\n", res);
	res = printf("%03.3d\n", -12);//72
	fprintf(fd, "%d\n", res);

	/*
	** Printing with 0 parameters
	*/

	res = printf("%0.5d\n", 123);//73
	fprintf(fd, "%d\n", res);
	res = printf("%7.0d\n", 123);//74
	fprintf(fd, "%d\n", res);
	res = printf("%0.3d\n", 12345);//75
	fprintf(fd, "%d\n", res);
	res = printf("%3.0d\n", 12345);//76
	fprintf(fd, "%d\n", res);
	res = printf("%0.5d\n", -123);//77
	fprintf(fd, "%d\n", res);
	res = printf("%7.0d\n", -123);//78
	fprintf(fd, "%d\n", res);
	res = printf("%0.3d\n", -12345);//79
	fprintf(fd, "%d\n", res);
	res = printf("%3.0d\n", -12345);//80
	fprintf(fd, "%d\n", res);
	res = printf("%6.0d\n", 0);//81
	fprintf(fd, "%d\n", res);
	res = printf("%6.d\n", 0);//82
	fprintf(fd, "%d\n", res);
	res = printf("%0.7d\n", 0);//83
	fprintf(fd, "%d\n", res);
	res = printf("%0.0d\n", 0);//84
	fprintf(fd, "%d\n", res);
	res = printf("%0.d\n", 0);//85
	fprintf(fd, "%d\n", res);

	res = printf("%-7.0d\n", 123);//86
	fprintf(fd, "%d\n", res);
	res = printf("%-3.0d\n", 12345);//87
	fprintf(fd, "%d\n", res);
	res = printf("%-7.0d\n", -123);//88
	fprintf(fd, "%d\n", res);
	res = printf("%-3.0d\n", -12345);//89
	fprintf(fd, "%d\n", res);
	res = printf("%-6.0d\n", 0);//90
	fprintf(fd, "%d\n", res);
	res = printf("%-6.d\n", 0);//91
	fprintf(fd, "%d\n", res);

	res = printf("%00.5d\n", 123);//92
	fprintf(fd, "%d\n", res);
	res = printf("%07.0d\n", 123);//93
	fprintf(fd, "%d\n", res);
	res = printf("%00.3d\n", 12345);//94
	fprintf(fd, "%d\n", res);
	res = printf("%03.0d\n", 12345);//95
	fprintf(fd, "%d\n", res);
	res = printf("%00.5d\n", -123);//96
	fprintf(fd, "%d\n", res);
	res = printf("%07.0d\n", -123);//97
	fprintf(fd, "%d\n", res);
	res = printf("%00.3d\n", -12345);//98
	fprintf(fd, "%d\n", res);
	res = printf("%03.0d\n", -12345);//99
	fprintf(fd, "%d\n", res);
	res = printf("%06.0d\n", 0);//100
	fprintf(fd, "%d\n", res);
	res = printf("%06.d\n", 0);//101
	fprintf(fd, "%d\n", res);
	res = printf("%00.7d\n", 0);//102
	fprintf(fd, "%d\n", res);
	res = printf("%00.0d\n", 0);//103
	fprintf(fd, "%d\n", res);
	res = printf("%00.d\n", 0);//104
	fprintf(fd, "%d\n", res);

	/*
	** Print extreme values
	*/
	
	res = printf("%15.5d\n", 2147483647);//105
	fprintf(fd, "%d\n", res);
	res = printf("%15.15d\n", 2147483647);//106
	fprintf(fd, "%d\n", res);
	res = printf("%15.5d\n", -2147483647);//107
	fprintf(fd, "%d\n", res);
	res = printf("%15.15d\n", -2147483647);//108
	fprintf(fd, "%d\n", res);

	res = printf("%-15.5d\n", 2147483647);//109
	fprintf(fd, "%d\n", res);
	res = printf("%-15.15d\n", 2147483647);//110
	fprintf(fd, "%d\n", res);
	res = printf("%-15.5d\n", -2147483647);//111
	fprintf(fd, "%d\n", res);
	res = printf("%-15.15d\n", -2147483647);//112
	fprintf(fd, "%d\n", res);
	
	res = printf("%015.5d\n", 2147483647);//113
	fprintf(fd, "%d\n", res);
	res = printf("%015.15d\n", 2147483647);//114
	fprintf(fd, "%d\n", res);
	res = printf("%015.5d\n", -2147483647);//115
	fprintf(fd, "%d\n", res);
	res = printf("%015.15d\n", -2147483647);//116
	fprintf(fd, "%d\n", res);
	
	/*
	** Printing with extra zeros
	*/

	res = printf("%d\n", 001);//117
	fprintf(fd, "%d\n", res);
	res = printf("%d\n", -001);//118
	fprintf(fd, "%d\n", res);
	res = printf("%15.5d\n", 001);//119
	fprintf(fd, "%d\n", res);
	res = printf("%15.15d\n", -001);//120
	fprintf(fd, "%d\n", res);

	res = printf("%-d\n", 001);//121
	fprintf(fd, "%d\n", res);
	res = printf("%-d\n", -001);//122
	fprintf(fd, "%d\n", res);
	res = printf("%-15.5d\n", 001);//123
	fprintf(fd, "%d\n", res);
	res = printf("%-15.15d\n", -001);//124
	fprintf(fd, "%d\n", res);
	
	res = printf("%0d\n", 001);//125
	fprintf(fd, "%d\n", res);
	res = printf("%0d\n", -001);//126
	fprintf(fd, "%d\n", res);
	res = printf("%015.5d\n", 001);//127
	fprintf(fd, "%d\n", res);
	res = printf("%015.15d\n", -001);//128
	fprintf(fd, "%d\n", res);

	/*
	** Printing with '+'
	*/

	res = printf("%d\n", +123);//129
	fprintf(fd, "%d\n", res);
	res = printf("%d\n", +0);//130
	fprintf(fd, "%d\n", res);

	res = printf("%-d\n", +123);//131
	fprintf(fd, "%d\n", res);
	res = printf("%-d\n", +0);//132
	fprintf(fd, "%d\n", res);
	
	res = printf("%0d\n", +123);//133
	fprintf(fd, "%d\n", res);
	res = printf("%0d\n", +0);//134
	fprintf(fd, "%d\n", res);

	/*
	** Printing with * 
	*/

	res = printf("%*.5d\n", 7, 123);//135
	fprintf(fd, "%d\n", res);
	res = printf("%7.*d\n", 2, 123);//136
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d\n", 4, 3, 12345);//137
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d\n", -4, 3, 12345);//138
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*d\n", -4, 3, 12345);//139
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d\n", -8, 3, 12345);//140
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*d\n", -8, 3, 12345);//141
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d\n", -4, -3, 12345);//142
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*d\n", -4, -3, 12345);//143
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d\n", -8, -3, 12345);//144
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*d\n", -8, -3, 12345);//145
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d\n", -4, -10, 12345);//146
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*d\n", -4, -10, 12345);//147
	fprintf(fd, "%d\n", res);
	res = printf("%*.*d\n", -8, -10, 12345);//148
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*d\n", -8, -10, 12345);//149
	fprintf(fd, "%d\n", res);
	res = printf("%0*.*d\n", -8, -10, 12345);//150
	fprintf(fd, "%d\n", res);
	res = printf("%0*.*d\n", -8, -10, 12345);//151
	fprintf(fd, "%d\n", res);

	return (0);
}
