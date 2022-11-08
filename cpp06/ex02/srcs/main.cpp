/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:16:41 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/08 15:06:21 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <D.hpp>

//#include <typeinfo> FORBIDEN
// typeid: typeid(expression)
// typeid allows to check the type of an expression
// typeid(exprssion).data()

void	checkleaks(void)
{
	system("echo '\033[1;36m'");
	system("leaks -q ft_typeid");
}

// It randomly instanciates A, B or C and returns the instance as a Base pointer.
// Feel free to use anything you like for the random choice implementation.
Base* generate(void) {
	// Random odd/even can use (num & 0x01) (wow) -> does not work here since
	// we need 3 options for the randomization.
	srand(time(NULL));
	int randomInt = std::rand() % 10;// any number module 10 is from 0 to 9

	Base *abc = NULL;
	if (randomInt < 3) {
		//std::cout << "A" << " | randomInt: " << randomInt << std::endl;
		abc = new A();
	} else if (randomInt < 6) {
		//std::cout << "B" << " | randomInt: " << randomInt << std::endl;
		abc = new B();
	} else {
		//std::cout << "C" << " | randomInt: " << randomInt << std::endl;
		abc = new C();
	}
	return abc;
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p) {
	// check if the pointer is pointing to a A object
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	}
	if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	}
	if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
// Using a pointer inside this function is forbidden.
void identify(Base& p) {
	try {
		identify(&p);
	} catch (std::bad_cast const& ex) {
		// If the dynamic_cast is used on pointers, the null pointer value of
		// type new-type is returned. If it was used on references, the
		// exception std::bad_cast is thrown since there is no such thing as a
		// zero/null reference.
		std::cout << RED <<ex.what() << std::endl;
	}
}

int main() {

	Base* abcPTR = generate();
	Base& abcREF = *abcPTR;

	std::cout << std::endl;
	std::cout << "identify(*) Class type: ";
	identify(abcPTR);// Even though its a pointer, it's passed by value. (to change it pass by reference (Base*& p)).
	std::cout << "identify(&) Class type: ";
	identify(abcREF);// Passed by reference.
	std::cout << std::endl;

	delete abcPTR;

	std::cout << "Testing dynamic_cast with reference: ";
	try {
		D& d = dynamic_cast<D&>(abcREF);
		std::cout << "D: " << &d << std::endl;// just fr the sake of using d
	} catch (std::bad_cast const& ex) {
		// If the dynamic_cast is used on pointers, the null pointer value of
		// type new-type is returned. If it was used on references, the
		// exception std::bad_cast is thrown since there is no such thing as a
		// zero/null reference.
		std::cout << RED << ex.what() << std::endl;
	}

	atexit(checkleaks);
	return 0;
}

/* RTTI
 * Is short for Run-time Type Identification. RTTI is to provide a standard
 * way for a program to determine the type of object during runtime.
 */

/* There are 4 Type Conversion operators:
 *
 * static_cast
 *   - Performs all conversions allowed implicitly.
 *   - Explicitly call a single-argument constructor or a conversion operator.
 *   - Convert to rvalue references.
 *   - Convert from void* to any pointer type.
 *   - Convert any type to void, evaluating and discarding the value.
 *   - Convert integers, floating-point values and enum types to enum types.
 *   - Convert enum class values into integers or floating-point values.
 *   - Obs: No checks are performed during runtime to guarantee that the object
 *   being converted is in fact a full object of the destination type. Therefore,
 *   it is up to the programmer to ensure that the conversion is safe.
 *
 * dynamic_cast
 *   - Can only be used with pointers and references to classes (or with void*).
 *   - Can also downcast (convert from pointer-to-base to pointer-to-derived)
 *   polymorphic classes (those with virtual members) if -and only if- the
 *   pointed object is a valid complete object of the target type.
 *   - Can also perform the other implicit casts allowed on pointers: casting
 *   null pointers between pointers types (even between unrelated classes),
 *   and casting any pointer of any type to a void* pointer.
 *   - Obs: When it cannot cast a pointer because it is not a complete object
 *   of the required class it returns a null pointer to indicate the failure.
 *
 * const_cast
 *   - This type of casting manipulates the constness of the object pointed by
 *   a pointer, either to be set or to be removed.
 *   - Obs: Removing the constness of a pointed object to actually write to it
 *   causes undefined behavior.
 *
 * reinterpret_cast
 *   - Converts any pointer type to other pointer type, even of unrelated classes.
 *     Neither the content pointed nor the pointer type itself is checked.
 *   - It can also cast pointers to or from integer types.
 */
