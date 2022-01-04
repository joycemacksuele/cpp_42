# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 15:35:00 by jfreitas          #+#    #+#              #
#    Updated: 2022/01/04 23:12:08 by jfreitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = braiiiiiiinnnzzzZ

##### COLORS #####
WHITE = \033[1;37m
GREY = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
LIGHT_BLUE = \033[1;36m
RESET = \033[0m

##### FLAG #####
CC = clang++
FLAGS = -Wall -Wextra -Werror

##### SRC & OBJ PATH #####
SRCPATH = ./srcs
OBJPATH = $(SRCPATH)/objs

##### SOURCES #####
SRCS = $(addprefix $(SRCPATH)/, main.cpp newZombie.cpp randomChump.cpp Zombie.cpp)

##### OBJECTS #####
OBJS = $(SRCS:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

#### RULES ####
all: mk_objdir $(NAME)

mk_objdir:
	@if [ ! -d $(OBJPATH) ]; then mkdir $(OBJPATH); fi

#$@ = $(NAME)
#$^ = $(OBJS)
$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "\n$(RESET)$(GREEN)$(NAME) is built\n$(RESET)"

leaks: mk_objdir
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@leaks -atExit -- ./braiiiiiiinnnzzzZ

### CLEAN ###
.PHONY: clean fclean re leaks

clean:
	@echo "\n$(RESET)$(YELLOW)Removing $(NAME) object file\n$(RESET)"
	@rm -rf $(OBJPATH)

fclean: clean
	@echo "\n$(RESET)$(YELLOW)\nRemoving $(NAME) binary\n$(RESET)"
	@rm -f $(NAME)

re: fclean all
