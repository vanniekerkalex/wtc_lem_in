# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 11:40:00 by avan-ni           #+#    #+#              #
#    Updated: 2018/08/14 13:52:07 by avan-ni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM = lem-in

FLAGS = -Wall -Werror -Wextra

SRCS = *.c

OBJS = *.o

HEADERS = -I libft/includes -I includes/

LIB = libft/libft.a

$(LEM) :
	@make fclean -C libft/
	@make -C libft/
	@make clean -C libft/
	gcc $(FLAGS) -c $(SRCS) $(HEADERS)
	gcc $(FLAGS) $(OBJS) -o $(LEM) $(LIB)
	@make clean
	@echo "\x1B[33mLEM_IN compiled\x1B[0m"

all : $(LEM)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@make fclean -C libft/
	@rm -rf $(LEM)
	@echo "\x1B[35mCLEAN\x1B[0m"

re : fclean all
