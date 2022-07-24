/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/24 15:25:31 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include <iostream>
#include <unistd.h>

#include "./Animal.hpp"
#include "./Brain.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

/*
 * Class Inheritance:
 * The capability of a class to derive properties and characteristics from another class.
 * - The new class created is called “derived class” or “child class”.
 * - The existing class is known as the “base class” or “parent class”.
 * Memory for the child class is set aside (enough for both the child,  parent, ...).
 *
 * Inheritance instanciation:
 * class <ClassName> : <Encapsulation_level> <ParentClassName> {...}
 *
 * Encapsulation level of Inheritance:
 *  OBS.: If neither is specified, PRIVATE is taken as default.
 *  OBS_2.: Private members keep being private (accessed only through getters/
 *  setters) even if their class is inherited.
 *
 *  * public: Accessible from everywhere:
 *    - Obs.: public members of the base/parent class also become the public
 *      members of the derived/child class. i.e. the public members of the parent
 *      class are accessible by the objects of the child class as well as by the
 *      member functions of the child class.
 *
 *  * protected: Accessible from an Object of the class and derived Objects:
 *    (only the child and its children (its objects) are aware that they inherit from a class).
 *    - Obs.: If you want a member to be private but still accessible to its child(rem)
 *      class, leave it as protected (only the own class and the children can then
 *      directly access those protected members).
 *
 *  * private: Only accessible from an Object of the class:
 *    (no one other than Child is aware of the inheritance).
 *    - Obs.: public members of the base/parent class becomes the private members
 *      of the derived/child class. i.e. the public members of the parent class
 *      can only be accessed by the member functions of the child class (They are
 *      inaccessible to the objects of the derived class).
 */

// i.e. Cat = child/derived class AND Animal = base/parent class
class Cat : public Animal {

	public:
		Cat(void);// Default (no args) constructor
		Cat(const std::string type);// Overloaded constructor (with one param)
		Cat(const Cat& src);// Overloaded Copy constructor
		Cat& operator=(const Cat& rhs);// Copy assignment operator
		~Cat(void);// Destructor

		void makeSound() const;//overrites the parent class method

		Brain* getBrain() const;

	private:
		Brain* _brain;
};

/*
 * Multiple Inheritance:
 *
 * class <ClassName> : <Encapsulation_level> <ParentClassName>, <Encapsulation_level> <ParentClassName>, ... {...}
 *
 *   - The Diamond Inheritamce "problem":
 *     It occurs when two parent classes of a class (child) have a common parent class:
 *     So an object of the child class has two copies of all members of the
 *     grandparent inherited class(es), causing ambiguities.
 *     * The solution to this problem is ‘virtual’ keyword to avoid unnecessary
 *       copies of the grandparent class (inherited class) on the parent class.
 *       (i.e. unnecessary duplicated calls to its constructor and destructor).
 *
 *     Conclusion:
 *     Without using virtual inheritance, the child class would inherit the
 *     properties of the grandparent class twice, leading to ambiguity.
 *
 *
 *     Virtual inheritance:
 *       Is a C++ technique that ensures only one copy of a base/parent class's
 *       member variables are inherited by grandchild/derived classes.
 *
 *     Virtual keyword:
 *     For constructors/destructors:
 *     * A class may have virtual destructor but can't have a virtual constructor.
 *     * When we use ‘virtual’ keyword, the default constructor of grandparent
 *       class is called by default even if the parent classes explicitly
 *       call parameterized constructor.
 *     * How to call the parameterized constructor of the Parent class?
 *       - The constructor has to be called in child class.
 *       - In general, it's not allowed to call the grandparent’s constructor
 *       directly, it has to be called through parent class. It is allowed only
 *       when ‘virtual’ keyword is used.
 *     For methods:
 *     * Is a member function which is declared within a parent/base class and
 *       is re-defined (overridden) by a derived/chield class.
 *     * Even if the type of the object is the base/parent class, if the
 *       methoded called is virtual on that parent class, then the
 *       implementation of this method on the child class will be executed.
 */

#endif
