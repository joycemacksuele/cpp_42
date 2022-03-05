/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:38:26 by jfreitas          #+#    #+#             */
/*   Updated: 2022/03/05 11:49:26 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>// I/O manipulation flags/methods
//#include <cstdlib>// to use exit();

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

		int		addContact( int index );
		int		add( int index );
		void	displayChosenContact( int index );
		void	displayContactsList( int index );
		int		checkIfEmpty( int index );

	/* _varNmae -> convention to remember that this variable is private */
	private:
		Contact _contact[8];
};

#endif /* __CLASS_PHONEBOOK_HPP__ */
