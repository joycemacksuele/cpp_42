/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:26:51 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/08 17:33:32 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <whatever.hpp>

template <typename T>
void swap(T &arg1, T &arg2);

template <typename T>
const T min(T &arg1, T &arg2);

template <typename T>
const T max(T &arg1, T &arg2) {
	arg1 = arg2;
}
