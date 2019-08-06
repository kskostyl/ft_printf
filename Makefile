# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kskostyl <kskostyl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/01 19:45:35 by kskostyl          #+#    #+#              #
#    Updated: 2019/07/30 19:54:50 by kskostyl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = characterize.c \
	  pars.c \
	  convertation_type.c \
	  convertation_length.c \
	  convertation_length_2.c \
	  ft_printf.c \
	  max_itoa_base.c \
	  u_max_itoa_base.c \
	  itoa_for_e.c \
	  itoa_for_f.c \
	  for_tobige.c \
	  apply_flags_chars_kk.c \
	  apply_flags_digits_kk.c \
	  apply_flags_digits_2_kk.c \
	  apply_flags_digits_util_kk.c \
	  convertation_type_2.c \
	  convertation_type_3.c

OBJECTS = $(SRC:%.c=%.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror -c -I.
INCLUDE = ft_printf.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : LIBF $(OBJECTS)
	ar rc $(NAME) $(OBJECTS) libft/*.o
	ranlib $(NAME)

$(OBJECTS):
	$(CC) $(FLAGS) $(SRC)

LIBF:
	$(MAKE) -C libft/

clean:
	$(MAKE) -C libft/ clean
	rm -rf *.o

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
