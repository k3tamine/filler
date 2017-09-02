# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/23 21:22:48 by mgonon            #+#    #+#              #
#    Updated: 2017/09/02 05:27:21 by mgonon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= mgonon.filler

I_DIR	= includes
S_DIR	= srcs
O_DIR	= objs

INCS	= filler.h
FILES	= main.c \
		  parse_vm_info.c \
		  play_move.c
SRCS 	= $(addprefix $(S_DIR)/, $(FILES))
OBJS 	= $(SRCS:%.c=%.o)

FLAGS 	= -Werror -Wall -Wextra

all: $(NAME)


%.o: %.c $(I_DIR)/$(INCS)
	@echo "\033[1A\033[K\033[33;32mCompiling [$@]"
	@gcc $(FLAGS) -o $@ -c $<
	
libft: 
	make -C libft

$(NAME): $(OBJS) libft
	@echo ""
	@gcc $(FLAGS) -o $(NAME) $(OBJS) -Llibft -lft
	@echo "\033[33;32mCreating $(NAME)"
	@mv mgonon.filler resources/players/
	
	@rm -f $(OBJS)
clean:
	@make -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "\033[33;31mDeleting $(NAME)"

re: fclean all

.PHONY: re clean fclean all libft
