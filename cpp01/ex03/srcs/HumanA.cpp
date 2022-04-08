/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:23:00 by jfreitas          #+#    #+#             */
/*   Updated: 2022/04/08 15:19:21 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include "../includes/Weapon.hpp"

/* HumanA takes the Weapon in its constructor. */
HumanA::HumanA( std::string Aname, Weapon& weapon): weaponA(weapon) {
	//this->weaponA = weapon; is not possible because inicialization of reference variables can only be done with initializer list
	this->name = Aname;
	return ;
}

HumanA::~HumanA(void) {
	return ;
}

void	HumanA::attack() {
	std::cout << GREEN << this->name << RESET << " attacks with their " << YELLOW << weaponA.getType() << RESET << std::endl;
}
