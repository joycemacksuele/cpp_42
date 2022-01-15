/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:11 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/15 16:52:42 by jfreitas         ###   ########.fr       */
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

void	HumanB::setWeapon(Weapon *weapon) {
	this->weaponB = weapon;
}

void	HumanB::attack() {
	std::cout << GREEN << this->name << RESET << " attacks with " << YELLOW << weaponB->getType() << std::endl;
}
