/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:17 by jfreitas          #+#    #+#             */
/*   Updated: 2022/04/08 15:07:38 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

/*
 * stringPTR is a pointer a string containing "HI THIS IS BRAIN".
 * stringREF is a reference to the same string created.
 *
 * 1. Display the address in memory of the string.
 * 2. Display the address of the string by using stringPTR.
 * 3. Display the address of the string by using stringREF.
 * 4. Display the string using the pointer.
 * 5. Display it using the reference.
 *
 * - Pointer:
 *   - has its own memory address and size on the stack.
 *   - can be assigned NULL directly.
 *   - pointers to pointers is ok.
 *   - pointers arithmetic is ok.
 * - Reference:
 *   - shares the same memory address (with the original variable).
 *   - also takes up some space on the stack.
 *   - can not be assigned NULL directly.
 *   - reference to reference in not ok (references only offer one level of
 *     indirection).
 *   - reference Arithmetic is not ok (unless the address of an object pointed
 *     by a reference is used as in &obj + 5).
 */
int		main(void) {
	std::string		original;
	std::string*	stringPTR;
	std::string&	stringREF = original; // has to be initialized on the same line

	original = "HI THIS IS BRAIN";
	stringPTR = &original;
	std::cout << std::endl;

	// & is used to show the address of a variable.
	std::cout << "Address of the string:                            ";
	std::cout << GREEN << &original << std::endl << RESET;

	// stringPTR is a pointer so it contains the address of the variable original.
	std::cout << "Address of the string by using stringPTR:         ";
	std::cout << GREEN << stringPTR << std::endl << RESET;

	// & is used to show the address of a variable.
	std::cout << "Address of the string by using &stringREF:        ";
	std::cout << GREEN << &stringREF << std::endl << RESET;

	std::cout << std::endl;

	std::cout << "Display the original string:                      ";
	std::cout << GREEN << original << std::endl << RESET;

	// uses the * to display the value inside the address that stringPTR is pointing to.
	std::cout << "Display the string using the pointer stringPTR:   ";
	std::cout << GREEN << *stringPTR << std::endl << RESET;

	// the stringREF is an alias for the variable original, it has the same value and address.
	std::cout << "Display the string using the reference stringREF: ";
	std::cout << GREEN << stringREF << std::endl << RESET;

	std::cout  << std::endl;

	// display the address of the pointer variable, this address can hold only
	// other address, it can't be initialized to a value.
	std::cout << "bonus -> Address of the pointer stringPTR:        ";
	std::cout << GREEN << &stringPTR << std::endl << RESET;
	std::cout << std::endl;

	return 0;
}
