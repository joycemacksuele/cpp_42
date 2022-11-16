/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/16 13:39:49 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <whatever.hpp>
#include <Fixed.hpp>

int main() {

	std::cout << CLEAR_SCREEN;
	/**************************************************************************/
	//Codam tests
	std::cout << BOLD << GREEN << std::endl;
	std::cout << "---------------- Codam Tests:\n" << RESET << std::endl;
	int a = 2;
	int b = 3;
	std::cout << BOLD << "Before swap:" << RESET << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	::swap(a, b);
	std::cout << BOLD << "\nAfter swap:" << RESET << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << BOLD << "\nBefore swap:" << RESET << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	::swap(c, d);
	std::cout << BOLD << "\nAfter swap:" << RESET << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl << std::endl;
	/**************************************************************************/
	// My tests
	std::cout << BOLD << GREEN;
	std::cout << "---------------- My Tests:\n" << RESET << std::endl;
	Fixed aa = Fixed(100);
	Fixed bb = Fixed(1000);
	//std::cout.precision(1);
	//std::cout.setf(std::ios::fixed);
	std::cout << BOLD << "Before swap:" << RESET << std::endl;
	std::cout << "aa = " << aa << std::endl;
	std::cout << "bb = " << bb << std::endl;
	::swap<Fixed>(aa, bb);// Explicit instanciation
	std::cout << BOLD << "\nAfter swap:" << RESET << std::endl;
	std::cout << "aa = " << aa << std::endl;
	std::cout << "bb = " << bb << std::endl << std::endl;
	std::cout << "min(aa, bb) = \n" << ::min(aa, bb) << std::endl;
	std::cout << "max(aa, bb) = \n" << ::max(aa, bb) << std::endl;

	char cc = 'b';
	char dd = 'a';
	std::cout << BOLD << "\nBefore swap:" << RESET << std::endl;
	std::cout << "cc = " << cc << std::endl;
	std::cout << "dd = " << dd << std::endl;
	::swap(cc, dd);// Implicit instanciation
	std::cout << BOLD << "\nAfter swap:" << RESET << std::endl;
	std::cout << "cc = " << cc << std::endl;
	std::cout << "dd = " << dd << std::endl << std::endl;
	std::cout << "min(cc, dd) = " << ::min(cc, dd) << std::endl;
	std::cout << "max(cc, dd) = " << ::max(cc, dd) << std::endl << std::endl;
	/**************************************************************************/
	return 0;
}
