/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 11:41:17 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/24 17:34:20 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>
#include <sstream>
#include <algorithm>

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

/* Why typename keyword is being used on the return type?
 * A name used in a template declaration or definition and that is dependent on
 * a template-parameter is assumed not to name a type unless the applicable name
 * lookup finds a type name or the name is qualified by the keyword typename.
 *
 * lookup:
 * Some names denote types or templates. In general, whenever a name is
 * encountered it is necessary to determine whether that name denotes one of
 * these entities before continuing to parse the program that contains it.
 * The process that determines this is called name lookup.
 *
 * Check first answer of:
 * https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
 */

template <typename T>
typename T::iterator const easyfind(T & arg1, int const& toFind) {
	/* Container adaptors (stack, queue, priority_queue) don't have the begin
	 * or end iterators, to parse one of them, the arg1 would have to be
	 * passed by value because there is no way to traverse them without erasing
	 * their elements (so a copy is needed).
	 */
	typename T::iterator containerIter = std::find(arg1.begin(), arg1.end(), toFind);
	if (containerIter == arg1.end()) {
		throw std::runtime_error("does not exist on the container");
	}
	return containerIter;

	/* std::for_each could be used? 
	 * - for_each s a built-in function under the header <algorithm>.
	 * Response: No since the third param receives only one parameter, each
	 * element of the container passed to it (so it could not compare itself
	 * to arg2 (unless arg2 was global but lets not go there/do it).
	 *
	 * Third parameter of for_each:
	 * A function object. To be applied to the result of dereferencing every
	 * iterator in the range [first, last]
	 * The signature of the function should be equivalent to the following:
	 *      void fun(const Type &a);
	 * - The signature does not need to have const &.
	 * - The type Type must be such that an object of type InputIt can be
	 * dereferenced and then implicitly converted to Type.
	 *
	 * Syntax:
	 * std::for_each(arg1.begin(), arg1.end(), firstOccurrence) {...}
	 */
}


/* ****************************************************************************
 * Containers:
 *
 *** Sequence containers:
 * Sequence containers implement data structures which can be accessed
 * sequentially.
 *     array: static contiguous array
 *     vector: dynamic contiguous array
 *     deque: double-ended queue
 *     forward_list: singly-linked list
 *     list: doubly-linked list
 *
 *** Associative containers:
 * Associative containers implement sorted data structures that can be quickly
 * searched (O(log n) complexity).
 *     set: collection of unique keys, sorted by keys
 *     map: collection of key-value pairs, sorted by keys, keys are unique
 *     multiset: collection of keys, sorted by keys
 *     multimap: collection of key-value pairs, sorted by keys
 *
 *** Unordered associative containers (since C++11)
 * Unordered associative containers implement unsorted (hashed) data structures
 * that can be quickly searched (O(1) amortized, O(n) worst-case complexity).
 *     unordered_set: collection of unique keys, hashed by keys
 *     unordered_map: collection of key-value pairs, hashed by keys, keys are
 *                    unique
 *     unordered_multiset: collection of keys, hashed by keys
 *     unordered_multimap: collection of key-value pairs, hashed by keys
 *
 *** Container adaptors:
 * Container adaptors provide a different interface for sequential containers.
 *    stack: adapts a container to provide stack (LIFO data structure)
 *    queue: adapts a container to provide queue (FIFO data structure)
 *    priority_queue: adapts a container to provide priority queue
 *    flat_set: adapts a container to provide a collection of unique keys,
 *              sorted by keys
 *    flat_map: adapts a container to provide a collection of key-value pairs,
 *              sorted by unique keys
 *    flat_multiset: adapts a container to provide a collection of keys,
 *                   sorted by keys
 *    flat_multimap: adapts a container to provide a collection of key-value
 *                   pairs, sorted by keys
 */

/* ****************************************************************************
 * Templates:
 *
 * typename or class keywords can be used (they are the same).
 *
 *** Why can templates only be implemented in the header file?
 *   Templates are often used in headers because the compiler needs to instantiate 
 *   different versions of the code, depending on the parameters given/deduced
 *   for template parameters, and it's easier (as a programmer) to let the
 *   compiler recompile the same code multiple times and deduplicate later.
 *   - https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
 *
 *** Default templantes: template <typename T = int>
 * it will use the default type if no type is sent to it (explicitally): funcOrClass<>
 *
 *** Important: A template is literally a template; a class/function template
 *   is not a class, it's a recipe for creating a new class/function for each
 *   T we encounter.
 *** I.e. A template cannot be compiled into code, only the result of
 *   instantiating the template can be compiled.
 *
 */

/* ****************************************************************************
 * Can Lamda expression be downgrade to C++ 98?
 * No they cannot. Prior C++11 standards have no notion of lambda syntax.
 * Though there are surrogates available like boost::lambda (can't be used here).
 *
 * You can provide functor style classes, overriding the call operator
 * (<return_type> operator()(<args>);), to provide the same effect, as mentioned
 * in the other answer.
 *
 * Functor (function object type):
 *    struct firstOccurrence {
 *        void operator()(T const &each) {
 *        ...
 *        }
 *    };
 */

#endif
