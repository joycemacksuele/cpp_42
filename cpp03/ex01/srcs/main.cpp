/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/06/18 17:56:01 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main(void) {
	ClapTrap attacker;
	ScavTrap attacker1;
	ScavTrap attacker2("Attacker 2");
	ScavTrap attacker3(attacker1);

	attacker1.set_name("Attacker 1");
	attacker1.attack("Attacker 3");
	attacker1.beRepaired(2);

	attacker2.attack("Henrique");
	attacker2.beRepaired(2);

	attacker3.set_name("Attacker 3");
	attacker3.set_attackDamage(5);
	attacker3.attack("You");
	attacker3.beRepaired(1);
	return 0;
}
