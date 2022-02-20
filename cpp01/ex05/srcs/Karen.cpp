/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:11 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/20 20:01:01 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Karen.hpp"

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
Karen::Karen(void) {
	return ;
}

Karen::~Karen(void) {
	return ;
}

void	Karen::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
}

void	Karen::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
}

void	Karen::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
}

void	Karen::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now.";
}

void	Karen::complain(std::string level) {
	Karen	obj;

	// declaring a pointer to member function
	void (Karen::*fptr)(void);
	switch(level[0]) {
		case 'D' :
			//this->debug();
			fptr = &Karen::debug;
			break ;
		case 'I' :
			fptr = &Karen::info;
			break ;
		case 'W' :
			fptr = &Karen::warning;
			break ;
		case 'E' :
			fptr = &Karen::error;
			break ;
	}
	std::cout << GREEN;
	// calling member function
	(obj.*fptr) ();
	std::cout << RESET << std::endl;
}
