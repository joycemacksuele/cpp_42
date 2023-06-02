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
        std::cout << RED << "Please input one string of: operators (+-*/) in between operands (0 to 9)." << RESET << std::endl;
        return -1;
    }

    RPN rpn;
    try {
        int64_t result = rpn.calculate(std::string(argv[1]));
        std::cout << GREEN << result << RESET << std::endl;
    } catch (std::logic_error const& ex) {
        std::cout << RED << ex.what() << RESET << std::endl;
        return -1;
    } catch (std::invalid_argument const& ex) {
        std::cout << RED << ex.what() << RESET << std::endl;
        return -1;
    }
    return 0;
}
