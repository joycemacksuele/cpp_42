/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 03:30:47 by jfreitas          #+#    #+#             */
/*   Updated: 2021/11/23 07:23:38 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClassPhonebook.hpp"

/* Constructor */
Contact::Contact( void ) {
	return ;
}

/* Destructor */
Contact::~Contact( void ) {
	return ;
}

void	Contact::add( void ) {
	std::string	input;

	std::cout << "\t First name . . . . . ";
	std::getline(std::cin, input);
	_firstName = input;
	std::cout << "\t Last name  . . . . . ";
	std::getline(std::cin, input);
	_lastName = input;
	std::cout << "\t Nickname . . . . . . ";
	std::getline(std::cin, input);
	_nickName = input;
	std::cout << "\t Phone number . . . . ";
	std::getline(std::cin, input);
	_phoneNumber = input;
	std::cout << "\t Darkest secret . . . ";
	std::getline(std::cin, input);
	_darkestSecret = input;
	return ;
}

void	Contact::displayContactsList( int index ) {
	std::cout << std::endl;
	/* https://en.cppreference.com/w/cpp/io/manip/setfill */
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << index << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	_firstName.length() > 10 ? std::cout << _firstName.substr(0, 9) + '.'
										: std::cout << std::right << _firstName;
	std::cout << '|';
	std::cout << std::setfill(' ') << std::setw(10);
	_lastName.length() > 10 ? std::cout << _lastName.substr(0, 9) + '.'
										: std::cout << std::right << _lastName;
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	_nickName.length() > 10 ? std::cout << _nickName.substr(0, 9) + '.'
										: std::cout << std::right << _nickName;
	std::cout << "|";
	return ;
}

void	Contact::displayChosenContact( void ) {
	std::cout << std::endl;
	std::cout << "\t First name . . . . . " << _firstName << std::endl;
	std::cout << "\t Last name  . . . . . " << _lastName << std::endl;
	std::cout << "\t Nickname . . . . . . " << _nickName << std::endl;
	std::cout << "\t Phone number . . . . " << _phoneNumber << std::endl;
	std::cout << "\t Darkest secret . . . " << _darkestSecret << std::endl;
	return ;
}
