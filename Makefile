#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 18:08:35 by khou              #+#    #+#              #
#    Updated: 2018/10/29 18:21:09 by khou             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C = clang

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror -fsanitize=address #-g

DIR_S = srcs

DIR_O = obj

HEADER = -I include

SOURCES = main.c \
		operate.c\
		plong.c\
		f_or_d.c\

SRCS = $(addprefix $(DIR_S)/, $(SOURCES))

all: $(NAME)

$(NAME): $(SRCS)
	@make -C libft/
	@$(C) libft/libft.a $(HEADER) $(FLAGS) $(SRCS) -o $(NAME)

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

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
