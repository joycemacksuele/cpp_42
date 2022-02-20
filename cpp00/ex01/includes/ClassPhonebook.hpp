/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:38:26 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/20 17:44:01 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#include "ClassContact.hpp"

class Phonebook {

	public:
		Phonebook( void );
		~Phonebook( void );

		int		add( void);
		void	displayChosenContact( void );
		void	displayContactsList( int index );
		int	checkIfEmpty();

	/* _varNmae -> convention to remember that this variable is private */
	private:
		Contact _contact;
};

#endif /* __CLASS_PHONEBOOK_HPP__ */
