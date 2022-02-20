/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:11 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/20 18:35:30 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(void) {
	return ;
}

// Also, add a debugging message in the destructor including the name of the Zombie.
Zombie::~Zombie(void) {
	std::cout << std::endl << "Destructor -> ";
	if (getWasAllocated() == 0) {
		std::cout << "Zombie " << GREEN << this->_ZombieName;
		std::cout << RESET << " was not dinamically allocated." << std::endl;
	}
	else if (getWasAllocated() == 1) {
		std::cout << "Zombie " << GREEN << this->_ZombieName;
		std::cout << RESET << " was freed." << std::endl;
	}
	return ;
}

std::string	Zombie::getName() const {
	return this->_ZombieName;
}

void	Zombie::setName(std::string name) {
	this->_ZombieName = name;
}

bool	Zombie::getWasAllocated() const {
	return this->wasAllocated;
}

void	Zombie::setWasAllocated(bool allocated)  {
	this->wasAllocated = allocated;;
}

void	Zombie::announce(void) {
	std::cout << GREEN << this->_ZombieName << ": " << "BraiiiiiiinnnzzzZ...";
	std::cout << RESET;
}
