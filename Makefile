# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 16:17:39 by mmanley           #+#    #+#              #
#    Updated: 2018/05/29 11:37:55 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -Wall -Wextra -Werror

LIB = libftprintf.a

LIB_PATH = ./printf

INC = printf

FSAN = -fsanitize=address -g3

RED = \x1b[31m

GREEN = \x1b[32m

WHITE = \x1b[0m

OBJ_PATH = objs/

SRCS =	main.c\
		pars/ft_get_info.c\
		pars/ft_init_lsts.c\
		pars/ft_get_links.c\
		pars/ft_ants_check.c\
		pars/ft_coment_checks.c\
		files/ft_checks.c\
		files/functions.c\
		files/ft_debugs.c\
		path_finder.c\

OBJS_BASE = $(SRCS:%.c=%.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJS_BASE))

all : $(LIB) $(NAME)

$(NAME) : objs $(OBJS)
	@gcc -o $@ $(OBJS) $(LIB_PATH)/$(LIB) -I $(LIB_PATH)/ -I ./ $(CFLAGS)
	@echo "${WHITE}Lem-in			${GREEN}DONE${WHITE}"

$(LIB) :
	@make -C $(LIB_PATH)

objs :
	@mkdir -p objs
	@mkdir -p objs/files
	@mkdir -p objs/pars

$(OBJ_PATH)%.o: %.c
	@gcc -o $@ -c $< -I $(LIB_PATH)/$(INC) -I ./

errors: $(NAME)
	@echo "${RED}NO COMANDS${WHITE}"
	./lem-in < maps/errors/no_cmds.map
	@echo "${RED}WRONG ROOM NAME${WHITE}"
	./lem-in < maps/errors/l_room_name.map
	@echo "${RED}WRONG ROOM PLACEMENT${WHITE}"
	./lem-in < maps/errors/new_room_after_links.map
	@echo "${RED}NO ANTS${WHITE}"
	./lem-in < maps/errors/no_ants.map

valid: $(NAME)
	@echo "${GREEN}BASIC TEST${WHITE}"
	./lem-in < maps/valid_simple/test.map
	@echo "${GREEN}NEW COMANDS${WHITE}"
	./lem-in < maps/valid_simple/new_cd.map

mul : $(NAME)
	@echo "${GREEN}MULTIPLE TEST${WHITE}"
	./lem-in < maps/valid_simple/multiple_paths.map

clean :
	@rm -rf $(OBJS) objs
	@cd $(LIB_PATH) && $(MAKE) clean
	@echo "${WHITE}Lem-in objs		${RED}DEL${WHITE}"

fclean : clean
	@cd $(LIB_PATH) && $(MAKE) fclean
	@rm -f $(NAME)
	@echo "${WHITE}Lem-in status		${RED}DEL${WHITE}"

re : fclean all
