/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/07 18:26:28 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

static void print_arg_option() {
	std::cout << std::endl << "-------------------------" << std::endl;
	std::cout << "Run also the the argument: " << GREEN << "\"wrong\"" << RESET << std::endl;
	std::cout << "-------------------------" << std::endl;
}

int main(int argc, char **argv) {
	if (argc == 2 && std::strcmp(argv[1], "wrong") == 0) {
        print_arg_option(); 
    //try {
    ////
    //} catch (std::exception& e) {
     //   e.
    //}
	} 

	return 0;
}
