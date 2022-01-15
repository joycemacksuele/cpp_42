/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:17 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/15 20:15:31 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

bool	isDigit(std::string amount) {
	int i;

	i = 0;
	while (amount[i]) {
		if (amount[i] < '0' || amount[i] > '9')
			return false;
		i++;
	}
	return true;
}
/*
void	fight(std::string Aname, std::string Bname, HumanA *A, HumanB *B) {
	std::string	input;

	std::cout << std::endl;
	std::cout << RESET << "Who will start the fight: " << GREEN << Bname << RESET << " or " << GREEN << Aname << RESET << " ? " << GREEN;
	std::getline(std::cin, input);
	std::cout << std::endl;
	if (std::strcmp(input.c_str(), Aname.c_str()) == 0 && !B->weaponB.getType().empty()) {
		A->attack();
		B->attack();
	}
	else {
		if (B->weaponB.getType().empty()) {
			std::cout << GREEN << Bname << RESET << " has no weapon. ";
			std::cout << GREEN << Aname << RESET << " wins!" << std::endl << std::endl;
			return ;
		}
		B->attack();
		A->attack();
	}

	std::cout << std::endl;
	std::cout << Bname << RESET << " = " << B->weaponB.weaponRank << YELLOW << " vs ";
	std::cout << GREEN << Aname << RESET << " = " << A->weaponA.weaponRank << std::endl;
	if (A->weaponA.weaponRank == B->weaponB.weaponRank) 
		std::cout << "It's a tie!" << std::endl;
	else if (A->weaponA.weaponRank > B->weaponB.weaponRank)
		std::cout << GREEN << Aname << RESET << " wins!" << std::endl;
	else
		std::cout << GREEN << Bname << RESET << " wins!" << std::endl;
	std::cout << std::endl;
}

std::string	chooseXP(std::string name) {
	std::string	xp;

	while (1) {
		std::cout << RESET << "Choose a XP for " << GREEN << name << RESET << "'s weapon: " << GREEN;
		std::getline(std::cin, xp);
		if (isDigit(xp) == false) {
			std::cout << YELLOW << "Not a valid number!" RESET << std::endl;
			continue ;
		}
		else
			return xp;
	}
}

ioid	humanaAinit_and_fight(HumanB *B, std::string Bname) {
	std::string	Aname;
	std::string	weaponA;
	std::string	xp;

	std::cout << std::endl;
	std::cout << RESET << "Chose a name for the second human: " << GREEN;
	std::getline(std::cin, Aname);
	std::cout << RESET << "Chose a weapon for " << GREEN << Aname << RESET << ": " YELLOW;
	std::getline(std::cin, weaponA);
	std::cout << GREEN << Aname << RESET << " will fight with this " << YELLOW << weaponA << RESET <<  " weapon!" << std::endl;

	HumanA	A(weaponA);
	A.name = Aname;
	xp = chooseXP(Aname);
	A.weaponA.weaponRank = std::stoi(xp);
	fight(Aname, Bname, &A, B);
}

std::string	humanBinit(HumanB *B) {
	std::string	Bname;
	std::string	weaponB;
	std::string	input;
	std::string	xp;

	std::cout << std::endl;
	std::cout << RESET << "Chose a name for the first human: " << GREEN;
	std::getline(std::cin, Bname);
	B->name = Bname;
	std::cout << RESET << "Chose a weapon for " << GREEN << Bname << RESET << ": " YELLOW;
	std::getline(std::cin, weaponB);
	std::cout << GREEN << Bname << RESET << " will fight with this " << YELLOW << weaponB << RESET <<  " weapon? yes or no: " << GREEN;
	std::getline(std::cin, input);
	if (std::strcmp(input.c_str(), "yes") == 0) {
		xp = chooseXP(Bname);
		B->weaponB.weaponRank = std::stoi(xp);
		B->weaponB.setType(weaponB);
	}
	return Bname;
}
*/
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
	//Bname = humanBinit(&B);
	//humanaAinit_and_fight(&B, Bname);

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
		std::cout << RESET << "Chose a name for the second  human: " << GREEN;
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
