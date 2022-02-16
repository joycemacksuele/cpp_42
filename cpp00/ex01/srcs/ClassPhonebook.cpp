/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 03:30:47 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/16 17:28:53 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClassPhonebook.hpp"

/* Constructor */
Phonebook::Phonebook(void) {
	return ;
}

/* Destructor */
Phonebook::~Phonebook(void) {
	return ;
}

void	Phonebook::add() {
	std::string	input;

	std::cout << "\t First name . . . . . ";
	std::getline(std::cin, input);
	//_firstName = input;
	this->_contact.setFirstName(input);
	std::cout << "\t Last name  . . . . . ";
	std::getline(std::cin, input);
	//_lastName = input;
	this->_contact.setLastName(input);
	std::cout << "\t Nickname . . . . . . ";
	std::getline(std::cin, input);
	//_nickName = input;
	this->_contact.setNickName(input);
	std::cout << "\t Phone number . . . . ";
	std::getline(std::cin, input);
	//_phoneNumber = input;
	this->_contact.setPhoneNumber(input);
	std::cout << "\t Darkest secret . . . ";
	std::getline(std::cin, input);
	//_darkestSecret = input;
	this->_contact.setDarkestSecret(input);
	return ;
}

/**
 * serfill: https://en.cppreference.com/w/cpp/io/manip/setfill
 * setw: https://www.cplusplus.com/reference/iomanip/setw/
 * substr: https://www.cplusplus.com/reference/string/string/substr/
 */
void	Phonebook::displayContactsList(int index) {
	//if (_firstName.empty() && _lastName.empty() && _nickName.empty() && _phoneNumber.empty() && _darkestSecret.empty())
		//return ;
	if (this->_contact.getFirstName().empty() && this->_contact.getLastName().empty() && this->_contact.getNickName().empty() &&
	    this->_contact.getPhoneNumber().empty() && this->_contact.getDarkestSecret().empty())
		return ;
	std::cout << std::endl << "         │";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << index << "│";
	std::cout << std::setfill(' ') << std::setw(10);
	this->_contact.getFirstName().length() > 10 ? std::cout << this->_contact.getFirstName().substr(0, 9) + '.' : std::cout << std::right << this->_contact.getFirstName();//_firstName
	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(10);
	this->_contact.getLastName().length() > 10 ? std::cout << this->_contact.getLastName().substr(0, 9) + '.' : std::cout << std::right << this->_contact.getLastName();//_lastName;
	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(10);
	this->_contact.getNickName().length() > 10 ? std::cout << this->_contact.getNickName().substr(0, 9) + '.' : std::cout << std::right << this->_contact.getNickName();//_nickName;
	std::cout << "│";
	return ;
}

void	Phonebook::displayChosenContact(void) {
	std::cout << std::endl;
	std::cout << "\t First name . . . . . " << this->_contact.getFirstName() << std::endl;//_firstName
	std::cout << "\t Last name  . . . . . " << this->_contact.getLastName() << std::endl;
	std::cout << "\t Nickname . . . . . . " << this->_contact.getNickName() << std::endl;
	std::cout << "\t Phone number . . . . " << this->_contact.getPhoneNumber() << std::endl;
	std::cout << "\t Darkest secret . . . " << this->_contact.getDarkestSecret() << std::endl;
	return ;
}
