/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/18 14:14:29 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/01/06 15:07:36 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_info
{
	int				dash;
	int				zero;
	int				prec;
	int				width;
	int				err;
	int				return_val;
	char			spec;

}					t_info;

/*
** The ft_printf function itself.
*/

int					ft_printf(const char *fmt, ...);

/*
** These functions parse the information in the specifier and saves it in a
** struct.
** The exceptions function handles some exceptions.
*/

int					set_info(const char *str_conv, t_info *info, va_list ap);
int					set_flags(const char *str_conv, t_info *info);
int					set_width(const char *str_conv, t_info *info, va_list ap);
int					set_prec(const char *str_conv, t_info *info, va_list ap);
int					set_spec(const char *str_conv, t_info *info);
void				exceptions(t_info *info);

/*
** The conversion function calls {d,u,s,x,p}_convert to print the values.
*/

void				conversion(va_list ap, t_info *info);

/*
** These functions handle the {d, u}-conversion.
*/

void				d_convert(va_list ap, t_info *info);
void				u_convert(va_list ap, t_info *info);
char				*create_array(int nb, t_info *info, int len_nb);
void				fill_zeros(char *str, t_info *info, int nb, int base);
void				fill_nb(char *str, char *str_nb, t_info *info, int nb);

/*
** These functions handle the x-conversion.
*/

void				x_convert(va_list ap, t_info *info);
char				*create_array_x(t_info *info, int nb, int len_nb);
void				fill_zeros_x(char *str, t_info *info);

/*
** These functions handle the c-conversion.
*/

void				c_convert(va_list ap, t_info *info);
char				*create_array_c(t_info *info);
void				exception_zero(unsigned char c, t_info *info);


/*
** These functions handle the s-conversion
*/

void				s_convert(va_list ap, t_info *info);
char				*create_array_s(const char *str, t_info *info, int is_null);
void				fill_str(char *str_malloc, const char *str, t_info *info, int is_null);

/*
** These functions handle the p-conversion.
*/

void				p_convert(va_list ap, t_info *info);
char				*create_array_p(char *str_nb, t_info *info);
void				fill_addr(char *str, char *str_nb, t_info *info);

/*
** Here are some utils functions.
*/

int					ft_nblen(int nb, int base);
int					max_number(int a, int b);
int					ft_abs(int a);
int					ft_strchr1(char *s, int c);
int					ft_cntchr(char *str, int c);

#endif
