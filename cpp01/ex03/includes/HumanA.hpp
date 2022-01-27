/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:39:52 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/20 11:25:39 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include <new>
#include <unistd.h>

#include "Weapon.hpp"

class HumanA {

	public:
		HumanA( std::string Aname, Weapon& weapon );
		~HumanA( void );

		/* can be a reference since its constructor have a way to unitialize it
		 * using initializer list (in this case, it has a var with the same type)*/
		Weapon&		weaponA;
		std::string	name;

		void	attack();
};

#endif
