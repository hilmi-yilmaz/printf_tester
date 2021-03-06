/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   x_C_main.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/03 11:16:12 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/01/03 16:38:35 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{	
	FILE *fd;
	int res;

	fd = fopen("logs/results/x_C_return_val", "a+");
	if (fd == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}

	/*
	** Printing positive numbers
	*/

	res = printf("%x\n", 0x8BA);//1
	fprintf(fd, "%d\n", res);
	res = printf("%x\n", 0x99BAFF);//2
	fprintf(fd, "%d\n", res);
	res = printf("%x\n", 0x749EFCA);//3
	fprintf(fd, "%d\n", res);
	res = printf("%x\n", 0x400);//4
	fprintf(fd, "%d\n", res);
	res = printf("%x\n", 0xA40FE);//5
	fprintf(fd, "%d\n", res);
	res = printf("%x\n", 0x1234ABCD);//6
	fprintf(fd, "%d\n", res);
	res = printf("%x\n", 0x4F5E9A1C);//7
	fprintf(fd, "%d\n", res);
	res = printf("%x\n", 0x0);//8
	fprintf(fd, "%d\n", res);

	/*
	** Printing positive numbers with single parameter 
	*/

	res = printf("%7x\n", 0x8BA);//9
	fprintf(fd, "%d\n", res);
	res = printf("%1x\n", 0x8BA);//10
	fprintf(fd, "%d\n", res);
	res = printf("%3x\n", 0x8BA);//11
	fprintf(fd, "%d\n", res);
	res = printf("%.6x\n", 0x400);//12
	fprintf(fd, "%d\n", res);
	res = printf("%.2x\n", 0x400);//13
	fprintf(fd, "%d\n", res);
	res = printf("%.3x\n", 0x400);//14
	fprintf(fd, "%d\n", res);
	res = printf("%.x\n", 0x0);//15
	fprintf(fd, "%d\n", res);
	res = printf("%x\n", 0x0);//16
	fprintf(fd, "%d\n", res);
	
	res = printf("%-7x\n", 0x8BA);//17
	fprintf(fd, "%d\n", res);
	res = printf("%-1x\n", 0x8BA);//18
	fprintf(fd, "%d\n", res);
	res = printf("%-3x\n", 0x8BA);//19
	fprintf(fd, "%d\n", res);
	res = printf("%-.6x\n", 0x400);//20
	fprintf(fd, "%d\n", res);
	res = printf("%-.2x\n", 0x400);//21
	fprintf(fd, "%d\n", res);
	res = printf("%-.3x\n", 0x400);//22
	fprintf(fd, "%d\n", res);
	res = printf("%-.x\n", 0x0);//23
	fprintf(fd, "%d\n", res);
	res = printf("%-x\n", 0x0);//24
	fprintf(fd, "%d\n", res);

	res = printf("%07x\n", 0x8BA);//25
	fprintf(fd, "%d\n", res);
	res = printf("%01x\n", 0x8BA);//26
	fprintf(fd, "%d\n", res);
	res = printf("%03x\n", 0x8BA);//27
	fprintf(fd, "%d\n", res);
	res = printf("%0.6x\n", 0x400);//28
	fprintf(fd, "%d\n", res);
	res = printf("%0.2x\n", 0x400);//29
	fprintf(fd, "%d\n", res);
	res = printf("%0.3x\n", 0x400);//30
	fprintf(fd, "%d\n", res);
	res = printf("%0.x\n", 0x0);//31
	fprintf(fd, "%d\n", res);
	res = printf("%0x\n", 0x0);//32
	fprintf(fd, "%d\n", res);

	/*
	** Printing positive numbers with width and precision
	*/

	res = printf("%7.5x\n", 0x123);//33
	fprintf(fd, "%d\n", res);
	res = printf("%7.2x\n", 0x123);//34
	fprintf(fd, "%d\n", res);
	res = printf("%4.3x\n", 0x12345);//35
	fprintf(fd, "%d\n", res);
	res = printf("%3.4x\n", 0x12345);//36
	fprintf(fd, "%d\n", res);
	res = printf("%6.7x\n", 0x12345);//37
	fprintf(fd, "%d\n", res);
	res = printf("%2.7x\n", 0x12345);//38
	fprintf(fd, "%d\n", res);
	res = printf("%2.7x\n", 0x0);//39
	fprintf(fd, "%d\n", res);
	res = printf("%7.2x\n", 0x0);//40
	fprintf(fd, "%d\n", res);
	res = printf("%3.3x\n", 0x0);//41
	fprintf(fd, "%d\n", res);
	res = printf("%4.0x\n", 0x0);//42
	fprintf(fd, "%d\n", res);	
	res = printf("%4.x\n", 0x0);//43
	fprintf(fd, "%d\n", res);

	res = printf("%-7.5x\n", 0x123);//44
	fprintf(fd, "%d\n", res);
	res = printf("%-7.2x\n", 0x123);//45
	fprintf(fd, "%d\n", res);
	res = printf("%-4.3x\n", 0x12345);//46
	fprintf(fd, "%d\n", res);
	res = printf("%-3.4x\n", 0x12345);//47
	fprintf(fd, "%d\n", res);
	res = printf("%-6.7x\n", 0x12345);//48
	fprintf(fd, "%d\n", res);
	res = printf("%-2.7x\n", 0x12345);//49
	fprintf(fd, "%d\n", res);
	res = printf("%-2.7x\n", 0x0);//50
	fprintf(fd, "%d\n", res);
	res = printf("%-7.2x\n", 0x0);//51
	fprintf(fd, "%d\n", res);
	res = printf("%-3.3x\n", 0x0);//52
	fprintf(fd, "%d\n", res);
	res = printf("%-4.0x\n", 0x0);//53
	fprintf(fd, "%d\n", res);	
	res = printf("%-4.x\n", 0x0);//54
	fprintf(fd, "%d\n", res);

	res = printf("%07.5x\n", 0x123);//55
	fprintf(fd, "%d\n", res);
	res = printf("%07.2x\n", 0x123);//56
	fprintf(fd, "%d\n", res);
	res = printf("%04.3x\n", 0x12345);//57
	fprintf(fd, "%d\n", res);
	res = printf("%03.4x\n", 0x12345);//58
	fprintf(fd, "%d\n", res);
	res = printf("%06.7x\n", 0x12345);//59
	fprintf(fd, "%d\n", res);
	res = printf("%02.7x\n", 0x12345);//60
	fprintf(fd, "%d\n", res);
	res = printf("%02.7x\n", 0x0);//61
	fprintf(fd, "%d\n", res);
	res = printf("%07.2x\n", 0x0);//62
	fprintf(fd, "%d\n", res);
	res = printf("%03.3x\n", 0x0);//63
	fprintf(fd, "%d\n", res);
	res = printf("%04.0x\n", 0x0);//64
	fprintf(fd, "%d\n", res);	
	res = printf("%04.x\n", 0x0);//65
	fprintf(fd, "%d\n", res);
	
	/*
	** Printing with equal parameters
	** The parameters are: field width, precision and number length.
	*/

	res = printf("%7.7x\n", 0x1B3);//66
	fprintf(fd, "%d\n", res);
	res = printf("%2.2x\n", 0x1B3);//67
	fprintf(fd, "%d\n", res);
	res = printf("%4.3x\n", 0x1FB4);//68
	fprintf(fd, "%d\n", res);
	res = printf("%4.6x\n", 0x1FB4);//69
	fprintf(fd, "%d\n", res);
	res = printf("%3.4x\n", 0x1FB4);//70
	fprintf(fd, "%d\n", res);
	res = printf("%6.4x\n", 0x1FB4);//71
	fprintf(fd, "%d\n", res);
	res = printf("%2.2x\n", 0x12);//72
	fprintf(fd, "%d\n", res);

	res = printf("%-7.7x\n", 0x1F3);//73
	fprintf(fd, "%d\n", res);
	res = printf("%-2.2x\n", 0x1F3);//74
	fprintf(fd, "%d\n", res);
	res = printf("%-4.3x\n", 0x1AC4);//75
	fprintf(fd, "%d\n", res);
	res = printf("%-4.6x\n", 0x1AC4);//76
	fprintf(fd, "%d\n", res);
	res = printf("%-3.4x\n", 0x1AC4);//77
	fprintf(fd, "%d\n", res);
	res = printf("%-6.4x\n", 0x1AC4);//78
	fprintf(fd, "%d\n", res);
	res = printf("%-2.2x\n", 0x12);//79
	fprintf(fd, "%d\n", res);

	res = printf("%07.7x\n", 0x1CD);//80
	fprintf(fd, "%d\n", res);
	res = printf("%02.2x\n", 0x1CD);//81
	fprintf(fd, "%d\n", res);
	res = printf("%04.3x\n", 0xFFFA);//82
	fprintf(fd, "%d\n", res);
	res = printf("%04.6x\n", 0x1234);//83
	fprintf(fd, "%d\n", res);
	res = printf("%03.4x\n", 0x1234);//84
	fprintf(fd, "%d\n", res);
	res = printf("%06.4x\n", 0x1234);//85
	fprintf(fd, "%d\n", res);
	res = printf("%02.2x\n", 0x12);//86
	fprintf(fd, "%d\n", res);

	/*
	** Printing with *
	*/

	res = printf("%7.*x\n", 2, 0x123);//87
	fprintf(fd, "%d\n", res);
	res = printf("%*.2x\n", 7, 0x123);//88
	fprintf(fd, "%d\n", res);
	res = printf("%*.*x\n", 4, 3, 0x12345);//89
	fprintf(fd, "%d\n", res);
	res = printf("%7.*x\n", 0, 0x123);//90
	fprintf(fd, "%d\n", res);
	res = printf("%*.2x\n", -7, 0x123);//91
	fprintf(fd, "%d\n", res);
	res = printf("%*.*x\n", -4, -3, 0x12345);//92
	fprintf(fd, "%d\n", res);

	res = printf("%-7.*x\n", 2, 0x123);//93
	fprintf(fd, "%d\n", res);
	res = printf("%-*.2x\n", 7, 0x123);//94
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*x\n", 4, 3, 0x12345);//95
	fprintf(fd, "%d\n", res);
	res = printf("%-7.*x\n", 0, 0x123);//96
	fprintf(fd, "%d\n", res);
	res = printf("%-*.2x\n", -7, 0x123);//97
	fprintf(fd, "%d\n", res);
	res = printf("%-*.*x\n", -4, -3, 0x12345);//98
	fprintf(fd, "%d\n", res);
	
	res = printf("%07.*x\n", 2, 0x123);//99
	fprintf(fd, "%d\n", res);
	res = printf("%0*.2x\n", 7, 0x123);//100
	fprintf(fd, "%d\n", res);
	res = printf("%0*.*x\n", 4, 3, 0x12345);//101
	fprintf(fd, "%d\n", res);
	res = printf("%07.*x\n", 0, 0x123);//102
	fprintf(fd, "%d\n", res);
	res = printf("%0*.2x\n", -7, 0x123);//103
	fprintf(fd, "%d\n", res);
	res = printf("%0*.*x\n", -4, -3, 0x12345);//104
	fprintf(fd, "%d\n", res);

	/*
	** Printing with text
	*/

	res = printf("this is a hexadecimal number: %x and this is too: %x\n", 0xFA123, 0x456BD);//105
	fprintf(fd, "%d\n", res);
	res = printf("this is a hexadecimal number: %10x and this is too: %.7x\n", 0xFA123, 0x456BD);//106
	fprintf(fd, "%d\n", res);
	res = printf("this is a hexadecimal number: %2x and this is too: %.2x\n", 0xFA123, 0x456BD);//107
	fprintf(fd, "%d\n", res);
	res = printf("this is a hexadecimal number: %15.10x and this is too: %10.15x\n", 0xFA123, 0x456BD);//108
	fprintf(fd, "%d\n", res);
	res = printf("this is a hexadecimal number: %-15.10x and this is too: %010.15x\n", 0xFA123, 0x456BD);//109
	fprintf(fd, "%d\n", res);
	res = printf("this is a hexadecimal number: %015.10x and this is too: %-10.15x\n", 0xFA123, 0x456BD);//110
	fprintf(fd, "%d\n", res);
	res = printf("this is a hexadecimal number: %0*.*x and this is too: %-10.*x\n", 15, 10, 0xFA123, 15, 0x456BD);//111
	fprintf(fd, "%d\n", res);
	res = printf("this is a hexadecimal number: %15.10x and this is too: %10.15x\n", 2147483647, 0x456BD);//112
	fprintf(fd, "%d\n", res);

	return (0);
}
