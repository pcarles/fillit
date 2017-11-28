# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarles <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 17:16:50 by pcarles           #+#    #+#              #
#    Updated: 2017/11/28 11:28:20 by pcarles          ###   ########.fr        #
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
	  check.c \
	  map.c \
	  solve.c \
	  print.c \
	  free.c

OBJ = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBDIR) all
	@$(CC) -o $@ $(OBJ) -L$(LIBDIR) -l$(LIB)
	@echo "fillit created."

$(OBJDIR)%.o: %.c $(HDRS)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< -I$(INCDIR) $(FLAGS)

clean:
	@$(MAKE) -C $(LIBDIR) $@
	@rm -rf $(OBJDIR)
	@echo "fillit $(OBJDIR) deleted."

fclean: clean
	@rm -f $(LIBDIR)libft.a
	@rm -f $(NAME)

re: fclean all
