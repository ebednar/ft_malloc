# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 20:03:31 by rwalder-          #+#    #+#              #
#    Updated: 2019/10/22 20:03:40 by rwalder-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE), )
	HOSTTYPE :=  $(shell uname -m)_$(shell uname -s)
endif

SRCDIR = src
OBJDIR = obj

MALLOC_NAME = libft_malloc_$(HOSTTYPE).so
SYMLINK_NAME = libft_malloc.so
NAME = main
SRCS = $(SRCDIR)/allocated_manager.c $(SRCDIR)/configs.c $(SRCDIR)/ft_free.c\
		$(SRCDIR)/ft_malloc.c $(SRCDIR)/ft_realloc.c $(SRCDIR)/prints.c\
		$(SRCDIR)/show_alloc_mem.c $(SRCDIR)/show_alloc_mem_ex.c

OBJS = $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.c=.o))
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

main: $(OBJS)
	@make -C libft/
	@gcc $(FLAGS) $(OBJS) -shared -fPIC -Llibft -lft -I ./include -o $(MALLOC_NAME)
	@ln -sfF $(MALLOC_NAME) $(SYMLINK_NAME)
	@ln -sfF libft/libft.so libft.so
	@echo "\033[1;32mSources compiled\033[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@gcc $(FLAGS) -I ./include -fPIC -c $< -o $@
	@echo "\033[1;34m" $< " -> " $@ "\033[0;36m$<\033[0m"

clean:
	@make -C libft/ clean
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
	@echo "\033[1;32mCleaned\033[0;36m$<\033[0m"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(MALLOC_NAME)
	@rm -f $(SYMLINK_NAME)
	@rm -f libft.so
	@echo "\033[1;32mDeleted binary\033[0m"

re: fclean all

.PHONY: all clean fclean re main
