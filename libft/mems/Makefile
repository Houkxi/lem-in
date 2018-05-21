# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 18:54:36 by mmanley           #+#    #+#              #
#    Updated: 2018/01/08 09:37:13 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmem.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = ../includes/

MEM =	ft_deltab.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c \
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c \
		ft_newtab.c\
		ft_strdup.c\
		ft_strnew.c\
		ft_strjoin.c\
		ft_strsub.c\
		ft_strsplit.c\


OBJS = $(MEM:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -c $(FLAGS) $(MEM) -I $(INC)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
