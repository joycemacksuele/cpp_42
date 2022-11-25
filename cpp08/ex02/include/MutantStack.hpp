#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <vector>
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

template<typename T>
class MutantStack: public std::stack<T>
{
    public:
        // Default (no args) constructor
        MutantStack<T>(void) {
            std::cout << GREEN << "MutantStack" << RESET;
		    std::cout << " Default constructor called" << std::endl;
		}

        /* OBS.:
		 * - In C++, assignment and copy construction are different because the
		 * copy constructor initializes uninitialized memory, whereas assignment
		 * starts with an existing initialized object.
		 * - In general, copy ctors should invoke the copy ctors of their members.
		 *
		 */

        // Copy constructor
	    MutantStack<T>(MutantStack<T> const & rhs) {
            std::cout << GREEN << "MutantStack" << RESET;
		    std::cout << " Copy constructor called" << std::endl;
            *this = rhs;
        }

        // Assignment operator
	    MutantStack<T> & operator=(MutantStack<T> const & rhs) {
            std::cout << GREEN << "MutantStack" << RESET;
		    std::cout << " Assignment operator called" << std::endl;
            if (this != &rhs) {
                *this = std::stack<T>::operator=(rhs);
            }
            return *this;
        }

        // Destructor
	    ~MutantStack<T>(void) {
            std::cout << GREEN << "MutantStack" << RESET;
		    std::cout << " Destructor called" << std::endl;
        }

	    typename std::stack<T>::container_type::iterator begin() {
            std::cout << GREEN << "MutantStack" << RESET;
		    std::cout << " begin() called" << std::endl;
            return this->c.begin();
        }
	    typename std::stack<T>::container_type::iterator end() {         
            std::cout << GREEN << "MutantStack" << RESET;
		    std::cout << " end() called" << std::endl;
            return this->c.end();
        }

	    typedef typename std::stack<T>::container_type::iterator iterator;
};

#endif
