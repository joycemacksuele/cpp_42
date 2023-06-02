/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2023/05/29 14:39:09 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <stdexcept>
#include <stack>

#define RESET         "\033[0m"
#define RED           "\033[31m"
#define GREEN         "\033[32m"
#define YELLOW        "\033[33m"
#define BLUE          "\033[34m"
#define MAGENTA       "\033[35m"
#define CYAN          "\033[36m"
#define BOLD          "\x1B[1m"
#define CLEAR_SCREEN  "\033c"
#define ERASE_LINE    "\033[2K"
#define JUMP_ONE_LINE "\033[1B"

class RPN {
public:
    RPN();
    RPN(RPN const & rhs);// Copy constructor
    RPN& operator=(RPN const& rhs);// Assignment operator
    ~RPN();

    /************************** member methods ****************************/
    int64_t calculate(std::string const& arg);

    /************************* member variables ***************************/
    static bool verbose;

private:
    // stack is the perfect data type for a postfix notation (aka reversed polish notation)
    // first comes operands, then operators (all in order - of importance for operators too)
    // ex: 123*+ (operands on stack in this order, and operators will be used (also in this order)
    // to compute using the operands just stored on the stack)
    // pop 3 and 2 => 3*2 = 6 (push 6 back to stack)
    // pop 1 and 6 => 1+6 = 7 (pish 7 to stack)
    // At the end stack will have the result of the computation
    std::stack<int64_t> _numbers;

    /************************** member methods ****************************/
    int64_t handleSigns(std::string const& operand_or_operator);
};

#endif
