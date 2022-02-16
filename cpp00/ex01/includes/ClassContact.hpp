/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:38:26 by jfreitas          #+#    #+#             */
/*   Updated: 2021/12/17 14:19:30 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONTACT_HPP
# define CLASS_CONTACT_HPP

class Contact {

	public:
		Contact( void );
		~Contact( void );
	
		std::string	getFirstName() const ;
		std::string	getLastName() const ;
		std::string	getNickName() const ;
		std::string	getPhoneNumber() const ;
		std::string	getDarkestSecret() const ;
	
		void		setFirstName( std::string firstName );
		void		setLastName( std::string lastName );
		void		setNickName( std::string nickName );
		void		setPhoneNumber( std::string phoneNumber );
		void		setDarkestSecret( std::string darkestSecret );

	/* _varNmae -> convention to remember that this variable is private */
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif /* __CLASS_CONTACT_HPP__ */
