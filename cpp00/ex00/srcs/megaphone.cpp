/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 03:30:47 by jfreitas          #+#    #+#             */
/*   Updated: 2022/03/26 09:33:35 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>// std::cout
#include <string>
#include <cctype>// std::toupper

/*
 * toupper's argument:
 * Like all other functions from <cctype>, the behavior of std::toupper is
 * undefined if the argument's value is neither representable as unsigned
 * char nor equal to EOF. To use these functions safely with plain chars
 * (or signed chars), the argument should first be converted to unsigned
 * char.
 */
void	toUpperIfLowerAndPrintAll(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		std::string	arg(argv[i]);
		for (size_t j = 0; j < arg.size(); j++) {
			std::cout << (char)std::toupper((unsigned char)arg[j]);
		}
	}
}

int		main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		toUpperIfLowerAndPrintAll(argc, argv);
	std::cout << std::endl;
	return (0);
}
