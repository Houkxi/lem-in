# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 18:54:36 by mmanley           #+#    #+#              #
#    Updated: 2018/01/08 09:36:59 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libstr.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = ../includes/

STR =	ft_count_btw.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strdel.c\
		ft_strmap.c\
		ft_strclr.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strtrim.c\
		ft_strmapi.c\
		ft_striter.c\
		ft_striteri.c\
		ft_tabcpy.c\

OBJS = $(STR:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -c $(FLAGS) $(STR) -I $(INC)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
