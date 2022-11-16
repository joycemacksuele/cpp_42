/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/16 17:03:46 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iter.hpp>
#include <ctype.h>

int main() {
	std::cout << CLEAR_SCREEN;
	std::cout << BOLD << GREEN;
	std::cout << "---------------- My Tests:\n" << RESET << std::endl;

	std::string array = "abcdef";
	size_t len = 4;
	std::cout << "calling iter(array=%s, len=%d, func=%p)" << array << len << &toupper << std::endl;
	::iter(&array, len, toupper);
	/**************************************************************************/
	return 0;
}
