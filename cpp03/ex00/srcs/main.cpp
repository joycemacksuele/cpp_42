/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/01 12:57:41 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void) {

	std::cout << RED << std::endl  << "Default Constructor attacker" << RESET << std::endl;
	ClapTrap attacker1;
	attacker1.set_name("Attacker 1");
	attacker1.attack("Joyce");
	attacker1.beRepaired(2);

	std::cout << RED << std::endl  << "Overloaded Constructor (with target name) attacker" << RESET << std::endl;
	ClapTrap attacker2("Attacker 2");
	attacker2.attack("Codam");
	attacker2.beRepaired(2);

	std::cout << RED << std::endl  << "Copy Constructor attacker" << RESET << std::endl;
	ClapTrap attacker3(attacker2);
	std::cout << BLUE << "Attack damage was set o 5 instead of the standard 0" << RESET << std::endl;
	attacker3.set_attackDamage(5);
	attacker3.attack("Larry");
	attacker3.beRepaired(1);

	std::cout << std::endl;
	return 0;
}
