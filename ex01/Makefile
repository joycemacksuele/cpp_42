# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 15:35:00 by jfreitas          #+#    #+#              #
#    Updated: 2021/10/25 20:24:30 by jfreitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = crappy_phonebook

##### COLORS #####
WHITE = \033[1;37m
GREY = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
LIGHT_BLUE = \033[1;36m
END = \033[0m

##### FLAG #####
CC = clang++
FLAGS = -Wall -Wextra -Werror

##### SRC & OBJ PATH #####
SRCPATH = ./srcs
OBJPATH = $(SRCPATH)/objs

##### SOURCES #####
SRCS = $(addprefix $(SRCPATH)/, main.cpp phonebook.cpp)

##### OBJECTS #####
OBJS = $(SRCS:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

#### RULES ####
all: mk_objdir $(NAME)

mk_objdir:
	@if [ ! -d $(OBJPATH) ]; then mkdir $(OBJPATH); fi

#$@ = $(NAME)
#$^ = $(OBJS)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "\n$(END)$(GREEN)$(NAME) is built\n$(END)"

### CLEAN ###
.PHONY: clean fclean re

clean:
	@echo "\n$(END)$(YELLOW)Removing $(NAME) object file\n$(END)"
	@rm -rf $(OBJPATH)

fclean: clean
	@echo "\n$(END)$(YELLOW)\nRemoving $(NAME) binary\n$(END)"
	@rm -f $(NAME)

re: fclean all
