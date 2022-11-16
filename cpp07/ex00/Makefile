# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jfreitas <jfreita@student.codam.nl>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 15:19:00 by jfreitas      #+#    #+#                  #
#    Updated: 2022/11/16 17:04:40 by jfreitas      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################### VARIABLES ##################################
## Variables can only be strings:
# e.g.: a := one two # a is assigned to the string "one two"
# Reference to variables using either ${} or $()
#
## There are two flavors of variables:
# - recursive (use =) -> only looks for the variables when the command is used,
#   not when it's defined.
# - simply expanded (use :=) -> like normal imperative programming. Only those
#   defined so far get expanded.
## e.g.:
# one = one ${later_variable} -> will look for later_variable when one is used.
# two := two ${later_variable} -> later_variable is not yet defined.
# later_variable = later -> The variable defined after one and two variables.
# all:
#	echo $(one) -> This will print "one later"
#	echo $(two) -> This will print "two" (will not print the later_variable)
#
## := allows you to append to a variable:
# e.g.: var3 := ${var1} file ${var2}
# or
# foo := one
# foo += two
#
# ?= only sets variables if they have not yet been set

NAME := templates

##### COLORS and ACTIONS #####
# web.archive.org/web/20190624214929/http://www.termsys.demon.co.uk/vtansi.htm
WHITE := \033[1;37m
GREY := \033[1;30m
RED := \033[1;31m
GREEN := \033[1;32m
YELLOW := \033[1;33m
LIGHT_BLUE := \033[1;36m
RESET := \033[0m
CLEAR_SCREEN := \033c
ERASE_LINE := \033[2K
JUMP_ONE_LINE := \033[1B

##### FLAGS #####
# CC := c++
FLAGS := -Iinclude -Wall -Wextra -Werror -Wshadow -pedantic -std=c++98
# -fsanitize=address -g3
# -pedantic -> Issue all the warnings demanded by strict ISO, it follows the
#  version of the ISO standard specified by any -std option.
# -Wshadow -> if variables, types, typedefs and/or parameters... have the same
#  name (i.e. shadows one another).
# -Wno-shadow -> is the default for the compiler, determinating that no warning
#  is issued when variables are being shadowed.

##### INCLUDES ####
INC := ./include
# Any modify to a .hpp file will alert Makefile;s rules and recompile
INC_DEP := $(INC)/*.hpp

##### SOURCES #####
SRCPATH := ./src
## another way: SRC = $(addprefix $(SRCPATH)/, main.cpp Bureaucrat.cpp)
# addprefix = Adds the $(SRCPATH) "prefix" to each argument after the comma.
SRC := $(wildcard $(SRCPATH)/*.cpp)
## wilcard = space-separated list of names of existing files that match one of
#  the given file name patterns.
## '*' searches your filesystem for matching filenames (can be used in the
#  target, prerequisites, or in the wildcard function.
# e.g.:
# thing_wrong := *.o # Don't do this! '*' will not get expanded
# thing_right := $(wildcard *.o)

##### OBJECTS #####
OBJPATH := ./obj
OBJ := $(SRC:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)
# OBS.: This won't create the .o files, just a string with the .o file names
# - Substitution reference: substitutes the value of a variable with alterations
#   that you specify. It has the form $(var:a=b).
#   Its meaning is to take the value of the variable var, replace every a at
#   the end of a word with b in that value, and substitute the resulting string.
# ---
# '%' matches any nonempty string, the rest after this has to  match themselves.
# It can be used on a variety of situations, some examples:
# - "matching" mode: It matches one or more characters in a string.
#   OBS.: This match is called the stem.
# - "replacing" mode: It takes the stem and replaces that in a string.

#################################### RULES ####################################
## Makefile Syntax of a rule:
# targets: prerequisites
#	command
#	command
# - The targets are file names, separated by spaces. A target will be run only
#   if its file does not exist or if its prerequisites are newer than itself.
# - The prerequisites (or dependencies) are also file names separated by spaces.
#   They need to exist before the commands for the target are run.
# - The commands are a series of steps typically used to make the target(s).
#   These need to start with a tab character, not spaces.

# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html

all: $(NAME)

$(NAME): $(OBJ) $(INC_DEP)
	@echo "\n$(RESET)$(GREEN)Building the executable from the object files$(RESET)"
	$(CXX) $(FLAGS) -o $@ $(OBJ)
	@echo "\n$(RESET)$(LIGHT_BLUE)$(NAME)$(GREEN) is built\n$(RESET)"
#	@echo "if leaks is being used: run export MallocStackLogging=1 to have more info about the leak\n$(RESET)"
# $@ = The target of the rule -> $(NAME)
# $< = The first prerequisite
# $^ = All prerequisites
# $? = All prerequisites NEWER than the target

$(OBJPATH)/%.o: $(SRCPATH)/%.cpp $(INC_DEP)
	@if [ ! -d $(OBJPATH) ]; then echo "\n$(RESET)$(GREEN)Generating .o objects$(RESET)"; fi
	@if [ ! -d $(OBJPATH) ]; then mkdir $(OBJPATH); fi
	$(CXX) $(FLAGS) -c $< -o $@
# - Pattern rules contain a '%' in the target, that creates a stem by matching
#   any nonempty string (the other character(s) have to match themselves).
# - In a prerequisite, '%' stands for the same stem matched by the target.
# -c = Compile or assemble the source files ($<)
#      $< for the $(SRCPATH)/%.cpp part (the first prerequisite)
# generating an .o object file (with the use of -o) for each source file given.
#      $@ for the $(OBJPATH)/%.o part (the target).

################################# CLEAN RULES #################################

.PHONY: clean fclean re print print2
# PHONY = Prevents make from confusing the phony target with a file name.
# i.e.: Use PHONY if a target is not intended to be a filename:
# e.g.: If you happen to have a file named clean, this target won't run, which
# is not what we want.

clean:
	@echo "\n$(RESET)$(YELLOW)Removing object directory$(RESET)"
	$(RM) -r $(OBJPATH)
	@echo "\n\c"

fclean: clean print
	@echo "\n\n$(RESET)$(YELLOW)Removing $(NAME) binary$(RESET)"
	$(RM) $(NAME)
	$(RM) *\~
	$(RM) ./include/*\~
	$(RM) ./src/*\~
	@echo "\n\c"

re: fclean print2 all

#Shit I don't need, why not?
print:
	@echo "---\c"

print2:
	@echo "---"
