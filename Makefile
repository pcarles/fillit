# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarles <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 17:16:50 by pcarles           #+#    #+#              #
#    Updated: 2017/11/22 16:19:40 by pcarles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

LIB = ft

FLAGS = -Wall -Wextra -Werror

LIBDIR = libft/

OBJDIR = obj/

INCDIR = includes/

HDRS = $(INCDIR)fillit.h

SRC = main.c \
	  utils.c \
	  parsing.c \
	  readfile.c \
	  check.c

OBJ = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR) all
	$(CC) -o $@ $(OBJ) -L$(LIBDIR) -l$(LIB)

$(OBJDIR)%.o: %.c $(HDRS)
	@mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< -I$(INCDIR) $(FLAGS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
