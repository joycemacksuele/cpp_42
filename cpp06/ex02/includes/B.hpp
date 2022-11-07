/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   B.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:08:27 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/07 20:33:53 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

#include <Base.hpp>

// Create a class B, that publicly inherit from Base.
struct B : public Base {
	public:
		virtual ~B(void);// Destructor
};

#endif
