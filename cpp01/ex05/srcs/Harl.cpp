/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 15:40:51 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/04/08 16:14:02 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

/*
 * https://www.codeguru.com/cplusplus/c-tutorial-pointer-to-member-function/
 *
 * How to declare a pointer-to-member function:
 *
 * Return_Type (Class_Name::* pointer_name) (Argument_List);
 *
 * Return_Type:   member function return type.
 * Class_Name:    name of the class in which the member function is declared.
 * pointer_name:  a name we'd like to call the pointer variable.
 * Argument_List: member function argument list.
 *
 *	To assign a member function to the pointer, the grammar is:
 * fptr = &Class::function;
 */
Harl::Harl(void) {
	return ;
}

Harl::~Harl(void) {
	return ;
}

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	Harl	obj;

	// declaring a pointer to member function
	void (Harl::*fptr)(void);
	switch(level[0]) {
		case 'D' :
			//this->debug();
			fptr = &Harl::debug;
			break ;
		case 'I' :
			fptr = &Harl::info;
			break ;
		case 'W' :
			fptr = &Harl::warning;
			break ;
		case 'E' :
			fptr = &Harl::error;
			break ;
	}
	std::cout << GREEN;
	// calling member function
	(obj.*fptr) ();
	std::cout << BLUE << std::endl;
}
