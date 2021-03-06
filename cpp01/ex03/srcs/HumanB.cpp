/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:11 by jfreitas          #+#    #+#             */
/*   Updated: 2022/04/08 15:12:12 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

HumanB::HumanB(std::string Bname) {
	this->name = Bname;
	return ;
}

HumanB::~HumanB(void) {
	return ;
}

/* parameter has to be passed by reference since on the main its passed as
 * a non pointer variable. */
void	HumanB::setWeapon(Weapon& weapon) {
	this->weaponB = &weapon;// has to be the address of the reference variable since weaponB is a pointer, so it has to contain an address.
}

void	HumanB::attack() {
	std::cout << GREEN << this->name << RESET << " attacks with their " << YELLOW << weaponB->getType() << RESET << std::endl;
}
