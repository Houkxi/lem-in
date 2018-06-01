# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 16:17:39 by mmanley           #+#    #+#              #
#    Updated: 2018/06/01 17:02:12 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -g -Wall -Wextra -Werror

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
		files/ft_checks.c\
		files/functions.c\
		files/ft_debugs.c\
		path_finder.c\
		ft_free_stuff.c\
		finder_functions.c\

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
	./lem-in < maps/test/err_duplicate.map
	./lem-in < maps/test/err_3_coordinates.map
	./lem-in < maps/test/err_letter_in_coordinate.map
	./lem-in < maps/test/err_link_to_unknown_room.map
	./lem-in < maps/test/err_no_ants.map
	./lem-in < maps/test/err_no_ants2.map
	./lem-in < maps/test/err_no_ants3.map
	./lem-in < maps/test/err_no_ants3.map
	./lem-in < maps/test/err_no_end2.map
	./lem-in < maps/test/err_no_links.map
	./lem-in < maps/test/err_no_path.map
	./lem-in < maps/test/err_no_rooms.map
	./lem-in < maps/test/err_no_start.map
	./lem-in < maps/test/err_no_start2.map
	./lem-in < maps/test/err_start_end_same.map
	./lem-in < maps/test/err_too_few_ants.map
	./lem-in < maps/test/err_too_many_ants.map

valid: $(NAME)
	@echo "${GREEN}BASIC TEST${WHITE}"
	./lem-in < maps/valid_simple/test.map
	@echo "${GREEN}NEW COMANDS${WHITE}"
	./lem-in < maps/valid_simple/new_cd.map

mul : $(NAME)
	@echo "${GREEN}MULTIPLE TEST${WHITE}"

	valgrind --track-origins=yes --leak-check=full ./lem-in < maps/valid_simple/multiple_paths.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/1.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/10.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/10_lots_of_comments.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/2.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/20.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/5.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/9_path_depth_10_ants.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/9_path_depth_1_ants.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/9_path_depth_2_ants.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/9_path_depth_4_ants.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/9_path_depth_8_ants.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/9_path_depth_9_ants.map
	valgrind --track-origins=yes --leak-check=full 	./lem-in < maps/test/loop.map
	valgrind --track-origins=yes --leak-check=full ./lem-in < maps/test/10k.map
	./lem-in < maps/valid_simple/multiple_paths.map
	./lem-in < maps/test/1.map
	./lem-in < maps/test/10.map
	./lem-in < maps/test/10_lots_of_comments.map
	./lem-in < maps/test/2.map
	./lem-in < maps/test/20.map
	./lem-in < maps/test/5.map
	./lem-in < maps/test/9_path_depth_10_ants.map
	./lem-in < maps/test/9_path_depth_1_ants.map
	./lem-in < maps/test/9_path_depth_2_ants.map
	./lem-in < maps/test/9_path_depth_4_ants.map
	./lem-in < maps/test/9_path_depth_8_ants.map
	./lem-in < maps/test/9_path_depth_9_ants.map
	./lem-in < maps/test/loop.map
	./lem-in < maps/test/10k.map

clean :
	@rm -rf $(OBJS) objs
	@cd $(LIB_PATH) && $(MAKE) clean
	@echo "${WHITE}Lem-in objs		${RED}DEL${WHITE}"

fclean : clean
	@cd $(LIB_PATH) && $(MAKE) fclean
	@rm -f $(NAME)
	@echo "${WHITE}Lem-in status		${RED}DEL${WHITE}"

re : fclean all
