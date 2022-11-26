/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:23:39 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/26 14:52:14 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <MutantStack.hpp>
#include <list>

void	checkleaks(void) {
	system("echo '\033[1;36m'");
	system("leaks -q executable");
}

static void printStack(std::stack<int> s) {
	int i = 0;
	std::stack<int> temp;

	// stack s:
	// 0
	// 737
	// 5
	// 3
	// 5

	while (s.empty() == false) {
		temp.push(s.top());//inserts the top of s at the top of temp
		s.pop();//removes the top element of s
	}

	// stack temp:
	// 5
	// 3
	// 5
	// 737
	// 0

	while (temp.empty() == false) {
		std::cout << "s[" << i << "] = " << temp.top() << std::endl;
		++i;
		temp.pop();//removes the top element of temp
	}
}

int main(int, char**) {
	std::cout << CLEAR_SCREEN << std::endl;

	MutantStack<int> mstack;
	std::list<int> lst;
	std::cout << std::endl;

	mstack.push(5);//inserts element at the top
	mstack.push(17);

	lst.push_back(5);//adds an element to the end
	lst.push_back(17);

	// mstack or lst are now:
	// 17
	// 5

	std::cout << "mstack.top(): " << mstack.top() << std::endl;//accesses the top element
	mstack.pop();//removes the top element
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << "lst.back(): " << lst.back() << std::endl;//access the last element
	lst.pop_back();//removes the last element
	std::cout << "lst.size(): " << lst.size() << std::endl;
	std::cout << std::endl;

	// mstack or lst are now:
	// 5

	mstack.push(3);//inserts element at the top
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	lst.push_back(3);//adds an element to the end
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);

	// mstack or lst are now:
	// 5
	// 3
	// 5
	// 737
	// 0

	MutantStack<int>::iterator it = mstack.begin();//returns an iterator to the beginning
	MutantStack<int>::iterator ite = mstack.end();//returns an iterator to the end
	++it;
	--it;

	std::list<int>::iterator lst_it = lst.begin();//returns an iterator to the beginning
	std::list<int>::iterator lst_ite = lst.end();//returns an iterator to the end
	++lst_it;
	--lst_it;

	std::cout << std::endl;
	int i = 0;
	while (it != ite)
	{
		std::cout << "mstack[" << i << "] = " << *it << std::endl;
		++it;
		++i;
	}
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << std::endl;

	i = 0;
	while (lst_it != lst_ite)
	{
		std::cout << "lst[" << i << "] = " << *lst_it << std::endl;
		++lst_it;
		++i;
	}
	std::cout << "lst.size(): " << lst.size() << std::endl;
	std::cout << std::endl;

	std::cout << BLUE << "Making a copy of 'mstack' to 's' and 'lst' to 'l':" << RESET <<std::endl;
	std::cout << std::endl;
	std::stack<int> s(mstack);
	std::list<int> l(lst);

	//it = s.begin();//error: no member begin on stack
	//ite = s.end();//error: no member begin on stack
	printStack(s);
	lst_it = lst.begin();
	lst_ite = lst.end();
	i = 0;
	std::cout << std::endl;
	while (lst_it != lst_ite)
	{
		std::cout << "l[" << i << "] = " << *lst_it << std::endl;
		++lst_it;
		++i;
	}
	std::cout << std::endl;

	atexit(checkleaks);
	return 0;
}
