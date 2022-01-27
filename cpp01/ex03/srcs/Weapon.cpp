/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:11 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/20 12:15:08 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(void) {
	return ;
}

Weapon::Weapon(std::string typeVar) {
	this->type = typeVar;
	return ;
}

Weapon::~Weapon(void) {
	return ;
}

std::string&	Weapon::getType() {
	return this->type;
}

void	Weapon::setType(std::string typeVar) {
	this->type = typeVar;
}
