/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   u_ft_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 13:35:58 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/03/11 10:32:26 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

int	ft_printf(const char *fmt, ...);

int		main(void)
{
	FILE *fd;
	int res;

	fd = fopen("logs/results/u_ft_return_val", "a+");
	if (fd == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}

	/*
	** Printing positive numbers
	*/
	
	res = ft_printf("%u\n", (unsigned int)999);//1
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7u\n", (unsigned int)999);//2
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.7u\n", (unsigned int)12345);//3
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.u\n", (unsigned int)12345);//4
	fprintf(fd, "%d\n", res);
	res = ft_printf("%010.u\n", (unsigned int)12345);//5
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.7u\n", (unsigned int)12345);//6
	fprintf(fd, "%d\n", res);

	res = ft_printf("%7.5u\n", (unsigned int)123);//7
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.2u\n", (unsigned int)123);//8
	fprintf(fd, "%d\n", res);
	res = ft_printf("%4.3u\n", (unsigned int)12345);//9
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.4u\n", (unsigned int)12345);//10
	fprintf(fd, "%d\n", res);
	res = ft_printf("%6.7u\n", (unsigned int)12345);//11
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.7u\n", (unsigned int)12345);//12
	fprintf(fd, "%d\n", res);

	res = ft_printf("%-7.5u\n", (unsigned int)123);//13
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-7.2u\n", (unsigned int)123);//14
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-4.3u\n", (unsigned int)12345);//15
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3.4u\n", (unsigned int)12345);//16
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-6.7u\n", (unsigned int)12345);//17
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.7u\n", (unsigned int)12345);//18
	fprintf(fd, "%d\n", res);

	res = ft_printf("%07.5u\n", (unsigned int)123);//19
	fprintf(fd, "%d\n", res);
	res = ft_printf("%07.2u\n", (unsigned int)123);//20
	fprintf(fd, "%d\n", res);
	res = ft_printf("%04.3u\n", (unsigned int)12345);//21
	fprintf(fd, "%d\n", res);
	res = ft_printf("%03.4u\n", (unsigned int)12345);//22
	fprintf(fd, "%d\n", res);
	res = ft_printf("%06.7u\n", (unsigned int)12345);//23
	fprintf(fd, "%d\n", res);
	res = ft_printf("%02.7u\n", (unsigned int)12345);//24
	fprintf(fd, "%d\n", res);

	/*
	** Print extreme values
	*/
	
	res = ft_printf("%15.5u\n", (unsigned int)3147483647);//25
	fprintf(fd, "%d\n", res);
	res = ft_printf("%15.15u\n", (unsigned int)3147483647);//26
	fprintf(fd, "%d\n", res);

	res = ft_printf("%-15.5u\n", (unsigned int)3147483647);//27
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-15.15u\n", (unsigned int)3147483647);//28
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%015.5u\n", (unsigned int)4294967295);//29
	fprintf(fd, "%d\n", res);
	res = ft_printf("%015.15u\n", (unsigned int)4294967295);//30
	fprintf(fd, "%d\n", res);

	return (0);
}
