/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 03:30:47 by jfreitas          #+#    #+#             */
/*   Updated: 2021/10/25 20:11:42 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int		charIsLower(char c) {
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

void	toUpperIfLowerAndPrintAll(int argc, char **argv) {
	int		i = 1;
	size_t	j = 0;

	while (i < argc) {
		while (j < strlen(argv[i])) {
			if (charIsLower(argv[i][j]) == 1)
				std::cout << (argv[i][j] -= 32);
			else
				std::cout << argv[i][j];
			j++;
		}
		i++;
		j = 0;
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
