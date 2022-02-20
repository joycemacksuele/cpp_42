/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 03:30:47 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/20 18:09:02 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClassPhonebook.hpp"

/* Constructor */
Phonebook::Phonebook(void) {
	// std::cout << YELLOW << "constructor called!" << std::endl;
	return ;
}

/* Destructor */
Phonebook::~Phonebook(void) {
	//std::cout << YELLOW << "destructor called!" << std::endl;
	return ;
}

int	Phonebook::checkIfEmpty() {
	if (this->_contact.getFirstName().empty() && this->_contact.getLastName().empty()
		&& this->_contact.getNickName().empty() && this->_contact.getPhoneNumber().empty()
		&& this->_contact.getDarkestSecret().empty()) {
		return -1;
	}
	return 0;
}

int	Phonebook::add() {
	std::string	input;

	std::cout << "\t First name . . . . . ";
	std::getline(std::cin, input);
	if (!input.empty())
		this->_contact.setFirstName(input);
	std::cout << "\t Last name  . . . . . ";
	std::getline(std::cin, input);
	if (!input.empty())
		this->_contact.setLastName(input);
	std::cout << "\t Nickname . . . . . . ";
	std::getline(std::cin, input);
	if (!input.empty())
		this->_contact.setNickName(input);
	std::cout << "\t Phone number . . . . ";
	std::getline(std::cin, input);
	if (!input.empty())
		this->_contact.setPhoneNumber(input);
	std::cout << "\t Darkest secret . . . ";
	std::getline(std::cin, input);
	if (!input.empty())
		this->_contact.setDarkestSecret(input);
	if (checkIfEmpty() == -1)
		return -1;
	return 0;
}

/**
 * serfill: https://en.cppreference.com/w/cpp/io/manip/setfill
 * setw: https://www.cplusplus.com/reference/iomanip/setw/
 * substr: https://www.cplusplus.com/reference/string/string/substr/
 */
void	Phonebook::displayContactsList(int index) {
	if (checkIfEmpty() == -1)
		return ;
	std::cout << std::endl << "         │";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << index << "│";
	std::cout << std::setfill(' ') << std::setw(10);
	this->_contact.getFirstName().length() > 10 ? std::cout << this->_contact.getFirstName().substr(0, 9) + '.' : std::cout << std::right << this->_contact.getFirstName();
	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(10);
	this->_contact.getLastName().length() > 10 ? std::cout << this->_contact.getLastName().substr(0, 9) + '.' : std::cout << std::right << this->_contact.getLastName();
	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(10);
	this->_contact.getNickName().length() > 10 ? std::cout << this->_contact.getNickName().substr(0, 9) + '.' : std::cout << std::right << this->_contact.getNickName();
	std::cout << "│";
	return ;
}

void	Phonebook::displayChosenContact(void) {
	if (checkIfEmpty() == -1)
		return ;
	std::cout << std::endl;
	std::cout << "\t First name . . . . . " << this->_contact.getFirstName() << std::endl;
	std::cout << "\t Last name  . . . . . " << this->_contact.getLastName() << std::endl;
	std::cout << "\t Nickname . . . . . . " << this->_contact.getNickName() << std::endl;
	std::cout << "\t Phone number . . . . " << this->_contact.getPhoneNumber() << std::endl;
	std::cout << "\t Darkest secret . . . " << this->_contact.getDarkestSecret() << std::endl;
	return ;
}
