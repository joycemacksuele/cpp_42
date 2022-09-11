# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: jfreitas <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/18 14:10:36 by jfreitas      #+#    #+#                  #
#    Updated: 2022/09/23 12:10:50 by jfreitas      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ShrubberyCreationForm

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
FLAGS = -Iincludes -std=c++98 -Wall -Wextra -Werror -pedantic -D

# -Wshadow if variables/types/typedefs/parameters... have the same name (i.e. shadows one another).
# -Wno-shadow is the default for the compiler, determinating that no warning is issued when variables are being shadowed.

##### INCLUDES #####
INC = ./includes

##### INCLUDES DEPENDENCIES ####
# Any modify to a .hpp file will alert Makefile to recompile
INC_DEP = $(INC)/*.hpp

##### SOURCES #####
SRCPATH = ./srcs
# addprefix = Adds the $(SRCPATH) "prefix" to each argument after the comma.
#SRCS = $(addprefix $(SRCPATH)/, main.cpp Bureaucrat.cpp) #\ if more lines are needed
# wilcard = space-separated list of names of existing files that match one of the given file name patterns.
SRCS = $(wildcard $(SRCPATH)/*.cpp)

##### OBJECTS #####
OBJPATH = $(SRCPATH)/objs
# OBJS = The path to each .o file
# '%' matches any nonempty string, and the other characters match themselves.
OBJS = $(SRCS:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)

#################################### RULES ####################################
#https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html

all:
	@echo "\n$(RESET)$(YELLOW)Arguments available for make:$(GREEN)\n"
	@echo "1 $(RESET)(for ShrubberyCreationForm)$(GREEN)"
	@echo "2 $(RESET)(for RobotomyRequestForm)$(GREEN)"
	@echo "3 $(RESET)(for PresidentialPardonForm)\n"

# -c = Compile or assemble the source files
1: mk_objdir $(INC_DEP)
	$(CC) $(FLAGS) FORM=$(NAME) -c $(SRCS)
	@mv *.o $(OBJPATH)
	@echo "\n$(RESET)$(GREEN)Building the executable for $(NAME) from the object files$(RESET)"
	$(CC) $(FLAGS) FORM=$(NAME) -o $(NAME) $(OBJS)
	@echo "\n$(RESET)$(LIGHT_BLUE)$(NAME)$(GREEN) is built\n$(RESET)"

2: mk_objdir $(INC_DEP)
	$(CC) $(FLAGS) FORM=RobotomyRequestForm -c $(SRCS)
	@mv *.o $(OBJPATH)
	@echo "\n$(RESET)$(GREEN)Building the executable for RobotomyRequestForm from the object files$(RESET)"
	$(CC) $(FLAGS) FORM=RobotomyRequestForm -o RobotomyRequestForm $(OBJS)
	@echo "\n$(RESET)$(LIGHT_BLUE)RobotomyRequestForm$(GREEN) is built\n$(RESET)"

3: mk_objdir $(INC_DEP)
	$(CC) $(FLAGS) FORM=PresidentialPardonForm -c $(SRCS)
	@mv *.o $(OBJPATH)
	@echo "\n$(RESET)$(GREEN)Building the executable for PresidentialPardonForm from the object files$(RESET)"
	$(CC) $(FLAGS) FORM=PresidentialPardonForm -o PresidentialPardonForm $(OBJS)
	@echo "\n$(RESET)$(LIGHT_BLUE)PresidentialPardonForm$(GREEN) is built\n$(RESET)"

mk_objdir:
	@if [ ! -d $(OBJPATH) ]; then echo "\n$(RESET)$(GREEN)Generating .o objects$(RESET)"; fi
	@if [ ! -d $(OBJPATH) ]; then mkdir $(OBJPATH); fi

# $@ = The target of the rule -> $(NAME)
# $< = The first prerequisite
# $^ = All prerequisites
# $? = All prerequisites NEWER than the target
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
$(NAME): $(OBJS) $(INC_DEP)


#################################### CLEAN ####################################

# PHONY = Prevents make from confusing the phony target with a file name.
.PHONY: clean fclean re print print2

clean:
	@echo "\n$(RESET)$(YELLOW)Removing object directory$(RESET)"
	rm -rf $(OBJPATH)
	@echo "\n\c"

fclean: clean print
	@echo "\n$(RESET)$(YELLOW)\nRemoving $(NAME) binary and form files$(RESET)"
	rm -f $(NAME)
	rm -f RobotomyRequestForm
	rm -f PresidentialPardonForm
	rm -f *_shrubbery
	@echo "\n\c"

re: fclean print2 all

#Shit I don't need, why not?
print:
	@echo "---\c"

print2:
	@echo "---"
