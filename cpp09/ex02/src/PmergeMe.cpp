/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2023/06/03 14:39:09 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool PmergeMe::verbose = false;

PmergeMe::PmergeMe() {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Private Default constructor called" << std::endl;
    }
}

PmergeMe::PmergeMe(int argc, char** argv) {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Overloaded constructor called" << std::endl;
    }

    std::cout << "Before: ";
    // Storing input numbers in both containers
    for (int i = 1; i < argc; i++) {
        try {
            for(int j = 0; argv[i][j] != '\0'; j++) {
                if (argv[i][j] < '0' || argv[i][j] > '9') {
                    throw std::invalid_argument("Error: bad input. Please input positive integers in between spaces.");
                }
            }
            int number = atoi(argv[i]);
            if (number <= 0) {
                throw std::invalid_argument("Error: Please input positive integers in between spaces.");
            }

            // print input before it gets sorted:
            std::cout << argv[i] << " ";

            _vector.push_back(number);
            _list.push_back(number);
        } catch (const std::invalid_argument& ex) {
            throw ex;
        }
    }
    std::cout << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const & rhs)
    : _vector(rhs._vector), _list(rhs._list) {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Copy constructor called" << std::endl;
    }
}

PmergeMe& PmergeMe::operator=(PmergeMe const & rhs) {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Assignment operator called" << std::endl;
    }
    if (this != &rhs) {
        this->_vector = std::vector<int>(rhs._vector);
        this->_list = std::list<int>(rhs._list);
    }
    return *this;
}

PmergeMe::~PmergeMe() {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Destructor called" << std::endl;
    }
    // Display sorted sequence with vector
    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
