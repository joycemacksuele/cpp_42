/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/16 16:23:58 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iter.hpp>

int main() {
	std::cout << CLEAR_SCREEN;
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
