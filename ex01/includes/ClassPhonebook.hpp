/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:06:31 by jfreitas          #+#    #+#             */
/*   Updated: 2021/11/23 07:41:37 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Contact {

	public:
		Contact( void );
		~Contact( void );

		void	add( void );
		void	displayChosenContact( void );
		void	displayContactsList( int index );


	/* _varNmae -> convention to remember that this variable is private */
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif /* __CLASS_PHONEBOOK_HPP__ */
