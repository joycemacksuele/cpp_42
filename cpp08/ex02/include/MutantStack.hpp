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

/* Ways of implementing the stack (with iteration):
 * 1. Use a vector or deque and limit its functionality to only allow push_back
 * and pop_back (and iterate for this exercise).
 * 2. bButchering the original stack to create missing features (chosen here).
 */

/* Stack:
 * - The class template acts as a wrapper to the underlying container (standard
 *   is a deque with only a specific set of functions is provided.
 * - The stack pushes and pops the element from the back of the underlying
 *   container, known as the top of the stack.
 * - The stack data structure follows the LIFO (Last In First Out) principle.
 *   That is, the element added last will be removed first.
 *   So if you want the element at the bottom, you must first remove all the
 *   elements on top. This is exactly how the stack data structure works.
 *
 * Applications of Stack Data Structure:
 * - To reverse a word:
 *   Put all the letters in a stack and pop them out. Because of the LIFO order
 *   of stack, you will get the letters in reverse order.
 * - In compilers:
 *   Compilers use the stack to calculate the value of expressions like
 *   2 + 4 / 5 * (7 - 9) by converting the expression to prefix or postfix form.
 * - In browsers:
 *   The back button in a browser saves all the URLs you have visited previously
 *   in a stack. Each time you visit a new page, it is added on top of the stack.
 *   When you press the back button, the current URL is removed from the stack,
 *   and the previous URL is accessed.
 */

/* Real template prototype of the class stack:
template<class T, class Container = std::deque<T>>
class stack;
*/

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
			/* Returns an iterator to the first element of the list.
			 * If the list is empty the returned iterator will be equal to end().
			 */
			if (this->empty()) {
				return this->c.end();
			}
			return this->c.begin();
			/* c is for const:
			 * cbegin() always return a const_iterator type
			 * begin() may or may not, depend on whether the caller is const or not
			 * Ex: 
			 * mp.begin()->second = 42 would work
			 * mp.cbegin()->second = 42 would not
			 */
		}

		typename std::stack<T>::container_type::iterator end() {
			std::cout << GREEN << "MutantStack" << RESET;
			std::cout << " end() called" << std::endl;
			/* Returns an iterator to the element following the last element
			 * of the list.
			 * This element acts as a placeholder; attempting to access it
			 * results in undefined behavior.
			 */
			return this->c.end();
		}

		/* It gets the member type iterator of the container_type of the stack
		 * which by default is a deque.I.e. iterator is the iterator member type
		 * of a deque.
		 */
		typedef typename std::stack<T>::container_type::iterator iterator;
};

#endif
