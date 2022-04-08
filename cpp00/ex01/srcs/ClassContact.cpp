/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 03:30:47 by jfreitas          #+#    #+#             */
/*   Updated: 2022/03/26 10:02:31 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClassPhonebook.hpp"
#include "../includes/ClassContact.hpp"

/* Constructor */
Contact::Contact(void) {
	//std::cout << RED << "Contact constructor called!" << RESET << std::endl;
	return ;
}

/* Destructor */
Contact::~Contact(void) {
	//std::cout << RED << "Contact destructor called!" << RESET << std::endl;
	return ;
}

/* getters */
const std::string	Contact::getFirstName() const {
	return this->_firstName;
}

const std::string	Contact::getLastName() const {
	return this->_lastName;
}

const std::string	Contact::getNickName() const {
	return this->_nickName;
}

const std::string	Contact::getPhoneNumber() const {
	return this->_phoneNumber;
}

const std::string	Contact::getDarkestSecret() const {
	return this->_darkestSecret;
}


/* setters */
void	Contact::setFirstName(const std::string firstName) {
	this->_firstName = firstName;
}

void	Contact::setLastName(const std::string lastName) {
	this->_lastName = lastName;
}

void	Contact::setNickName(const std::string nickName) {
	this->_nickName = nickName;
}

void	Contact::setPhoneNumber(const std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}
