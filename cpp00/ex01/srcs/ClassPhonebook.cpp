/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 03:30:47 by jfreitas          #+#    #+#             */
/*   Updated: 2022/03/26 10:02:37 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClassPhonebook.hpp"

/* Constructor */
Phonebook::Phonebook(void) {
	//std::cout << YELLOW << "Phonebook constructor called!" << RESET << std::endl;
	return ;
}

/* Destructor */
Phonebook::~Phonebook(void) {
	//std::cout << YELLOW << "Phonebook destructor called!" << RESET << std::endl;
	return ;
}

int	Phonebook::checkIfEmpty(int i) {
	if (this->_contact[i].getFirstName().empty()
			|| this->_contact[i].getLastName().empty()
			|| this->_contact[i].getNickName().empty()
			|| this->_contact[i].getPhoneNumber().empty()
			|| this->_contact[i].getDarkestSecret().empty()) {
		return -1;
	}
	return 0;
}

int	Phonebook::addContact(int contactIndex) {
	if (contactIndex == 8) {
		this->add(0);
	}
	else {
		if (this->add(contactIndex) == 0) {
			contactIndex++;
		}
	}
	return contactIndex;
}

int	Phonebook::add(int i) {
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "\t First name . . . . . ";
	std::getline(std::cin, firstName);
	//std::cin >> firstName;// after a space it counts the \n as a character not as end of input
	std::cout << "\t Last name  . . . . . ";
	std::getline(std::cin, lastName);
	std::cout << "\t Nickname . . . . . . ";
	std::getline(std::cin, nickName);
	std::cout << "\t Phone number . . . . ";
	std::getline(std::cin, phoneNumber);
	std::cout << "\t Darkest secret . . . ";
	std::getline(std::cin, darkestSecret);
	if (!firstName.empty() && !lastName.empty() && !nickName.empty()
			&& !phoneNumber.empty() && !darkestSecret.empty()) {
		this->_contact[i].setFirstName(firstName);
		this->_contact[i].setLastName(lastName);
		this->_contact[i].setNickName(nickName);
		this->_contact[i].setPhoneNumber(phoneNumber);
		this->_contact[i].setDarkestSecret(darkestSecret);
	} else
		return -1;
	return 0;
}

/**
 * serfill: https://en.cppreference.com/w/cpp/io/manip/setfill
 * setw: https://www.cplusplus.com/reference/iomanip/setw/
 * substr: https://www.cplusplus.com/reference/string/string/substr/
 */
void	Phonebook::displayContactsList(int index) {
	for (int i = 0; i < index; i++) {
		std::cout << std::endl << "         │";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << i + 1 << "│";
		std::cout << std::setfill(' ') << std::setw(10);
		this->_contact[i].getFirstName().length() > 10 ?
			std::cout << this->_contact[i].getFirstName().substr(0, 9) + '.' :
			std::cout << std::right << this->_contact[i].getFirstName();
		std::cout << "│";
		std::cout << std::setfill(' ') << std::setw(10);
		this->_contact[i].getLastName().length() > 10 ?
			std::cout << this->_contact[i].getLastName().substr(0, 9) + '.' :
			std::cout << std::right << this->_contact[i].getLastName();
		std::cout << "│";
		std::cout << std::setfill(' ') << std::setw(10);
		this->_contact[i].getNickName().length() > 10 ?
			std::cout << this->_contact[i].getNickName().substr(0, 9) + '.' :
			std::cout << std::right << this->_contact[i].getNickName();
		std::cout << "│";
	}
}

void	Phonebook::displayChosenContact(int i) {
	if (checkIfEmpty(i) == 0) {
		std::cout << std::endl;
		std::cout << "\t First name . . . . . ";
		std::cout << this->_contact[i].getFirstName() << std::endl;
		std::cout << "\t Last name  . . . . . ";
		std::cout << this->_contact[i].getLastName() << std::endl;
		std::cout << "\t Nickname . . . . . . ";
		std::cout << this->_contact[i].getNickName() << std::endl;
		std::cout << "\t Phone number . . . . ";
		std::cout << this->_contact[i].getPhoneNumber() << std::endl;
		std::cout << "\t Darkest secret . . . ";
		std::cout << this->_contact[i].getDarkestSecret() << std::endl;
	}
}
