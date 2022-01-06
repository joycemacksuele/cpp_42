/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:11 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/06 12:15:30 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(void) {
	return ;
}

Zombie::~Zombie(void) {
	std::string zombieName = getName();
	std::cout << std::endl << "Destructor -> ";
	std::cout << "Zombie " << GREEN << this->_ZombieName;
	std::cout << RESET << " was freed.";
	return ;
}

std::string	Zombie::getName() const {
	return this->_ZombieName;
}

void	Zombie::setName(std::string name) {
	this->_ZombieName = name;
}

void	Zombie::announce(void) {
	std::cout << GREEN << this->_ZombieName << " BraiiiiiiinnnzzzZ...";
	std::cout << RESET;
}
