# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: symatevo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 22:07:21 by symatevo          #+#    #+#              #
#    Updated: 2021/12/09 22:07:21 by symatevo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = $(shell find "." -name "*.c")

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} $(OBJS)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
