/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/01 11:57:43 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <unistd.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class ClapTrap {

	public:
		ClapTrap(void);// Default (no args) constructor

		ClapTrap(const std::string name);// Overloaded constructor (with one param)

		ClapTrap(const ClapTrap& src);// Overloaded Copy constructor
		ClapTrap& operator=(const ClapTrap& rhs);// Copy assignment operator
		// Important to return a reference to the class since we don't want a deep copy). ex: s2 = s1 is actually s2.operator=(s1);
		/* - Good to know: Move assignment operator is like the Copy one but the parameter
		 *   is a non const (since we will change it by null-ing it) r-value reference (aka ClassName&& rhs).
		 * - Move operator will make the current instance point to the value the rhs is pointing to,
		 *   then null the rhs pointer (so rhs pointer is lost/not accessible anymore).
		 * - Copy operator will delete what is inside the current instance, allocate a new
		 *   necessary space to it and copy what is inside the rhs to this memory just allocated
		 *   on the current instance (so the rhs pointer is still accessibe and still with the value
		 *   it had before (aka: now we have 2 addresses with the sam evalue in it)).
		 */
		~ClapTrap(void);// Destructor

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// getters
		std::string		get_name() const;
		int				get_hitPoints() const;
		int				get_energyPoints() const;
		unsigned int	get_attackDamage() const;
		// setters
		void set_name(std::string name);
		void set_hitPoints(int hitPoints);
		void set_energyPoints(int energyPoints);
		void set_attackDamage(unsigned int attackDamage);

	/* _varNmae -> convention to remember that this variable is private */
	private:
		std::string		_name;
		int				_hitPoints;// represent the health of the ClapTrap.
		int				_energyPoints;//Attacking and repairing cost 1 energy point each.
		unsigned int	_attackDamage;// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
		std::string		_targetName;

};

#endif
