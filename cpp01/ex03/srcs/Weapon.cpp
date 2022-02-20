/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:11 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/20 19:15:58 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(void) {
	return ;
}

Weapon::Weapon(std::string typeVar) {
	this->_type = typeVar;
	return ;
}

Weapon::~Weapon(void) {
	return ;
}

const std::string&	Weapon::getType() {
	return this->_type;
}

void	Weapon::setType(std::string typeVar) {
	this->_type = typeVar;
}
