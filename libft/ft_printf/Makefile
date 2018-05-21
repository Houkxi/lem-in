# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 16:56:10 by mmanley           #+#    #+#              #
#    Updated: 2018/05/12 12:53:23 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -I.

OBJ_PATH = objs/

INC = ../includes

RED = \x1b[31m

GREEN = \x1b[32m

WHITE = \x1b[0m

SRCS =	srcs/chr_manager.c\
		srcs/flag_power.c\
		srcs/flags_pmss.c\
		srcs/ft_itoall.c\
		srcs/ft_printf.c\
		srcs/info_pars.c\
		srcs/nbr_manager.c\
		srcs/pars_check.c\
		srcs/buff_renderer.c\
		srcs/flags_chr.c\
		srcs/wchar_conv.c\
		srcs/bonus_part.c\
		srcs/bonus_binairy.c\

OBJS_NAME = $(SRCS:%.c=%.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJS_NAME))

all : $(NAME) info

$(OBJ_PATH) :
	@mkdir -p objs
	@mkdir -p objs/srcs

$(OBJS): |$(OBJ_PATH)

$(NAME) : $(OBJS)
	@ar rc libftprintf.a $(OBJS)
	@ranlib libftprintf.a

$(OBJ_PATH)%.o: %.c
	@$(CC) $(FLAGS) -o $@ -I $(INC) -c $<

info :
	@echo "${WHITE}libftprintf.a${GREEN}		DONE"

clean :
	@rm -rf objs

fclean : clean
	@rm -rf $(NAME)

re : fclean all
