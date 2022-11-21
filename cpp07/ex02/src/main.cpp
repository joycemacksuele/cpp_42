/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/21 15:36:18 by jfreitas      ########   odam.nl         */
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
		std::cout << "(array) -> ";
		Array<int> array(8);// Explicit instanciation
		//std::cout << "n = " << 8 << std::endl;
		std::cout << std::endl;
		std::cout << BLUE << "array constructed with parametized contructor and initialized by default:" << RESET << std::endl;
		for (int i = 0; i < 8; i++) {
			std::cout << "array[" << i << "] = " << array[i] << std::endl;
		}
		std::cout << std::endl;
		std::cout << BLUE << "array initialized with other values:" << RESET << std::endl;
		for (int i = 0; i < 8; i++) {
			array[i] = i + 10;
		}
		for (int i = 0; i < 8; i++) {
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
	std::cout << "(numbers) -> ";
	Array<int> numbers(MAX_VAL);
	std::cout << std::endl;
	std::cout << BLUE << "'numbers' object constructed with parametized contructor and initialized by default:" << RESET << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}
	std::cout << "numbers.size() = " << numbers.size() << std::endl;
	std::cout << std::endl;

	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << BLUE << "Initializing 'numbers' and 'mirror' objects to rand numbers and comparing them:" << RESET << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << RED << "didn't save the same value!!" << RESET << std::endl;
			return 1;
		} else {
			std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
			std::cout << " mirror[" << i << "] = " << mirror[i] << std::endl;
		}
	}
	std::cout << MAGENTA << "result: OK!" << std::endl;

	//SCOPE
	std::cout << std::endl << BLUE << "Beginning of new scope" << RESET << std::endl;
	{
		// copy constructor (memory allocated = 1)
		std::cout << "(tmp = numbers) -> tmp is allocated:" << std::endl;
		Array<int> tmp = numbers;

		// default constructor (memory allocated = 2)
		std::cout << std::endl << "(tmp2) -> tmp2 is allocated:" << std::endl;
		Array<std::string> tmp2;

		// default constructor for Array<>() (memory allocated = 3) + assignment
		// operator where memmory is deleted for tmp2 (memory allocated = 2)
		// and then allocated again with new Array values(memory allocated = 3)
		std::cout << std::endl << "(tmp2 = Array<int>()) -> Array is allocated, tmp2 is deleted and allocated again:" << std::endl;
		tmp2 = Array<std::string>();

		// copy constructor (memory allocated = 4)
		std::cout << std::endl << "(test(tmp)) -> test is allocated:" << std::endl;
		Array<int> test(tmp);

		std::cout << std::endl;
		std::cout << " tmp.size() = " << tmp.size() << std::endl;
		std::cout << "tmp2.size() = " << tmp2.size() << std::endl;
		std::cout << "test.size() = " << test.size() << std::endl;
		std::cout << std::endl;
	}
	std::cout << BLUE << "End of new scope " << RESET << std::endl << std::endl;

	int index = -2;
	try {
		std::cout << "Trying invalid index: " << index << " -> ";
		numbers[index] = 0;
	} catch(const std::exception& e) {
		std::cerr << RED << "Error: " << RESET << e.what() << "\n";
	}
	try {
		numbers[MAX_VAL - 1] = 0;// valid index
		std::cout << "Trying correct index: " << MAX_VAL - 1 << " -> " << MAGENTA << "result: OK!" << RESET << std::endl;
		std::cout << "Trying invalid index: " << MAX_VAL << " -> ";
		numbers[MAX_VAL] = 0;// invalid index
	} catch(const std::exception& e) {
		std::cerr << RED << "Error: " << RESET << e.what() << "\n\n";
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
		std::cout << "numbers(new rand)[" << i << "] = " << numbers[i] << std::endl;
		std::cout << "mirror(unchanged)[" << i << "] = " << mirror[i] << std::endl;
	}
	std::cout << std::endl;

	delete [] mirror;
	atexit(checkleaks);
	return 0;
}
