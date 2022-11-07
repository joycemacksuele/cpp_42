/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   C.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:08:27 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/07 20:33:48 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

#include <Base.hpp>

// Create a class C, that publicly inherit from Base.
struct C : public Base {
	public:
		virtual ~C(void);// Destructor
};

#endif
