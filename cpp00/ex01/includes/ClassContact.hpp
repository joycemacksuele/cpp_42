/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:38:26 by jfreitas          #+#    #+#             */
/*   Updated: 2022/03/26 10:02:25 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONTACT_HPP
# define CLASS_CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Contact {

	public:
		Contact( void );
		~Contact( void );
	
		const std::string	getFirstName() const ;
		const std::string	getLastName() const ;
		const std::string	getNickName() const ;
		const std::string	getPhoneNumber() const ;
		const std::string	getDarkestSecret() const ;

		void		setFirstName( const std::string firstName );
		void		setLastName( const std::string lastName );
		void		setNickName( const std::string nickName );
		void		setPhoneNumber( const std::string phoneNumber );
		void		setDarkestSecret( const std::string darkestSecret );

	/* _varNmae -> convention to remember that this variable is private */
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif /* __CLASS_CONTACT_HPP__ */
