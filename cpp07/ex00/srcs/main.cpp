/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/08 17:26:28 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <whatever.hpp>


int main(int argc, char **argv) {
	if (argc == 2 && std::strcmp(argv[1], "-l") == 0) {

	}


	/**************************************************************************/
	//Codam test
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	/**************************************************************************/

	return 0;
}
