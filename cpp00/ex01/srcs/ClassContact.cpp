/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 03:30:47 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/16 17:31:12 by jfreitas         ###   ########.fr       */
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
std::string	Contact::getFirstName() const {
	return this->_firstName;
}

std::string	Contact::getLastName() const {
	return this->_lastName;
}

std::string	Contact::getNickName() const {
	return this->_nickName;
}

std::string	Contact::getPhoneNumber() const {
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret() const {
	return this->_darkestSecret;
}


/* setters */
void	Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

void	Contact::setNickName(std::string nickName) {
	this->_nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}
