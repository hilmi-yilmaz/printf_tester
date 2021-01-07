# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hyilmaz <hyilmaz@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/19 10:51:42 by hyilmaz       #+#    #+#                  #
#    Updated: 2020/12/27 17:38:19 by hyilmaz       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
LIBFT=libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	ft_printf.c \
		set_info.c \
		exceptions.c \
		conversion.c \
		d_convert.c \
		u_convert.c \
		x_convert.c \
		c_convert.c \
		s_convert.c \
		p_convert.c \
		utils.c

OBJ := $(SRC:.c=.o)
HEADER_FILE = ft_printf.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $< $@
	ar -rc $@ $(OBJ)

%.o: %.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -c $<

$(LIBFT):
	make bonus -C libft

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
