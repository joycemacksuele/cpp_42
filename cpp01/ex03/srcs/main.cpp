/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:17 by jfreitas          #+#    #+#             */
/*   Updated: 2022/02/20 19:36:45 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

/*
 * HumanB may not always have a Weapon, but HumanA will ALWAYS be armed.
 *
 * - Pointer:
 *   - has its own memory address and size on the stack.
 *   - can be assigned NULL directly.
 *   - pointers to pointers is ok.
 *   - pointers arithmetic is ok.
 * - Reference:
 *   - shares the same memory address (with the original variable).
 *   - also takes up some space on the stack.
 *   - can not be assigned NULL directly.
 *   - reference to reference in not ok (references only offer one level of
 *     indirection).
 *   - reference Arithmetic is not ok (unless the address of an object pointed
 *     by a reference is used as in &obj + 5).
 */
int		main(void) {
	std::cout << std::endl;

	{
		std::string	Aname;
		Weapon	club = Weapon("crude spiked club");
		std::cout  << RESET << "Chose a name for the first human: " << GREEN;
		std::getline(std::cin, Aname);
		HumanA	A(Aname, club);
		A.attack();
		club.setType("some other type of club");
		A.attack();
	}
	std::cout << std::endl;
	{
		std::string	Bname;
		Weapon	club = Weapon("crude spiked club");
		std::cout << RESET << "Chose a name for the second human: " << GREEN;
		std::getline(std::cin, Bname);
		HumanB	B(Bname);
		B.setWeapon(club);
		B.attack();
		club.setType("some other type of club");
		B.attack();
	}

	std::cout << std::endl;
	return 0;
}
