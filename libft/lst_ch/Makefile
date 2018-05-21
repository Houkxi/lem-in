# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 18:54:36 by mmanley           #+#    #+#              #
#    Updated: 2018/01/05 18:58:35 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = liblt.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = ../includes/

LST =	ft_lst_print.c\
		ft_lstadd_end.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstmapi.c\
		ft_lstnew.c\

OBJS = $(LST:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -c $(FLAGS) $(LST) -I $(INC)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
