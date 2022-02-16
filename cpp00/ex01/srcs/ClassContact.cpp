/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 03:30:47 by jfreitas          #+#    #+#             */
/*   Updated: 2021/12/15 20:27:33 by whoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClassPhonebook.hpp"
#include "../includes/ClassContact.hpp"

/* Constructor */
Contact::Contact(void) {
	return ;
}

/* Destructor */
Contact::~Contact(void) {
	return ;
}

/* getters */
std::string	Contact::geContactFirstName() const {
	return this->_firstName;
}


std::string	Contact::geContactLastName() const {
	return this->_lastName;
}

std::string	Contact::geContactNickName() const {
	return this->_nickName;
}

std::string	Contact::geContactPhoneNumber() const {
	return this->_phoneNumber;
}

std::string	Contact::geContactDarkestSecret() const {
	return this->_darkestSecret;
}


/* setters */
void	Contact::setContact(std::string firstName) {
	this->_firstName = firstName;
}

void	Contact::setContact(std::string lastName) {
	this->_lastName = lastName;
}

void	Contact::setContact(std::string nickName) {
	this->_nickName = nickName;
}

void	Contact::setContact(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void	Contact::setContact(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}

}
