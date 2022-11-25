/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/25 15:16:31 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

#define TEN_K 10000
void	checkleaks(void) {
	system("echo '\033[1;36m'");
	system("leaks -q executable");
}

int main(int, char**) {
	std::cout << CLEAR_SCREEN;
	Span::verbose = true;

/* ****************************************************************************/
	std::cout << BOLD << BLUE << std::endl << "---------------- My tests:\n" << RESET << std::endl;

	Span mySpan = Span(TEN_K);
	std::vector<int> intVecBigger(TEN_K * 2);
	/* Test your Span at least with a minimum of 10 000 numbers. More would be
	 * even better.
	 */
	srand(time(NULL));
	const int value = rand();
	std::cout << std::endl;
	std::cout << BLUE << "Initializing the 'mySpan' object with 10000 times the number: " << value << RESET << std::endl;
	mySpan.addNumbers(value);
	std::cout << "mySpan size = " << mySpan.getSpanSize() << std::endl << std::endl;
	std::cout << BLUE << "Initializing first 10000 elements of a vector of integers with the number " << value << RESET << std::endl;
	std::fill(intVecBigger.begin(), intVecBigger.end() - TEN_K, value);
	std::cout << "intVecBigger size = " << intVecBigger.size() << std::endl << std::endl;

	std::cout << BLUE << "Comparing 'mySpan' with the first 10000 elements of 'intVecBigger':" << RESET << std::endl;
	int stop = 4;
	for (int i = 0; i < TEN_K; i++) {
		if (mySpan[i] != intVecBigger[i])
		{
			std::cerr << RED << "Values don't match" << RESET << std::endl;
			return 1;
		} else {
			if (!stop)
				break ;
			--stop;
			std::cout << "      mySpan[" << i << "] = " << mySpan[i] << std::endl;
			std::cout << "intVecBigger[" << i << "] = " << intVecBigger[i] << std::endl;
		}
	}
	std::cout << "..." << std::endl;
	for (int i = TEN_K - 2; i < TEN_K + 3; i++) {
		if (i < TEN_K)
			std::cout << "      mySpan[" << i << "] = " << mySpan[i] << std::endl;
		std::cout << "intVecBigger[" << i << "] = " << intVecBigger[i] << std::endl;
	}
	std::cout << "..." << std::endl;
	std::cout << MAGENTA << "result: OK!" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE << "Initializing restant values of 'intVecBigger' with the number " << 42 << RESET << std::endl;
	std::fill(intVecBigger.begin() + TEN_K, intVecBigger.end(), 42);
	for (int i = TEN_K - 2; i < TEN_K + 3; i++)
	{
		std::cout << "intVecBigger[" << i << "] = " << intVecBigger[i] << std::endl;
	}
	std::cout << "..." << std::endl;
	std::cout << std::endl;

	std::cout << BLUE << "Initializing the 'smallSpan' object with 1 time the number: " << 13 << RESET << std::endl;
	Span smallSpan = Span(1);
	smallSpan.addNumber(13);
	std::cout << "span[" << 0 << "] = " << smallSpan[0] << std::endl;
	std::cout << "smallSpan size = " << smallSpan.getSpanSize() << std::endl;
	std::cout << std::endl;

	try {
		std::cout << BLUE <<  "Trying to find the shortest span on 'smallSpan': " << RESET;
		smallSpan.shortestSpan();;
	} catch(const std::exception& e) {
		std::cerr << RED << "Error: " << RESET << e.what() << "\n";
	}
	std::cout << std::endl;

	std::cout << BLUE << "Adding many numbers to 'smallSpan' in one call:" << RESET << std::endl;
	smallSpan.addIntVectorToSpan(intVecBigger);
	stop = 4;
	for (int i = 0; i < stop; i++) {
		std::cout << "smallSpan[" << i << "] = " << smallSpan[i] << std::endl;
	}
	std::cout << "..." << std::endl;
	for (int i = TEN_K - 2; i < TEN_K + 3; i++) {
		std::cout << "smallSpan[" << i << "] = " << smallSpan[i] << std::endl;
	}
	std::cout << "smallSpan size = " << smallSpan.getSpanSize() << std::endl;
	std::cout << std::endl;

/* ****************************************************************************/
	std::cout << BOLD << BLUE << "---------------- Codam tests:\n" << RESET << std::endl;

	Span span = Span(5);
	std::cout << std::endl;
	std::cout << BLUE << "Initializing the 'span' object:" << RESET << std::endl;
	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);
	std::cout << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << "span[" << i << "] = " << span[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << span.shortestSpan() << " is the shortest span" << std::endl;
	std::cout << std::endl;

	std::cout << span.longestSpan() << " is the longest span" << std::endl;
	std::cout << std::endl;

	try {
		std::cout << BLUE << "Trying to add one more number: " << RESET;
		span.addNumber(11);
	} catch(const std::exception& e) {
		std::cerr << RED << "Error: " << RESET << e.what() << "\n";
	}
	std::cout << std::endl;
/* ****************************************************************************/

	atexit(checkleaks);
	return 0;
}
