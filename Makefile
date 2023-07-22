# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 20:01:30 by nzhuzhle          #+#    #+#              #
#    Updated: 2023/07/22 20:32:33 by nzhuzhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -I ./

SRC = ft_check_parse.c ft_sort.c ft_lists.c ft_utils.c \
	  ft_moves.c ft_budget.c ft_engine.c
OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

%.o: %.c Makefile
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
