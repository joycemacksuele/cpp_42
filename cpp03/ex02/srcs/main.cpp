/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/01 12:43:51 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main(void) {

	std::cout << RED << std::endl  << "Default Constructor attacker" << RESET << std::endl;
	FragTrap attacker;// default constructor
	attacker.set_name("JOYCE");
	attacker.attack("YOU");
	attacker.beRepaired(13);

	std::cout << RED << std::endl  << "Overloaded Constructor (with target name) attacker" << RESET << std::endl;
	FragTrap attacker1("A");// overloaded costructor
	attacker1.attack("A1");
	attacker1.beRepaired(2);
	attacker1.highFivesGuys();

	std::cout << RED << std::endl  << "Copy Constructor attacker" << RESET << std::endl;
	FragTrap attacker2(attacker1);// copy costructor
	attacker2.attack("B1");
	attacker2.beRepaired(15);
	std::cout << BLUE << "Attack damage was set o 5 instead of the standard 30" << RESET << std::endl;
	attacker2.set_attackDamage(5);
	attacker2.attack("B2");
	attacker2.beRepaired(5);

	std::cout << std::endl;
	return 0;
}
