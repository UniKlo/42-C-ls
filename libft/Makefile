#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/13 13:40:17 by khou              #+#    #+#              #
#    Updated: 2018/08/29 13:32:42 by khou             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CFLAG = -g -Wall -Werror -Wextra -c
SRC = $(wildcard *.c)
OFILES = *.o

all: $(NAME)

$(NAME): $(SRC)
		@gcc $(CFLAG) $(SRC)
		@ar rc $(NAME) $(OFILES)

clean:
		@/bin/rm -f $(OFILES)

fclean: clean
		@/bin/rm -f $(NAME)
		@/bin/rm -f *~
		@/bin/rm -f \#*\#

re: fclean all

.PHONY: clean fclean all re

