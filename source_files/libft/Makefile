# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hyilmaz <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/17 12:51:19 by hyilmaz       #+#    #+#                  #
#    Updated: 2020/12/26 20:08:51 by hyilmaz       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER_FILE = libft.h
SOURCE =	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

BONUS_SOURCE = ft_lstnew.c \
			   ft_lstadd_front.c \
			   ft_lstsize.c \
			   ft_lstlast.c \
			   ft_lstadd_back.c \
			   ft_lstdelone.c \
			   ft_lstclear.c \
			   ft_lstiter.c \
			   ft_lstmap.c \
			   ft_itoa_hex_bonus.c \
			   ft_toupper_str_bonus.c \
			   ft_ultoa_hex_bonus.c

REG_OBJECT = $(SOURCE:.c=.o)

BONUS_OBJECT = $(BONUS_SOURCE:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJ_FILES = $(REG_OBJECT) $(BONUS_OBJECT)
else
OBJ_FILES = $(REG_OBJECT)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar cr $@ $^

bonus:
	$(MAKE) WITH_BONUS=1 all

%.o: %.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(REG_OBJECT) $(BONUS_OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
