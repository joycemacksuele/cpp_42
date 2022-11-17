/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/17 21:58:59 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>
#include <iostream>

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
	{
		// It is compulsory to specify the type when declaring objects of class templates.
		// Otherwise, the compiler will produce an error.
		Array<int> array(8);// Explicit instanciation
		//std::cout << "n = " << 8 << std::endl;
		std::cout << std::endl;
		std::cout << BLUE << "array constructed with parametized contructor and initialized by default:" << RESET << std::endl;
		for (int i = 0; i <= 8; i++) {
			std::cout << "array[" << i << "] = " << array[i] << std::endl;
		}
		std::cout << std::endl;
		std::cout << BLUE << "array initialized with other values:" << RESET << std::endl;
		for (int i = 0; i < 8; i++) {
			array[i] = i + 10;
		}
		for (int i = 0; i <= 8; i++) {
			std::cout << "array[" << i << "] = " << array[i] << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << BOLD << BLUE << "---------------- Codam tests:\n" << RESET << std::endl;
	//Tip: Try to compile int * a = new int(); then display *a
	int *a = new int();
	std::cout << "*a = " << *a << std::endl;
	delete a;
	std::cout << std::endl;

	// creating an array of ints with the Array class but also just as int* to
	// compare them later:
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << RED << "didn't save the same value!!" << RESET << std::endl;
			return 1;
		} else {
			std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
			std::cout << " mirror[" << i << "] = " << numbers[i] << std::endl;
		}
	}

	//SCOPE
	std::cout << std::endl << BLUE << "Beginning of new scope " << RESET << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	std::cout << BLUE << "End of new scope " << RESET << std::endl << std::endl;


	int index = -2;
	try
	{
		numbers[index] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << ": " << index << "\n\n";
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << ": " << MAX_VAL << "\n\n";
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	delete [] mirror;
	atexit(checkleaks);
	return 0;
}
