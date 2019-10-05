# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: koparker <koparker@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 13:59:51 by pberge            #+#    #+#              #
#    Updated: 2019/10/05 08:25:17 by pberge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
WFLAGS = -Wall -Wextra -Werror
SRCF = src
SRCS = ft_printf.c	\
	   parse_flags.c\
	   ft_percent.c	\
	   ft_text.c	\
	   ft_s.c	\
	   ft_i.c	\
	   ft_o.c	\
	   ft_x.c	\
	   ft_u.c	\
	   ft_c.c	\
	   ft_p.c	\
	   ft_f.c	\
	   ft_ntoa.c	\
	   ft_ftoa.c	\
	   ft_xlow_xup.c	\
	   ft_refresh_buffer.c\
	   ft_error.c
LSRC = ft_memset.c	ft_memalloc.c	ft_tolower.c	\
		  ft_toupper.c	ft_isprint.c	ft_isascii.c	\
		  ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	\
		  ft_bzero.c	ft_memcpy.c		ft_memccpy.c	\
		  ft_memmove.c	ft_strlen.c		ft_memchr.c		\
		  ft_memcmp.c	ft_strdup.c		ft_strcpy.c		\
		  ft_strncpy.c	ft_strcat.c		ft_strncat.c	\
		  ft_strlcat.c	ft_strchr.c		ft_strrchr.c	\
		  ft_strstr.c	ft_strcmp.c		ft_strnstr.c	\
		  ft_strncmp.c	ft_atoi.c		ft_memdel.c		\
		  ft_strnew.c	ft_strdel.c		ft_strclr.c		\
		  ft_striter.c	ft_striteri.c	ft_strmap.c		\
		  ft_strmapi.c	ft_strequ.c		ft_strnequ.c	\
		  ft_strsub.c	ft_strjoin.c	ft_strtrim.c	\
		  ft_strsplit.c	ft_itoa.c		ft_putchar.c	\
		  ft_putstr.c	ft_putendl.c	ft_putnbr.c		\
		  ft_putchar_fd.c	ft_putstr_fd.c	\
		  ft_putendl_fd.c	ft_putnbr_fd.c	\
		  ft_lstnew.c	ft_lstdelone.c	ft_lstdel.c		\
		  ft_lstadd.c	ft_lstiter.c	ft_lstmap.c		\
		  ft_islower.c	ft_isupper.c	ft_swap_ints.c	\
		  ft_iterative_power.c			\
		  ft_recursive_power.c			\
		  ft_lstadd_to_end.c			ft_strrcpy.c
SRC = $(addprefix $(SRCF)/, $(SRCS))
SRC += $(addprefix libft/, $(LSRC))
OBJF = obj
OBJS = $(SRCS:.c=.o)
OBJS += $(LSRC:.c=.o)
OBJ = $(addprefix $(OBJF)/, $(OBJS))
DEL = rm -rf
INC = -I./inc -I./libft
#LIB = -L./libft -lft
#LIBNAME = libft/libft.a
LIBF = libft

$(NAME): $(OBJF) $(OBJ)
	@ar rc $(NAME) $(OBJ) 

all: $(NAME)

$(OBJF)/%.o: $(LIBF)/%.c 
	@gcc $(WFLAGS) $(INC) -c $< -o $@

$(OBJF)/%.o: $(SRCF)/%.c
	@gcc $(WFLAGS) $(INC) -c $< -o $@

$(OBJF):
	@mkdir $(OBJF)

$(LIBNAME):
	@make -C libft

e:
	gcc -g zcompile/main.c $(SRC) -I./libft -I./inc -o test

c:
	@gcc -g zcompile/main.c -I./libft -I./inc -L. -lftprintf -o test

clean:
	@make clean -C $(LIBF)
	@$(DEL) $(OBJF)/*.o

fclean:
	@make fclean -C $(LIBF)
	@$(DEL) $(OBJF)/*.o
	@$(DEL) $(NAME)

re: fclean
	@make all
