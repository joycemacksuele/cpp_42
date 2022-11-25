/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/25 15:16:31 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <MutantStack.hpp>
#include <list>

void	checkleaks(void) {
	system("echo '\033[1;36m'");
	system("leaks -q executable");
}

int main(int, char**) {
	std::cout << CLEAR_SCREEN;

/* ****************************************************************************/
	std::cout << BOLD << BLUE << std::endl << "---------------- My tests:\n" << RESET << std::endl;

	std::cout << std::endl;

/* ****************************************************************************/
	std::cout << BOLD << BLUE << "---------------- Codam tests:\n" << RESET << std::endl;

    MutantStack<int> mstack;
    std::list<int> lst;
	std::cout << std::endl;

    mstack.push(5);
    mstack.push(17);

    lst.push_back(5);
    lst.push_back(17);

    std::cout << "mstack.top(): " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << std::endl;

    std::cout << "lst.back(): " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "lst.size(): " << lst.size() << std::endl;
	std::cout << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();
    ++lst_it;
    --lst_it;

	std::cout << std::endl;
    int i = 0;
    while (it != ite)
    {
        //std::cout << *it << std::endl;
        std::cout << "mstack[" << i << "] = " << *it << std::endl;
        ++it;
        ++i;
    }
    std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << std::endl;

    i = 0;
    while (lst_it != lst_ite)
    {
        //std::cout << *lst_it << std::endl;
        std::cout << "lst[" << i << "] = " << *lst_it << std::endl;
        ++lst_it;
        ++i;
    }
    std::cout << "lst.size(): " << lst.size() << std::endl;
	std::cout << std::endl;

    std::stack<int> s(mstack);
    std::list<int> l(lst);
/* ****************************************************************************/

	atexit(checkleaks);
	return 0;
}
