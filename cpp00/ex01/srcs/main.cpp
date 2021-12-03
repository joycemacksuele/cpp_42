/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:55:34 by jfreitas          #+#    #+#             */
/*   Updated: 2021/11/23 07:43:42 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClassPhonebook.hpp"

void	ft_print( std::string input ) { //could maybe use "case" here?
	if (input.compare("START") == 0) {
		std::cout << std::endl;
		std::cout << ". . . . PhoneBook . . . ." << std::endl;
	}
	else if (input.compare("LOOP") == 0) {
		std::cout << std::endl << "Commands accepted: ADD, SEARCH or EXIT: ";
	}
	else if (input.compare("ADD") == 0) {
		std::cout << std::endl;
		std::cout << "Fill in the new contact’s information please!" << std::endl;
		std::cout << std::endl;
	}
	else if (input.compare("SEARCH") == 0) {
		std::cout << std::endl;
		std::cout << "Input a contact's index number please: ";
	//	std::cout << std::endl;
	}
}

void	search(Contact instance[8], int index, std::string input) {
	std::string	indexInput;
	int indexNbr;

	std::cout << std::endl;
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "index" << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "First Name" << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "Last Name" << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "Nick Name" << "|";
	for (int i = 1; i < index; i++)
		instance[i].displayContactsList(i);
	std::cout << std::endl;
	ft_print(input);
	std::getline(std::cin, indexInput);
	indexNbr = std::atoi(indexInput.c_str());
	if ( indexNbr > 0 && indexNbr < index && indexNbr <= 8 )
		instance[indexNbr].displayChosenContact();
	else
		std::cout << std::endl << "Wrong contact index OR PhoneBook is empty!!!" << std::endl;
	return ;
}

//  SEARCH SEM contatos mostrar que Agenda esta vazia e acresentar replace oldest contact
int		main( void ) {
	Contact		instance[8];
	std::string	input;
	int			contact = 1;

	ft_print("START");
	while (1) {
		ft_print("LOOP");
		std::getline(std::cin, input);
		if (std::cin.eof() || input.compare("EXIT") == 0) {
			std::cout << std::endl << "Bye Bye!" << std::endl;
			exit(EXIT_SUCCESS);
		}
		if (input.compare("ADD") == 0) {
			if (contact == 9)
				std::cout << std::endl << "The PhoneBook is full!" << std::endl;
		//	else if (contact > 8)
		//		replace_oldest_contact();
			else {
				ft_print(input);
				instance[contact].add();
				contact++;
			}
		}
		else if (input.compare("SEARCH") == 0)
			search(instance, contact, input);
		else
			std::cout << std::endl << "Wrong command!!!" << std::endl;
	}
	return (0);
}
