# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zombunga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 18:33:07 by zombunga          #+#    #+#              #
#    Updated: 2024/08/15 21:29:06 by zombunga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Werror -Wextra

SRC =	ft_printf.c \
	sources/number_utils.c \
	sources/string_utils.c

OBJS = $(SRC:.c=.o)

all: ${NAME}

%.o:%.c
	@${CC} ${FLAGS} -c $< -o $@

$(NAME): ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@echo "Biblioteca \033[1m\033[32mlibftprintf.a\033[0m devidamente criado!"

clean:
	@rm -f ${OBJS}
	@echo "Arquivos \033[1m.o\033[0m devidamente \033[31m\033[1maposentados\033[0m"

fclean: clean
	@rm -f ${NAME}	
	@echo "\033[1mLIMPO!\033[0m"

re: fclean all

.PHONY: all clean fclean re
