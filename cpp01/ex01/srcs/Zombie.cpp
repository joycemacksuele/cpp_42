/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:11 by jfreitas          #+#    #+#             */
/*   Updated: 2022/04/08 15:02:15 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(void) {
	return ;
}

Zombie::~Zombie(void) {
	//delete [] this; -> You should not call delete this from your destructor since it will call the destructor recursively, possibly leading to a stack overflow.
	std::string zombieName = getName();
	std::cout << std::endl << "Destructor -> ";
	std::cout << "Zombie " << GREEN << zombieName;
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
	std::cout << GREEN << this->_ZombieName << ": " << "BraiiiiiiinnnzzzZ...";
	std::cout << RESET;
}
