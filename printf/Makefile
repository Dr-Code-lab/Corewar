# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 15:45:02 by ksenaida          #+#    #+#              #
#    Updated: 2020/11/18 13:57:53 by wtsn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC1 = add_func.c \
       adv_itoa.c \
       ap_arith.c \
       ft_printf.c \
       handling_f.c \
       handling_lf.c \
       nulz.c \
       parsing.c \
       type_b.c \
       type_c.c \
       type_di.c \
       type_di_add.c \
       type_f.c \
       type_f_add.c \
       type_o.c \
       type_other.c \
       type_p.c \
       type_s.c \
       type_u.c \
       type_x.c

SRCS = $(addprefix "src/",$(SRC1))
OBJS = $(SRC1:.c=.o)


HDR = ./includes/
LIBFT = ./src/libft/
FLAGS = -Wall -Wextra -Werror
LIBFTO = ./src/libft/*.o
LIBFT_A = ./src/libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	ar rc $(NAME) $(OBJS) $(LIBFTO)

$(LIBFT_A): libft_a

libft_a:
	make -C $(LIBFT)

%.o: src/%.c includes/printf.h
	gcc $(FLAGS) -c $< -I $(HDR) -o $@

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
