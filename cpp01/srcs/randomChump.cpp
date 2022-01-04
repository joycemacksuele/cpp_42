/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:34:14 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/04 23:02:36 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/*
 * create a Zombie and make it announce itself.
 * On stack in this case.
 */
void randomChump( std::string name ) {
	Zombie	stackZombie;
	stackZombie.setWasAllocated(0);
	stackZombie.setName(name);
	stackZombie.announce();
}
