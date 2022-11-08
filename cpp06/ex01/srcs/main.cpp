/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:16:41 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/08 15:00:06 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Data.hpp>

/* uintptr_t
 * unsigned integer type capable of holding a pointer and a pointer to void.
 *
 * The types intptr_t and uintptr_t are used for storing pointer addresses.
 * They provide a portable and safe way of declaring pointers, and will be the
 * same size as the underlying pointer used on the system. They are useful for
 * converting pointers to their integer representation.
 * These types should be used when portability and safety are an issue.
 */

// Takes a pointer and converts it (meanig its address) to the unsigned integer
// type uintptr_t.
uintptr_t serialize(Data* ptr) {
	uintptr_t dataAddress = reinterpret_cast<uintptr_t>(ptr);
	return dataAddress;
}

// Takes an unsigned integer parameter (containing an address on this case) and
// converts it to a pointer to Data (pointer to the address of Data).
Data* deserialize(uintptr_t raw) {
	Data* dataAddress = reinterpret_cast<Data*>(raw);
	return dataAddress;
}

int main(int ac, char** av) {
	bool verbose = false;

	if (ac == 2) {
		std::string arg = av[1];
		if (arg.compare("-v") == 0) {
			verbose = true;
		}
	}

	Data dataStruct = Data(verbose);

	// Use serialize() on the address of the Data object:
	uintptr_t serializedDataAddress = serialize(&dataStruct);

	// Testing the serialize function:
	std::cout << std::endl;
	std::cout << "Testing the serialized address:" << std::endl;
	std::cout << "The serialized address of the struct Data is:   " << serializedDataAddress << std::endl;
	std::cout << "The serialized address from Hex to Decimal:     " << std::hex << std::showbase << serializedDataAddress << std::endl;
	std::cout << std::endl;

	// Pass the serialize() return value to deserialize():
	Data* deserializedDataAddress = deserialize(serializedDataAddress);

	// Ensure the return value of deserialize() is equal to the original pointer:
	std::cout << BOLD << "Real test:" << std::endl;
	std::cout << "The deserialized address of the struct Data is: " << deserializedDataAddress << std::endl;
	std::cout << "The address of the original Data struct is:     " << &dataStruct << std::endl;
	std::cout << std::endl;

	return 0;
}

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
 *     - Usage: https://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast
 *       Check the vendor APIs opaque data types example.
 *   - It can also cast pointers to or from integer types.
 */
