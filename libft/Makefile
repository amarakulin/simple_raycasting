# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tilda <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 18:24:12 by tilda             #+#    #+#              #
#    Updated: 2020/11/15 20:22:44 by tilda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc 
CFLAGS = -Wall -Werror -Wextra
MAIN_F = ft_itoa.c  ft_putnbr_fd.c ft_strmapi.c ft_atoi.c  ft_memccpy.c ft_putstr_fd.c ft_strncmp.c \
ft_bzero.c  ft_memchr.c ft_split.c ft_strnstr.c ft_calloc.c  ft_memcmp.c ft_strchr.c ft_strrchr.c \
ft_isalnum.c  ft_memcpy.c ft_strdup.c ft_strtrim.c ft_isalpha.c  ft_memmove.c ft_strjoin.c ft_substr.c \
ft_isascii.c  ft_memset.c ft_strlcat.c ft_tolower.c ft_isdigit.c  ft_putchar_fd.c ft_strlcpy.c ft_toupper.c \
ft_isprint.c  ft_putendl_fd.c ft_itoa_base.c ft_itoa_hex.c ft_itoa_unsigned.c ft_strlen.c ft_lstadd_front.c \
ft_lstnew.c ft_lstclear.c ft_lstlast.c ft_lstmap.c ft_lstdelone.c ft_lstiter.c ft_lstadd_back.c ft_lstsize.c

MAIN_OBJ = $(MAIN_F:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MAIN_OBJ)
	@ar -rc $@ $?
	@ranlib $@

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c -Includes $^

clean:
	@rm -f $(MAIN_OBJ) libft.h.gch

fclean: clean
	@rm -f $(NAME)

re: fclean all













