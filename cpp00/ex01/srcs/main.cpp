/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:55:34 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/20 18:07:11 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClassPhonebook.hpp"

enum Print {top, bottom};

void	ft_print(std::string input) {
	if (input.compare("START") == 0) {
		std::cout << std::endl;
		std::cout << BLUE << ". . . . PhoneBook . . . ." << RESET << std::endl;
	}
	else if (input.compare("LOOP") == 0) {
		std::cout << std::endl << "Commands accepted: ADD, SEARCH or EXIT: ";
	}
	else if (input.compare("ADD") == 0) {
		std::cout << std::endl << BLUE;
		std::cout << "Fill in the new contact’s information please!" << std::endl;
		std::cout << RESET << std::endl;
	}
	else if (input.compare("SEARCH") == 0) {
		std::cout << std::endl << BLUE;
		std::cout << "Input a contact's index number please: " << RESET;
	}
}

void print_search_table(Print print_enum) {
	if (print_enum == top) {
		std::cout << std::endl;
		std::cout << "         ┌──────────┬──────────┬──────────┬──────────┐";
		std::cout << std::endl << "         │";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << "index" << "│";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << "First Name" << "│";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << "Last Name" << "│";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << "Nick Name" << "│" << std::endl;
		std::cout << "         ├──────────┼──────────┼──────────┼──────────┤";
	}
	if (print_enum == bottom) {
		std::cout << std::endl;
		std::cout << "         └──────────┴──────────┴──────────┴──────────┘";
	}
}

void	search(Phonebook instance[8], int index, std::string input) {
	std::string	indexInput;
	int			indexNbr;

	print_search_table(top);
	for (int i = 0; i < index; i++)
		instance[i].displayContactsList(i + 1);
	print_search_table(bottom);
	std::cout << std::endl;
	ft_print(input);
	std::getline(std::cin, indexInput);
	indexNbr = std::atoi(indexInput.c_str());
	if ( indexNbr > 0 && indexNbr - 1 < index && indexNbr <= 8 )
		instance[indexNbr - 1].displayChosenContact();
	else {
		std::cout << std::endl << YELLOW;
		std::cout << "Wrong contact index or PhoneBook is empty!!!";
		std::cout << RESET << std::endl;
	}
	return ;
}

void	searchContact(std::string input, Phonebook instance[8], int contact) {
	if (contact == 0) {
		std::cout << std::endl << YELLOW;
		std::cout << "PhoneBook is empty!!!" << RESET << std::endl;
	}
	else {
		search(instance, contact, input);
	}
}

int	addContact(std::string input, Phonebook instance[8], int contact) {
	ft_print(input);
	if (contact == 8) {
		instance[7].add();
	}
	else {
		if (instance[contact].add() == 0) {
			contact++;
		}
	}
	return contact;
}

int		main(void) {
	Phonebook	instance[8];
	std::string	input;
	int			contact = 0;

	ft_print("START");
	while (1) {
		ft_print("LOOP");
		std::getline(std::cin, input);
		if (std::cin.eof() || input.compare("EXIT") == 0) {
			std::cout << BLUE << std::endl << "Bye Bye!" << RESET << std::endl;
			std::cout << std::endl;
			return 0;
			//exit(EXIT_SUCCESS); -> No destructors are called if program exits
		}
		if (input.compare("ADD") == 0)
			contact = addContact(input, instance, contact);
		else if (input.compare("SEARCH") == 0)
			searchContact(input, instance, contact);
		else {
			std::cout << std::endl << RED;
			std::cout << "Wrong command!!!" << RESET << std::endl;
		}
	}
	return 0;
}
