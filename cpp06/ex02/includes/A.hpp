/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   A.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:08:27 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/07 20:29:56 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

#include <Base.hpp>

// Create a class A, that publicly inherit from Base.
struct A : public Base {
	public:
		virtual ~A(void);// Destructor
};

#endif
