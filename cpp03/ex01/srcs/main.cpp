/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/01 12:43:57 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main(void) {
	// no way of setting a name after a default constructor one since set_name is private for the created object

	std::cout << RED << std::endl  << "Overloaded Constructor (with target name) attacker" << RESET << std::endl;
	ScavTrap attacker1("A");// overloaded costructor
	attacker1.attack("A1");
	attacker1.attack("A2");

	std::cout << RED << std::endl  << "Copy Constructor attacker" << RESET << std::endl;
	ScavTrap attacker2(attacker1);// copy costructor
	attacker2.attack("B1");
	attacker2.guardGate();
	attacker2.attack("B2");

	std::cout << std::endl;
	return 0;
}
