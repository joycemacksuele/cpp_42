# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: jfreitas <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/18 14:10:36 by jfreitas      #+#    #+#                  #
#    Updated: 2022/09/23 15:33:00 by jfreitas      ########   odam.nl          #
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
OBJPATH_1 = $(SRCPATH)/objs1
OBJPATH_2 = $(SRCPATH)/objs2
OBJPATH_3 = $(SRCPATH)/objs3

# OBJS = The path to each .o file
# '%' matches any nonempty string, and the other characters match themselves.
OBJS_1 = $(SRCS:$(SRCPATH)/%.cpp=$(OBJPATH_1)/%.o)
OBJS_2 = $(SRCS:$(SRCPATH)/%.cpp=$(OBJPATH_2)/%.o)
OBJS_3 = $(SRCS:$(SRCPATH)/%.cpp=$(OBJPATH_3)/%.o)

ShrubberyCreationForm = 1
RobotomyRequestForm = 2
PresidentialPardonForm = 3

#################################### RULES ####################################
#https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
# $@ = The target of the rule -> $(NAME)
# $< = The first prerequisite
# $^ = All prerequisites
# $? = All prerequisites NEWER than the target
# -c = Compile or assemble the source files
all: args

args:
	@echo "\n$(RESET)$(YELLOW)Arguments available for make:$(GREEN)\n"
	@echo "1 $(RESET)(for ShrubberyCreationForm)$(GREEN)"
	@echo "2 $(RESET)(for RobotomyRequestForm)$(GREEN)"
	@echo "3 $(RESET)(for PresidentialPardonForm)\n"

####################################

$(ShrubberyCreationForm): mk_objdir_1 ShrubberyCreationForm

mk_objdir_1:
	@if [ ! -d $(OBJPATH_1) ]; then echo "\n$(RESET)$(GREEN)Generating .o objects$(RESET)"; fi
	@if [ ! -d $(OBJPATH_1) ]; then mkdir $(OBJPATH_1); fi

$(OBJPATH_1)/%.o: $(SRCPATH)/%.cpp $(INC_DEP)
	$(CC) $(FLAGS) FORM=$(NAME) -c $< -o $@

ShrubberyCreationForm: $(OBJS_1) $(INC_DEP)
	@echo "\n$(RESET)$(GREEN)Building the executable for $(NAME) from the object files$(RESET)"
	$(CC) $(FLAGS) FORM=$@ -o $@ $(OBJS_1)
	@echo "\n$(RESET)$(LIGHT_BLUE)$(NAME)$(GREEN) is built\n$(RESET)"

####################################

$(RobotomyRequestForm): mk_objdir_2 RobotomyRequestForm

mk_objdir_2:
	@if [ ! -d $(OBJPATH_2) ]; then echo "\n$(RESET)$(GREEN)Generating .o objects$(RESET)"; fi
	@if [ ! -d $(OBJPATH_2) ]; then mkdir $(OBJPATH_2); fi

$(OBJPATH_2)/%.o: $(SRCPATH)/%.cpp $(INC_DEP)
	$(CC) $(FLAGS) FORM=RobotomyRequestForm -c $< -o $@

RobotomyRequestForm: $(OBJS_2) $(INC_DEP)
	@echo "\n$(RESET)$(GREEN)Building the executable for RobotomyRequestForm from the object files$(RESET)"
	$(CC) $(FLAGS) FORM=$@ -o $@ $(OBJS_2)
	@echo "\n$(RESET)$(LIGHT_BLUE)$@$(GREEN) is built\n$(RESET)"

####################################

$(PresidentialPardonForm): mk_objdir_3 PresidentialPardonForm

mk_objdir_3:
	@if [ ! -d $(OBJPATH_3) ]; then echo "\n$(RESET)$(GREEN)Generating .o objects$(RESET)"; fi
	@if [ ! -d $(OBJPATH_3) ]; then mkdir $(OBJPATH_3); fi

$(OBJPATH_3)/%.o: $(SRCPATH)/%.cpp $(INC_DEP)
	$(CC) $(FLAGS) FORM=PresidentialPardonForm -c $< -o $@

PresidentialPardonForm: $(OBJS_3) $(INC_DEP)
	@echo "\n$(RESET)$(GREEN)Building the executable for PresidentialPardonForm from the object files$(RESET)"
	$(CC) $(FLAGS) FORM=$@ -o $@ $(OBJS_3)
	@echo "\n$(RESET)$(LIGHT_BLUE)$@$(GREEN) is built\n$(RESET)"

#################################### CLEAN ####################################

# PHONY = Prevents make from confusing the phony target with a file name.
.PHONY: clean fclean re print print2 1 2 3 $(ShrubberyCreationForm)

clean:
	@echo "\n$(RESET)$(YELLOW)Removing object directory$(RESET)"
	rm -rf $(OBJPATH_1)
	rm -rf $(OBJPATH_2)
	rm -rf $(OBJPATH_3)
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
