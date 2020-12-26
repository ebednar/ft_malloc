# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 16:05:16 by rwalder-          #+#    #+#              #
#    Updated: 2019/06/01 14:39:51 by rwalder-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.so

CC = @gcc
CFLAGS = -Wall -Wextra -Werror

OBJ += $(addprefix ./,\
 	ft_atoi.o \
	ft_bzero.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \
	ft_itoa.o \
	ft_lstadd.o \
	ft_lstdel.o \
	ft_lstdelone.o \
	ft_lstiter.o \
	ft_lstmap.o \
	ft_lstnew.o \
	ft_memalloc.o \
	ft_memccpy.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memcpy.o \
	ft_memdel.o \
	ft_memmove.o \
	ft_memset.o \
	ft_putchar.o \
	ft_putchar_fd.o \
	ft_putendl.o \
	ft_putendl_fd.o \
	ft_putnbr.o \
	ft_putnbr_fd.o \
	ft_putstr.o \
	ft_putstr_fd.o \
	ft_strcat.o \
	ft_strchr.o \
	ft_strclr.o \
	ft_strcmp.o \
	ft_strcpy.o \
	ft_strdel.o \
	ft_strdup.o \
	ft_strequ.o \
	ft_striter.o \
	ft_striteri.o \
	ft_strjoin.o \
	ft_strlcat.o \
	ft_strlen.o \
	ft_strmap.o \
	ft_strmapi.o \
	ft_strncat.o \
	ft_strncmp.o \
	ft_strncpy.o \
	ft_strnequ.o \
	ft_strnew.o \
	ft_strnstr.o \
	ft_strrchr.o \
	ft_strsplit.o \
	ft_strstr.o \
	ft_strsub.o \
	ft_strtrim.o \
	ft_tolower.o \
	ft_toupper.o \
)


all: $(NAME)

$(NAME): $(OBJ)
	@gcc -shared -fPIC -o $(NAME) $(OBJ)
	@echo "\033[0;32mFile $@ was successfully created.\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -I../include -c -o $@ $<
	@echo "\033[1;34mCompiling ($(CFLAGS)) \033[0;36m$<\033[0m"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
