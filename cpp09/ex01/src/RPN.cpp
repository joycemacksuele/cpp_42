/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2023/05/29 14:39:09 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

bool RPN::verbose = false;

RPN::RPN() {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Default constructor called" << std::endl;
    }
}

RPN::RPN(RPN const & rhs)
    : _numbers(rhs._numbers) {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Copy constructor called" << std::endl;
    }
}

RPN& RPN::operator=(RPN const & rhs) {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Assignment operator called" << std::endl;
    }
    if (this != &rhs) {
        this->_numbers = std::stack<int>(rhs._numbers);
    }
    return *this;
}

RPN::~RPN() {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Destructor called" << std::endl;
    }
}

int RPN::handleSigns(std::string const& sign_or_number) {
    if (_numbers.size() < 2) {
        std::cout << RED << "Error: Insufficient operands for " << sign_or_number << " operator." << RESET << std::endl;
        throw std::invalid_argument("Error: Insufficient operands for " + sign_or_number + " operator.");
    }
    int n2 = _numbers.top();
    _numbers.pop();
    int n1 = _numbers.top();
    _numbers.pop();

    int result;
    if (sign_or_number == "+") {
        result = n1 + n2;
    }
    if (sign_or_number == "-") {
        result = n1 - n2;
    }
    if (sign_or_number == "*") {
        result = n1 * n2;
    }
    if (sign_or_number == "/") {
        if (n2 == 0) {
            std::cout << RED << "Error: Division by zero." << RESET << std::endl;
            throw std::logic_error("Error: Division by zero.");
        }
        result = n1 / n2;
    }
    return result;
}

int RPN::calculate(std::string const& arg) {
    std::istringstream ss(arg);
    if (ss.fail()) {
        throw std::invalid_argument("Error: String Stream failed ");
    }

    std::string sign_or_number;
    while (ss >> sign_or_number) {
        // std::cout << BLUE << "sign_or_number: " << sign_or_number << RESET << std::endl;
        try {
            if (sign_or_number.at(0) && sign_or_number.at(0) >= '0' && sign_or_number.at(0) <= '9') {
                int nb = atoi(sign_or_number.c_str());
                _numbers.push(nb);

            } else if (sign_or_number == "+" || sign_or_number == "-" || sign_or_number == "*" || sign_or_number == "/") {
                int result = handleSigns(sign_or_number);
                _numbers.push(result);
            } else {
                std::cout << RED << "Error: Invalid input expression." << RESET << std::endl;
                throw std::invalid_argument("Error: Invalid input expression.");
            }
        } catch (std::exception const& ex) {
            throw ex;
        }
    }
    if (_numbers.size() != 1) {
        std::cout << RED << "Error: Invalid input expression." << RESET << std::endl;
        throw std::invalid_argument("Error: Invalid input expression.");
    }

    std::cout << GREEN << _numbers.top() << RESET << std::endl;
    return _numbers.top();
}
