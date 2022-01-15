/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:39:52 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/15 20:49:23 by jfreitas         ###   ########.fr       */
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
		HumanA( std::string Aname, Weapon weapon );
		~HumanA( void );

		Weapon		weaponA;
		std::string	name;

		void	attack();
};

#endif
