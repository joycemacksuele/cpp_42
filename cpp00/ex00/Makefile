# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 15:35:00 by jfreitas          #+#    #+#              #
#    Updated: 2022/03/12 12:42:19 by jfreitas      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

##### COLORS #####
WHITE = \033[1;37m
GREY = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
LIGHT_BLUE = \033[1;36m
RESET = \033[0m

##### FLAGS #####
#CC = clang++
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

##### INCLUDES #####
#INC = ./includes

##### INCLUDES DEPENDENCIES ####
# Any modify to a .hpp file will alert Makefile to recompile
#INC_DEP = $(INC)/*.hpp

##### SOURCES #####
SRCPATH = ./srcs
# addprefix = Adds the $(SRCPATH) "prefix" to each argument after the comma.
# '%' matches any nonempty string, and the other characters match themselves.
SRCS = $(addprefix $(SRCPATH)/, megaphone.cpp) #\ if more lines are needed

##### OBJECTS #####
OBJPATH = $(SRCPATH)/objs
# OBJS = The path to each .o file
OBJS = $(SRCS:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)

#################################### RULES ####################################
#https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html

all: mk_objdir $(NAME)

mk_objdir:
	@if [ ! -d $(OBJPATH) ]; then echo "\n$(RESET)$(GREEN)Generating .o objects$(RESET)"; fi
	@if [ ! -d $(OBJPATH) ]; then mkdir $(OBJPATH); fi

# $@ = The target of the rule -> $(NAME)
# $< = The first prerequisite
# $^ = All prerequisites
# $? = All prerequisites NEWER than the target
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
$(NAME): $(OBJS)# $(INC_DEP)
	@echo "\n$(RESET)$(GREEN)Building the executable from the object files$(RESET)"
	$(CC) $(FLAGS) -o $@ $(OBJS)
	@echo "\n$(RESET)$(LIGHT_BLUE)$(NAME)$(GREEN) is built\n$(RESET)"

# -c = Compile or assemble the source files ($<)
#      $< for the $(SRCPATH)/%.cpp part (the first prerequisite)
# generating an .o object file (with the use of -o) for each source file given.
#      $@ for the $(OBJPATH)/%.o part (the target).
$(OBJPATH)/%.o: $(SRCPATH)/%.cpp# $(INC_DEP)
	$(CC) $(FLAGS) -c $< -o $@

#################################### CLEAN ####################################

# PHONY = Prevents make from confusing the phony target with a file name.
.PHONY: clean fclean re print print2

clean:
	@echo "\n$(RESET)$(YELLOW)Removing object directory$(RESET)"
	rm -rf $(OBJPATH)
	@echo "\n\c"

fclean: clean print
	@echo "\n$(RESET)$(YELLOW)\nRemoving $(NAME) binary$(RESET)"
	rm -f $(NAME)
	@echo "\n\c"

re: fclean print2 all

#Shit I don't need, why not?
print:
	@echo "---\c"

print2:
	@echo "---"
