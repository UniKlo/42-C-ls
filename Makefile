#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 18:08:35 by khou              #+#    #+#              #
#    Updated: 2018/11/09 03:23:00 by khou             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C = clang

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror #-fsanitize=address #-g

DIR_S = srcs

DIR_O = obj

HEADER = -I include

SOURCES = main.c \
		ls_init.c\
		plong.c\
		cmd_arg.c\
		btree_sort.c\
		open_dir.c\
		sub_sort.c\
		free.c\


SRCS = $(addprefix $(DIR_S)/, $(SOURCES))

all: $(NAME)

$(NAME): $(SRCS)
	@make -C libft/
	@$(C) libft/libft.a $(HEADER) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

clean:
	@make clean -C libft
	@echo "cleaned up objects"

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f \#*\#
	@rm -f include/*~
	@rm -f include/\#*\#
	@rm -f srcs/*~
	@rm -f srcs/\#*\#
	@rm -f srcs/.#*
	@rm -f a.out
	@rm -rf *dSYM
	@make fclean -C libft
	@echo "reset"

re: fclean all

.PHONY: fclean re norme all clean
