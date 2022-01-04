/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:39:52 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/04 22:47:22 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Zombie {

	public:
		Zombie( void );
		~Zombie( void );

		bool wasAllocated;
		bool		getWasAllocated() const;
		void		setWasAllocated( bool allocated );

		std::string	getName() const ;
		void		setName( std::string name );

		void		announce( void );

	/* _varNmae -> convention to remember that this variable is private */
	private:
		std::string _ZombieName;

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
