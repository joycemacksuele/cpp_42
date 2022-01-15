/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:17 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/15 21:16:11 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

std::string	userInput( void ) {
	std::string	name;

	std::cout << std::endl << "Name your Zombie: " << GREEN;
	std::getline(std::cin, name);
	return name;
}

/*
 * Now the actual point of the exercise: your Zombies must be destroyed at
 * the appropriate time (when they are not needed anymore). They must be
 * allocated on the stack or the heap depending on its use: sometimes it’s
 * appropriate to have them on the stack, at other times the heap may a
 * better choice.
 */
int		main(void) {
	std::string	name;
	Zombie		*heapZombie;

	name = userInput();
	heapZombie = newZombie(name); /** malloc */
	std::cout << RESET << "Your heap Zombie announcement: ";
	heapZombie->announce();
	if (heapZombie->getWasAllocated() == 1){
		delete heapZombie; // delete call the destructor
	}

	name = userInput();
	std::cout << RESET << "Your stack Zombie announcement: ";
	randomChump(name);
	std::cout << std::endl;
	return 0;
}
