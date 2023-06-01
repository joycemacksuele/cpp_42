/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2023/05/29 14:39:09 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char **argv) {
    // Your program must take an inverted Polish mathematical expression as an argument:

    if (argc != 2) {
        std::cout << RED << "Error: No inverted Polish mathematical expression provided." << RESET << std::endl;
        return -1;
    }

    RPN rpn;
    try {
        rpn.calculate(std::string(argv[1]));
    } catch (...) {
        return -1;
    }
    return 0;
}
