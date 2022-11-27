# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 13:37:18 by nskiba            #+#    #+#              #
#    Updated: 2022/11/12 22:55:12 by nskiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strncmp.c ft_printf.c ft_printstr.c ft_printchar.c ft_putchar.c ft_printptr.c ft_printnbr.c ft_printunsign.c ft_printbase.c ft_ptrlen.c ft_putnbr.c get_next_line.c get_next_line_utils.c ft_lstclear.c ft_lstiter.c ft_lstnew.c ft_lstsize.c ft_lstdelone.c ft_lstlast.c ft_lstadd_back.c ft_lstadd_front.c ft_putnbr_fd.c ft_split.c ft_putendl_fd.c ft_putstr_fd.c ft_strmapi.c ft_putchar_fd.c ft_striteri.c ft_memchr.c ft_itoa.c ft_strtrim.c ft_bzero.c ft_strjoin.c ft_isalnum.c ft_isalpha.c ft_calloc.c ft_strdup.c ft_substr.c ft_isascii.c ft_isdigit.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strrchr.c ft_tolower.c ft_toupper.c

OBJCS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

CC = gcc

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJCS}
	ar rc ${NAME} ${OBJCS}

all: ${NAME}

clean:
	rm -f ${OBJCS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re
