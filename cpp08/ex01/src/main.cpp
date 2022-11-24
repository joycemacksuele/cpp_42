/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/24 11:30:54 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

#define MAX_VAL 5

void	checkleaks(void)
{
	system("echo '\033[1;36m'");
	system("leaks -q Array");
}

int main(int, char**)
{
	std::cout << CLEAR_SCREEN;

	std::cout << BOLD << BLUE << std::endl << "---------------- My tests:\n" << RESET << std::endl;
	/* Test your Span at least with a minimum of 10 000 numbers. More would be
	 * even better.
	 */

	std::cout << std::endl;
	std::cout << BOLD << BLUE << "---------------- Codam tests:\n" << RESET << std::endl;
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		mirror[i] = value;
	}

	std::cout << BLUE << "Initializing 'numbers' and 'mirror' objects to rand numbers and comparing them:" << RESET << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << " mirror[" << i << "] = " << mirror[i] << std::endl;
	}
	std::cout << MAGENTA << "result: OK!" << std::endl;

	int index = -2;
	try {
		std::cout << "Trying invalid index: " << index << " -> ";
		mirror[index] = 0;
	} catch(const std::exception& e) {
		std::cerr << RED << "Error: " << RESET << e.what() << "\n";
	}

	atexit(checkleaks);
	return 0;
}
