/* ************************************************************************** */
/*                                                                            */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:11 by jfreitas          #+#    #+#             */
/*   Updated: 2022/01/07 12:38:08 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include "../includes/Weapon.hpp"

// HumanA takes the Weapon in its constructor.
HumanA::HumanA( std::string Aname, Weapon weapon) {
	this->weaponA = &weapon;
	this->name = Aname;
	return ;
}

HumanA::~HumanA(void) {
	return ;
}

void	HumanA::attack() {
	std::cout << GREEN << this->name << RESET << " attacks with " << YELLOW << weaponA->getType() << std::endl;
}
