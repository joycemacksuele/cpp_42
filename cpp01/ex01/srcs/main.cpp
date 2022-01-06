/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:17 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/06 22:33:38 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

std::string	userInputAmount() {
	std::string	amount;

	std::cout << RESET  << "Amount of Zombies to be dinamically allocated ";
	std::cout << "(from 1 to 20) : ";
	std::getline(std::cin, amount);
	std::cout << std::endl;
	return amount;
}

std::string	userInputName( int i ) {
	std::string	name;

	std::cout << RESET  << "Name your Zombie number " << i;
	std::cout<< ": " << GREEN;
	std::getline(std::cin, name);
	return name;
}

void	zombieLife(int nbZombies) {
	std::string	name;
	Zombie		*heapZombie;
	int			i;

	i = 0;
	name = userInputName(i + 1);
	heapZombie = zombieHorde(nbZombies, name); /** malloc nbZombies times*/
	while (i < nbZombies) {
		std::cout << std::endl;
		sleep(1);
		std::cout << RESET << "Your heap Zombie " << GREEN << i + 1;
		std::cout << RESET << " announcement: ";
		heapZombie[i].announce();
		i++;
	}
	std::cout << std::endl;
	sleep(2);
	delete [] heapZombie; // delete calls the destructor
	std::cout << std::endl << std::endl;
}

bool	isDigit(std::string amount) {
	int i;

	i = 0;
	while (amount[i]) {
		if (amount[i] < '1' || amount[i] > '9')
			return false;
		i++;
	}
	return true;
}

int	inputAmountChecker() {
	int			nbZombies;
	std::string	amount;

	std::cout << std::endl;
	while (1) {
		amount = userInputAmount();
		if (isDigit(amount) == false) {
			std::cout << YELLOW << "Not a number!" RESET << std::endl << std::endl;
			continue ;
		}
		else
			nbZombies = std::stol(amount);
		if (nbZombies <= 0 || nbZombies > 20)
			std::cout << YELLOW << "Wrong amount!" RESET << std::endl << std::endl;
		else
			break ;
	}
	return nbZombies;
}

/*
 * Submit a main to test that your function zombieHorde works as intended.
 * You may want to do so by calling announce() on each one of the Zombies.
 * Do not forget to delete ALL the Zombies when you don’t need them anymore.
 */
int		main(void) {
	int			nbZombies;

	nbZombies = inputAmountChecker();
	zombieLife(nbZombies);
	return 0;
}
