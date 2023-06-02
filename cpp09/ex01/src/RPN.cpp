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
        this->_numbers = std::stack<int64_t>(rhs._numbers);
    }
    return *this;
}

RPN::~RPN() {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Destructor called" << std::endl;
    }
}

int64_t RPN::handleSigns(std::string const& operand_or_operator) {
    if (_numbers.size() < 2) {
        throw std::invalid_argument("Error: Insufficient operands for " + operand_or_operator + " operator.");
    }
    int64_t operand_2 = _numbers.top();
    // Popping out of the stack, the second number/operand that will be used to compute
    _numbers.pop();
    int64_t operand_1 = _numbers.top();
    // Popping out of the stack, the first number/operand that will be used to compute
    _numbers.pop();

    int64_t result;
    if (operand_or_operator == "+") {
        result = operand_1 + operand_2;
    }
    if (operand_or_operator == "-") {
        result = operand_1 - operand_2;
    }
    if (operand_or_operator == "*") {
        result = operand_1 * operand_2;
    }
    if (operand_or_operator == "/") {
        if (operand_2 == 0) {
            throw std::logic_error("Error: Division by zero.");
        }
        result = operand_1 / operand_2;
    }
    return result;
}

int64_t RPN::calculate(std::string const& arg) {
    std::istringstream ss(arg);
    if (ss.fail()) {
        throw std::invalid_argument("Error: String Stream failed ");
    }

    if (verbose) {
        std::cout << BLUE << "stack:\n-----\n" << RESET;
    }

    std::string operand_or_operator;
    while (ss >> operand_or_operator) {
        try {
            // If it is a number from 0 to 9:
            if (operand_or_operator.at(0) && operand_or_operator.at(0) >= '0' && operand_or_operator.at(0) <= '9') {
                int64_t nb = atoll(operand_or_operator.c_str());
                _numbers.push(nb);
                if (verbose) {
                    std::cout << _numbers.top() << std::endl;
                }

            }
            // If it is a sign (+-*/):
            else if (operand_or_operator == "+" || operand_or_operator == "-" || operand_or_operator == "*" || operand_or_operator == "/") {
                int64_t result = handleSigns(operand_or_operator);
                _numbers.push(result);
                if (verbose) {
                    std::cout << GREEN << _numbers.top() << RESET << std::endl;
                }
            }
            // Else, the input exists, but it is not allowed:
            else {
                throw std::invalid_argument("Error: Invalid input expression.");
            }
        } catch (std::logic_error const& ex) {
            throw ex;
        } catch (std::invalid_argument const& ex) {
            throw ex;
        }
    }

    // _numbers has to have 1 item, the result of the computation.
    // Otherwise, the input exists, but it is empty (since _numbers was not filled up):
    if (_numbers.size() != 1) {
        throw std::invalid_argument("Error: Invalid input expression. Try again.");
    }

    if (verbose) {
        std::cout << BLUE << "-----\nresult: " << RESET;
    }
    return _numbers.top();
}
