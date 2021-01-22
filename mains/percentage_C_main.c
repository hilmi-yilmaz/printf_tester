/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   percentage_C_main.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 16:02:18 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/01/22 11:39:33 by hilmi         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int i;
	FILE *fd;
	int res;

	i = 0;
	fd = fopen("logs/results/percentage_C_return_val", "a+");
	if (fd == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}

    res = printf("%%\n");//1
	fprintf(fd, "%d\n", res);
    res = printf("%1%\n");//2
	fprintf(fd, "%d\n", res);
	res = printf("%-1%\n");//3
	fprintf(fd, "%d\n", res);
	res = printf("%3%\n");//4
	fprintf(fd, "%d\n", res);
	res = printf("%-3%\n");//5
	fprintf(fd, "%d\n", res);
	res = printf("%5%\n");//6
	fprintf(fd, "%d\n", res);
	res = printf("%-5%\n");//7
	fprintf(fd, "%d\n", res);
	res = printf("%*%\n", 4);//8
	fprintf(fd, "%d\n", res);
	res = printf("%-*%\n", 4);//9
	fprintf(fd, "%d\n", res);
	res = printf("%*%\n", 0);//10
	fprintf(fd, "%d\n", res);
	res = printf("%-*%\n", 0);//11
	fprintf(fd, "%d\n", res);

    return (0);
}
