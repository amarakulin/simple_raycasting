# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tilda <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 22:46:55 by tilda             #+#    #+#              #
#    Updated: 2020/12/29 22:46:56 by tilda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#gw parser.c libmlx.dylib -framework OpenGL -framework AppKit libft/libft.a get_next_line.c get_next_line_utils.c main.c sort_decreasing.c validate_map.c print_out.c  init_data.c texture_calculation.c wall_casting.c sprite_casting.c load_img.c validate_param.c read_file.c screen_save.c utils_validate.c utils_clean_error.c run_window.c buttons.c

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I ./libft/
OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(FILES:.c=.o))
FRAMEWORK = -framework OpenGL -framework AppKit
FILES = main.c parser.c get_next_line.c sort_decreasing.c validate_map.c print_out.c init_data.c \
	texture_calculation.c wall_casting.c sprite_casting.c load_img.c validate_param.c read_file.c screen_save.c \
	utils_validate.c utils_clean_error.c run_window.c buttons.c utils_init.c
MLX_LIB = libmlx.dylib
LIBFT = libft/libft.a
LIBFT_O = $(addprefix $(OBJDIR), ft_itoa.o  ft_putnbr_fd.o ft_strmapi.o ft_atoi.o  ft_memccpy.o ft_putstr_fd.o ft_strncmp.o \
	ft_bzero.o  ft_memchr.o ft_split.o ft_strnstr.o ft_calloc.o  ft_memcmp.o ft_strchr.o ft_strrchr.o \
	ft_isalnum.o  ft_memcpy.o ft_strdup.o ft_strtrim.o ft_isalpha.o  ft_memmove.o ft_strjoin.o ft_substr.o \
	ft_isascii.o  ft_memset.o ft_strlcat.o ft_tolower.o ft_isdigit.o  ft_putchar_fd.o ft_strlcpy.o ft_toupper.o \
	ft_isprint.o  ft_putendl_fd.o ft_itoa_base.o ft_itoa_hex.o ft_itoa_unsigned.o ft_strlen.o ft_lstadd_front.o \
	ft_lstnew.o ft_lstclear.o ft_lstlast.o ft_lstmap.o ft_lstdelone.o ft_lstiter.o ft_lstadd_back.o ft_lstsize.o)
ALL_O = $(OBJ) $(LIBFT_O)

.PHONY: all clean fclean re lib

all: $(OBJDIR) lib $(NAME)

#	Compiling libft's files
lib:
	@echo "=== Work with libft ==="
	@make -C libft/

$(NAME): $(ALL_O)
	@echo "=== Work with cub3D ==="
	@echo "Creating the binary file cub3D ..."
	@$(CC) $(CFLAGS) $(FRAMEWORK) $(MLX_LIB) $^ -o $@
	@echo "Done"

$(OBJDIR):
	@mkdir obj

$(LIBFT_O):
	@cd $(OBJDIR) && ar -x ../$(LIBFT) && cd ..

$(OBJ): $(OBJDIR)%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

clean:
	@cd libft && make clean
	@rm -rf $(OBJDIR)
	@echo "Delete the .o files in libft and obj directory"

fclean: clean
	@cd libft && make fclean
	@[ -f $(NAME) ] && rm $(NAME)
	@echo "Delete the binary file cub3D and libft.a"

re: fclean all

