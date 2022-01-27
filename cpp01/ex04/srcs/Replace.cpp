/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:11 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/21 11:30:21 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

Replace::Replace(const std::string &s1, const std::string &s2) {
	return ;
}

Replace::~Replace(void) {
	return ;
}

const std::string&	Replace::getType() {
	return this->type;
}

void	Replace::setType(std::string typeVar) {
	this->type = typeVar;
}
