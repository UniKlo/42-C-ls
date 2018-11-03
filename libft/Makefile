#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 18:08:35 by khou              #+#    #+#              #
#    Updated: 2018/11/03 15:14:46 by khou             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C = clang

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

DIR_INC = include/

DIR_L = libft_basic/

DIR_S = printf_srcs/

HEADER = printf.h libft_basic.h

LIBFT = ft_atoi.c		ft_bzero.c		ft_count_nbr_block.c	ft_isalnum.c\
		ft_isalpha.c 	ft_isascii.c 	ft_isdigit.c 			ft_islower.c\
		ft_isprint.c	ft_isspace.c	ft_isupper.c			ft_itoa.c\
		ft_lstadd.c		ft_lstdel.c		ft_lstdelone.c			ft_lstiter.c\
		ft_lstmap.c		ft_lstnew.c		ft_memalloc.c			ft_memccpy.c\
		ft_memchr.c		ft_memcmp.c		ft_memcpy.c				ft_memdel.c\
		ft_memmove.c	ft_memset.c		ft_putchar.c			ft_putchar_fd.c\
		pt_putnbr.c		pt_putnbr_fd.c	pt_putstr.c				pt_putstr_fd.c\
        ft_putnbr.c     ft_putnbr_fd.c  ft_putstr.c             ft_putstr_fd.c\
		ft_strcat.c		ft_strchr.c		ft_strclr.c				ft_strcmp.c\
		ft_strcpy.c		ft_strdel.c		ft_strdup.c				ft_strequ.c\
		ft_striter.c	ft_striteri.c	ft_strjoin.c			ft_strlcat.c\
		ft_strlen.c		ft_lstrlen.c	ft_strmap.c				ft_strmapi.c\
		ft_strncat.c	ft_strncmp.c	ft_strncpy.c			ft_strnequ.c\
		ft_strnew.c		ft_strnstr.c	ft_strrchr.c			ft_strsplit.c\
		ft_strstr.c		ft_strsub.c		ft_strtrim.c			ft_tolower.c\
		ft_toupper.c	ft_nbrlen.c

SOURCES =	 printf.c		fmt_dispatch.c			grab_fmt.c\
			 p_diuox.c		p_s.c			p_c.c\
			 undef.c 		get_lengh.c

SRCS = $(addprefix $(DIR_L), $(LIBFT)) $(addprefix $(DIR_S), $(SOURCES)) 

OBJS = $(SRCS:.c=.o)

INC = $(addprefix $(DIR_INC), $(HEADER))


all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

./%.o: ./%.c $(INC)
	@$(C) $(FLAGS) -I $(DIR_INC) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "libft cleaned up objects"

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f \#*\#
	@rm -f $(DIR_S)/*~
	@rm -f $(DIR_S)/\#*\#
	@rm -f a.out
	@rm -rf *dSYM
	@echo "libft reset"

re: fclean all

.PHONY: fclean re norme all clean
