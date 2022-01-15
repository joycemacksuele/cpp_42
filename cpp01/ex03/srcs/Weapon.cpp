/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:11 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/15 15:53:30 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(void) {
	return ;
}

Weapon::Weapon(std::string typeVar) {
	this->type = typeVar;
	//this->weaponRank = 0;
	return ;
}

Weapon::~Weapon(void) {
	return ;
}

const std::string&	Weapon::getType() {
	return this->type;
}

void	Weapon::setType(std::string typeVar) {
	this->type = typeVar;
}
