# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pberge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 13:59:51 by pberge            #+#    #+#              #
#    Updated: 2019/05/25 12:54:06 by pberge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
WFLAGS = -Wall -Wextra -Werror
SRCF = src
SRCS = ft_printf.c parsers.c
SRC = $(addprefix $(SRCF)/, $(SRCS))
OBJF = obj
OBJS = $(SRCS:.c=.o)
OBJ = $(addprefix $(OBJF)/, $(OBJS))
DEL = rm -rf
INC = -I./inc -I./libft
LIB = -L./libft -lft
LIBNAME = libft/libft.a

$(NAME): $(LIBNAME) $(OBJ)
	ar rc $(NAME) $(OBJ) libft/*.o 

all: $(NAME)

$(OBJF)/%.o: $(SRCF)/%.c $(OBJF)
	gcc $(INC) -c -o $@ $<

$(OBJF):
	mkdir $(OBJF)

$(LIBNAME):
	make -C libft

c:
	gcc compile/main.c -I./libft -L./libft -lft -I./inc -L. -lftprintf -o test

clean:
	make clean -C libft
	$(DEL) $(OBJF)/*.o

fclean:
	make fclean -C libft
	$(DEL) $(OBJF)/*.o
	$(DEL) $(NAME)

re: fclean
	make all
