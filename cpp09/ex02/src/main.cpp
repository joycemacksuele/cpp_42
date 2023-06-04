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
#include <vector>
#include <list>
#include <iostream>


int main (int argc, char **argv) {

    if (argc < 2) {
        std::cout << RED << "Please input a positive integer sequence that can be sorted." << RESET << std::endl;
        return -1;
    }

    int vector_size = 0;
    int list_size = 0;

    try {
        PmergeMe pMergeMe(argc, argv);
        vector_size = pMergeMe.getContainerSize<std::vector<int> >();
        list_size = pMergeMe.getContainerSize<std::list<int> >();

        std::clock_t start_clock;

        // --------------------------------  Sort using a std::vector while measuring time
        start_clock = std::clock();
        pMergeMe.mergeInsert<std::vector<int> >(0, vector_size - 1);
        // std::sort(vec.begin(), vec.end());
        // trying with algos from the std lib
        std::clock_t end_vec = std::clock();
        double elapsed_time_vector = static_cast<double>(end_vec - start_clock) / CLOCKS_PER_SEC * 1000000;
        // Display time to process (sort) the vector:
        std::cout << "Time to process a range of " << vector_size << " elements with std::vector: " << elapsed_time_vector << " us" << std::endl;

        // -------------------------------- Sort using a std::list while measuring time
        start_clock = std::clock();
        pMergeMe.mergeInsert<std::list<int> >(0, list_size - 1);
        // trying with algos from the std lib
        // std::sort(_list.begin(), _list.end());
        // _list.sort()
        std::clock_t end_lst = std::clock();
        double elapsed_time_list = static_cast<double>(end_lst - start_clock) / CLOCKS_PER_SEC * 1000000;
        // Display time to process (sort) the list:
        std::cout << "Time to process a range of " << list_size << " elements with std::list: " << elapsed_time_list << " us" << std::endl;

    } catch (std::logic_error const& ex) {
        std::cout << RED << ex.what() << RESET << std::endl;
        return -1;
    }
    return 0;
}
