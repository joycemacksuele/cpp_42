/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/06/30 13:06:38 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main(void) {
	std::cout << RED << std::endl  << "Overloaded Constructor (with target name) attacker" << RESET << std::endl;
	ScavTrap attacker1("A");// overloaded costructor
	attacker1.attack("A1");
	attacker1.attack("A2");

	std::cout << RED << std::endl  << "Copy Constructor attacker" << RESET << std::endl;
	ScavTrap attacker2(attacker1);// copy costructor
	attacker2.attack("B1");
	attacker2.guardGate();
	attacker2.attack("B2");
	return 0;
}
