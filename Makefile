# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 16:17:39 by mmanley           #+#    #+#              #
#    Updated: 2018/05/14 19:36:18 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -Wall -Wextra -Werror

LIB = libft.a

LIB_PATH = ~/libft

INC = includes

RED = \x1b[31m

GREEN = \x1b[32m

WHITE = \x1b[0m

SRCS =	main.c\
		ft_get_info.c\
		ft_init_lsts.c\

OBJS = $(SRCS:%.c=%.o)

all : $(LIB) $(NAME)

$(NAME) : $(OBJS)
	@gcc -o $@ $(OBJS) $(LIB_PATH)/$(LIB) -I $(LIB_PATH)/$(INC)
	@echo "${WHITE}Lem-in			${GREEN}DONE${WHITE}"

$(LIB) :
	@make -C $(LIB_PATH)

%.o: %.c
	@gcc -o $@ -c $< -I $(LIB_PATH)/$(INC)

clean :
	@rm $(OBJS)
	@cd $(LIB_PATH) && $(MAKE) clean
	@echo "${WHITE}Lem-in objs		${RED}DEL${WHITE}"

fclean : clean
	@cd $(LIB_PATH) && $(MAKE) fclean
	@rm $(NAME)
	@echo "${WHITE}Lem-in status		${RED}DEL${WHITE}"

re : fclean all
