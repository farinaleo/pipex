# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nskiba <nskiba@student.42anougleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 13:37:18 by nskiba            #+#    #+#              #
#    Updated: 2022/11/23 23:44:57 by nskiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

SRCS = main.c error.c

OBJCS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra -g

CC = clang

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJCS}
	make -C libft
	${CC} -o pipex ${CFLAGS} ${OBJCS} -Llibft -lft

all: ${NAME}

clean:
	rm -f ${OBJCS}

fclean: clean
	rm -f ${NAME}

compile: clean
	${CC} ${CFLAGS} ${SRCS} 

re: fclean all

.PHONY : all clean fclean re
