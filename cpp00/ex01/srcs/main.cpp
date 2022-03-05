/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:55:34 by jfreitas          #+#    #+#             */
/*   Updated: 2022/03/05 12:44:13 by jfreitas      ########   odam.nl         */
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
	else if (input.compare("EXIT") == 0) {
		std::cout << BLUE << std::endl << "Bye Bye!" << RESET << std::endl;
		std::cout << std::endl;
	}
	else if (input.compare("EMPTY") == 0) {
		std::cout << std::endl << YELLOW;
		std::cout << "PhoneBook is empty!!!" << RESET << std::endl;
	}
	else if (input.compare("INDEX") == 0) {
		std::cout << std::endl << YELLOW;
		std::cout << "Wrong contact index or PhoneBook is empty!!!";
		std::cout << RESET << std::endl;
	}
	else if (input.compare("WRONG") == 0) {
		std::cout << std::endl << RED;
		std::cout << "Wrong command!!!" << RESET << std::endl;
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

int	chooseContact(int contactIndex, std::string input) {
	std::string	indexInput;
	int			indexNbr;

	std::cout << std::endl;
	ft_print(input);
	std::getline(std::cin, indexInput);
	indexNbr = std::atoi(indexInput.c_str());
	if ( indexNbr > 0 && indexNbr - 1 < contactIndex && indexNbr <= 8 )
		return indexNbr;
	else {
		ft_print("INDEX");
	}
	return 0;
}

int		main(void) {
	Phonebook	instance;
	std::string	input;
	int			contactIndex = 0;
	int			indexNbr = 0;

	ft_print("START");
	while (1) {
		ft_print("LOOP");
		//std::cin >> input;
		std::getline(std::cin, input);
		if (std::cin.eof() || input.compare("EXIT") == 0) {// input == "EXIT" also works (operator overload)
			ft_print("EXIT");
			return 0;// exit(EXIT_SUCCESS); -> No destructors are called if program exits
		}
		if (input.compare("ADD") == 0) {
			ft_print(input);
			contactIndex = instance.addContact(contactIndex);
		}
		else if (input.compare("SEARCH") == 0)  {
			if (contactIndex == 0) {
				ft_print("EMPTY");
			} else {
				print_search_table(top);
				instance.displayContactsList(contactIndex);
				print_search_table(bottom);
				indexNbr = chooseContact(contactIndex, input);
				if (indexNbr != 0)
					instance.displayChosenContact(indexNbr - 1);
			}
		}
		else
			ft_print("WRONG");
	}
	return 0;
}
