/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 03:30:47 by jfreitas          #+#    #+#             */
/*   Updated: 2022/03/05 13:38:07 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>// std::cout
#include <string.h>// strlen <cstring>
#include <cctype>// toupper

void	toUpperIfLowerAndPrintAll(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		std::string	arg(argv[i]);
		for (size_t j = 0; j < strlen(arg.c_str()); j++) {
			std::cout << (unsigned char)toupper(arg[j]);
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
