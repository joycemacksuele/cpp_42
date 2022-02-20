/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:32:28 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/20 18:39:58 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/*
 * It allocates N Zombie objects in a single allocation. Then, it should
 * initialize each Zombie by giving to each one a name.
 * It should return the pointer to the first Zombie.
 * On heap in this case (malloc->new).
 */
Zombie* zombieHorde( int N, std::string name ) {
	Zombie	*heapZombie;

	try {
		heapZombie = new Zombie[N];
	}
	catch (std::bad_alloc& ba) {
		std::cerr << ba.what() << std::endl;
		return NULL;
	}
	heapZombie[0].setName(name);
	for (int i = 1; i < N; i++) {
		name = userInputName(i + 1);
		heapZombie[i].setName(name);
	}
	return &heapZombie[0];
}

/*
 * Try/Catch Exceptions:
 *
 * - Try blocks are used to enclose statements that may return an exception.
 *   - These blocks need to be followed up by one or more catch blocks.
 *
 * - A catch block specifies the type of exception it can handle and allows
 *   you to define the code executed when the error occurs.
 */
