# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:50:56 by imanoka-          #+#    #+#              #
#    Updated: 2020/09/25 15:38:42 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
LIB_DIR = libft
SRCS =		srcs/ft_printf.c \
			srcs/conversion_specifier.c \
			srcs/flag_simple.c \
			srcs/format.c \
			srcs/outils_flags.c \
			srcs/outils_flags_bis.c \
			srcs/specifiers.c \
			srcs/specifiers_d.c \
			srcs/specifiers_f.c \

RESULT = 	ft_printf.o \
			conversion_specifier.o \
			flag_simple.o \
			format.o \
			outils_flags.o\
			outils_flags_bis.o\
			specifiers.o \
			specifiers_d.o\
			specifiers_f.o \

INCLUDES = includes/libftprintf.h
all: $(NAME)
$(NAME):
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/libft.a $(NAME)
	@$(CC) -c $(CFLAGS) $(SRCS) $(INCLUDES)
	@ar rc $(NAME) $(RESULT)
	@ranlib $(NAME)
	@/bin/rm -f libftprintf.h.gch
	@echo "compilation ok"
clean:
	@/bin/rm -f $(RESULT)
	@/bin/rm -f libft/*.o
	@printf "Objects are removed correctly.\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIB_DIR)/libft.a
	@printf "$(NAME) and $(LIB) are removed correctly.\n"
re: fclean all
.PHONY: all clean fclean re
