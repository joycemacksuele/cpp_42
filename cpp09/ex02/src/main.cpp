/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2023/06/02 14:39:09 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv) {
    if (argc < 2) {
        std::cout << RED << "Please input a positive integer sequence that can be sorted." << RESET << std::endl;
        return -1;
    }

    try {
        PmergeMe pMergeMe(argc, argv);

        //pMergeMe.verbose = true;
        //pMergeMe.std_lib = true;

        pMergeMe.mergeInsertVector();// ------------ Sort using a std::vector while measuring time
        pMergeMe.mergeInsertList();// -------------- Sort using a std::list while measuring time
    } catch (std::logic_error const& ex) {
        std::cout << RED << ex.what() << RESET << std::endl;
        return -1;
    }

    return 0;
}
