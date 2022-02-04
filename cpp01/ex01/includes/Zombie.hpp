/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:39:52 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/04 15:59:40 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>
#include <unistd.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Zombie {

	public:
		Zombie( void );
		~Zombie( void );

		int	amount;

		std::string	getName() const ;
		void		setName( std::string name );

		void		announce( void );


	/* _varNmae -> convention to remember that this variable is private */
	private:
		std::string _ZombieName;

};

Zombie*		zombieHorde( int N, std::string name );
std::string	userInputName( int i );

#endif
