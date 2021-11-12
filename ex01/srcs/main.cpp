/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:55:34 by jfreitas          #+#    #+#             */
/*   Updated: 2021/10/25 22:30:55 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

// bundles together functions and/or variables that could have the same name
// as other functions and varibles inside it's program scope or inside any
// included library. i.e. defines a scope.
namespace	Index {
	int	contact = 1;

	void	func( void ) {
		//
	}
}

//void	add(Contact *instance) {
//}

void	search(Contact instance[8]) {
	(void)instance;
}


int		main( void ) {

	Contact		instance[8];
	std::string	input;

	while (1) {
		std::getline(std::cin, input);
		if (std::cin.eof() || !(input.compare("EXIT")))
			exit(EXIT_SUCCESS);
		else if (!(input.compare("ADD"))) {
			if (Index::contact == 8)
				std::cout << "The PhoneBook is full!" << std::endl;
			else {
				Index::contact++;
				instance[Index::contact].add();
			}
		}
		//	add(instance);
		else if (!(input.compare("SEARCH")))
			search(instance);
	}
	return (0);
}
