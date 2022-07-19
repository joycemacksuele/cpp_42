/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/19 19:52:48 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include <string>
#include <iostream>
#include <unistd.h>

#include "./WrongAnimal.hpp"

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

// i.e. WrongCat = child/derived class AND Animal = base/parent class
class WrongCat : public WrongAnimal {

	public:
		WrongCat(void);// Default (no args) constructor
		//WrongCat(const std::string type);// Overloaded constructor (with one param)
		WrongCat(const WrongCat& src);// Overloaded Copy constructor
		WrongCat& operator=(const WrongCat& rhs);// Copy assignment operator
		/* Good to know:
		 * - Move assignment operator is like the Copy assignment one, but the
		 *   parameter is a non const (since we will change it by null-ing it)
		 *   r-value reference (aka ClassName&& rhs).
		 *
		 * - Move assignment operator: will make the current instance point to
		 *   the value the rhs is pointing to, then null the rhs pointer (so rhs
		 *   pointer is lost/not accessible anymore).
		 *
		 * - Copy assignment operator will delete what is inside the current
		 *   instance, allocate a new necessary space to it and copy what is
		 *   inside the rhs to this memory just allocated on the current
		 *   instance (so the rhs pointer is still accessibe and still with the
		 *   value it had before (aka: now we have 2 addresses with the same
		 *   value in it)).
		 *   Important: to return a reference to the class since we don't want
		 *   a deep copy). -> ex: s2 = s1 is actually s2.operator=(s1);
		 */
		~WrongCat(void);// Destructor

		//void makeSound() const;
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
 *     Virtual inheritance:
 *       Is a C++ technique that ensures only one copy of a base/parent class's
 *       member variables are inherited by grandchild/derived classes.
 *
 *     Virtual keyword:
 *     * When we use ‘virtual’ keyword, the default constructor of grandparent
 *       class is called by default even if the parent classes explicitly
 *       call parameterized constructor.
 *     * How to call the parameterized constructor of the Parent class?
 *       - The constructor has to be called in child class.
 *       - In general, it's not allowed to call the grandparent’s constructor
 *       directly, it has to be called through parent class. It is allowed only
 *       when ‘virtual’ keyword is used.
 *
 *     Conclusion:
 *     Without using virtual inheritance, the child class would inherit the
 *     properties of the grandparent class twice, leading to ambiguity.
 */

#endif
