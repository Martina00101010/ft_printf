# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pberge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 13:59:51 by pberge            #+#    #+#              #
#    Updated: 2019/05/12 16:36:58 by pberge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
WFLAGS = -Wall -Wextra -Werror
SRCF = src
SRCS = main.c	\
		ft_printf.c
SRC = $(addprefix $(SRCF)/, $(SRCS))
OBJF = obj
OBJS = $(SRCS:.c=.o)
OBJ = $(addprefix $(OBJF)/, $(OBJS))
DEL = rm -rf
INC = -I./inc

$(NAME): $(OBJ)
	gcc $(WFLAGS) $(INC) $(OBJ) -o $(NAME)

all: $(OBJF) $(NAME)

$(OBJF)/%.o: $(SRCF)/%.c
	gcc $(WFLAGS) $(INC) -c -o $@ $<

$(OBJF):
	mkdir $(OBJF)

clean:
	$(DEL) $(OBJF)/*.o

fclean:
	$(DEL) $(OBJF)/*.o
	$(DEL) $(NAME)

re: fclean
	make all
