/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:39:52 by jfreitas          #+#    #+#             */
/*   Updated: 2022/04/08 15:18:22 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include <new>
#include <unistd.h>

#include "Weapon.hpp"

class HumanB {

	public:
		HumanB( std::string Bname );
		~HumanB( void );

		/* can not be a reference since its constructor does not have a way to
		 * initialize it using initializer list (in this case, it does not have
		 * a variable with the same type) */
		Weapon		*weaponB;
		std::string	name;

		/* here the parameter has to be passed by reference, if it was a
		 * pointer, then on the main the argument would have to be &arg, and
		 * the exercise passes a non pointer variable */
		void	setWeapon(Weapon& weapon);
		void	attack();
};


#endif
