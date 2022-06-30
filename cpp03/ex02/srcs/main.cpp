/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/06/30 12:46:13 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main(void) {
	//ClapTrap attacker;// default costructor
	ScavTrap attacker1;// default costructor
	ScavTrap attacker2("B");// overloaded costructor
	ScavTrap attacker3(attacker1);// copy costructor

	std::cout << RED << std::endl << "Default Constructor attacker" << RESET << std::endl;
	attacker1.set_name("A");
	attacker1.attack("A2");
	attacker1.beRepaired(2);
	std::cout << RED << "Attack damage was set o 5 instead of the standard 20" << RESET << std::endl;
	attacker1.set_attackDamage(5);
	attacker1.attack("A22");
	attacker1.beRepaired(5);

	std::cout << RED << std::endl  << "Overloaded Constructor (with target name) attacker" << RESET << std::endl;
	attacker2.attack("B2");
	attacker2.beRepaired(2);
	attacker2.guardGate();

	std::cout << RED << std::endl  << "Copy Constructor attacker" << RESET << std::endl;
	attacker3.set_name("C");
	attacker3.attack("C2");
	attacker3.beRepaired(1);
	return 0;
}
