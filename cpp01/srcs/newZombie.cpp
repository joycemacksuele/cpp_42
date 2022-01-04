/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:32:28 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/04 23:03:05 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/*
 * create a Zombie, name it, and return it to be used somewhere else in your 
 * code 
 * On heap in this case.
 */
Zombie* newZombie( std::string name ) {
	Zombie* heapZombie;

	try {
		heapZombie = new Zombie;
		heapZombie->setWasAllocated(1);
	}
	catch (std::bad_alloc& ba) {
		std::cerr << ba.what() << std::endl;
		return NULL;
	}
	heapZombie->setName(name);
	return heapZombie;
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
