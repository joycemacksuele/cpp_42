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
bool PmergeMe::std_lib = false;

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

    for(int j = 0; argv[1][j] != '\0'; j++) {
        if (argv[1][j] < '0' || argv[1][j] > '9') {
            throw std::invalid_argument("Error: bad input. Please input positive integers in between spaces.");
        }
    }

    std::cout << "Before: ";
    // Storing input numbers in both containers
    for (int i = 1; i < argc; i++) {
        try {
            int number = atoi(argv[i]);

            // print input before it gets sorted:
            std::cout << argv[i] << " ";

            _vector.push_back(number);
            _list.push_back(number);
        } catch (const std::invalid_argument& ex) {
            throw ex;
        }
    }
    std::cout << std::endl;
    // Setting the size of the chunks to be sorted before merging them (it will be valid for both vector and list).
    // Getting a good division of the container where each chunk won't have more than 25 numbers:
    setChunckSize(_vector.size());

    std::vector<int> temp_vector = _vector;
    std::sort(temp_vector.begin(), temp_vector.end());
    // Display sorted sequence with vector
    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = temp_vector.begin(); it != temp_vector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
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
}

void PmergeMe::mergeInsertVector() {
    std::clock_t start_clock = std::clock();
    int vector_size = _vector.size();

    if (std_lib) {
        std::cout << BLUE << "std::vector: Trying with std::sort():" << RESET << std::endl;
        std::sort(_vector.begin(), _vector.end());
    } else {
        mergeInsertVector(0, vector_size - 1);
    }

    std::clock_t end_vector = std::clock();
    // Display time to process (sort) the vector in millisecond:
    std::cout << std::flush;
    std::cout << "Time to process a range of " << vector_size << " elements with std::vector: ";
    std::cout << std::fixed << std::setprecision(5) << (1000.0 * (end_vector - start_clock) / CLOCKS_PER_SEC) << " ms" << std::endl;
}

void PmergeMe::mergeInsertList() {
    std::clock_t start_clock = std::clock();
    int list_size = _list.size();

    if (std_lib) {
        std::cout << BLUE << "std::list: Trying with .sort():" << RESET << std::endl;
        _list.sort();
    } else {
        mergeInsertList(0, list_size - 1);
    }

    std::clock_t end_list = std::clock();
    // Display time to process (sort) the list in millisecond:
    // (https://stackoverflow.com/questions/331889/c-sorting-a-vector-or-linked-list)
    std::cout << std::flush;
    std::cout << "Time to process a range of " << list_size << " elements with std::vector: ";
    std::cout << std::fixed << std::setprecision(5) << (1000.0 * (end_list - start_clock) / CLOCKS_PER_SEC) << " ms" << std::endl;
}

/************************** private member methods ****************************/

void PmergeMe::mergeInsertVector(int start, int end) {
    if (verbose) {
        std::cout << "insertionSort with a std::vector" << std::endl;
    }

    // If current container size is smaller or equal than the chunk_size, use insertion sort
    if (end - start <= _chunk_size) {
        insertionSortVector(start, end);
    } else {
        int middle = (start + end) / 2;

        // In Merge sort we split the given array (or a chunk of it) in two parts and
        // sort them individually (using the insertion sort) -> unless the array or chunk is
        // already small enough, then only insertion sort is faster:
        mergeInsertVector(start, middle);
        mergeInsertVector(middle + 1, end);

        // Then we merge the both sorted halves (it is based on divide and conquer algorithm):
        mergeVector(start, middle, end);
    }
}

void PmergeMe::mergeInsertList(int start, int end) {
    if (verbose) {
        std::cout << "insertionSort with a std::list" << std::endl;
    }

    // If current container size is smaller or equal than the chunk_size, use insertion sort
    if (end - start <= _chunk_size) {
        insertionSortList(start, end);
    } else {
        int middle = (start + end) / 2;

        // In Merge sort we split the given array (or a chunk of it) in two parts and
        // sort them individually (using the insertion sort) -> unless the array or chunk is
        // already small enough, then only insertion sort is faster:
        mergeInsertList(start, middle);
        mergeInsertList(middle + 1, end);

        // Then we merge the both sorted halves (it is based on divide and conquer algorithm):
        mergeList(start, middle, end);
    }
}

void PmergeMe::setChunckSize(int size) {
    _chunk_size = size / 2;
    while (1) {
        if (_chunk_size > 25) {
            _chunk_size = _chunk_size / 2;
        } else {
            break;
        }
    }
}

void PmergeMe::insertionSortVector(int start, int middle) {
    for (int i = start; i < middle; i++) {
        // Get the value at index (i + 1)
        int temp_number_next = _vector[i + 1];

        int j = i + 1;
        // Shift elements to the right to make space for the current element
        while (j > start && _vector[j] && _vector[j - 1] > temp_number_next) {
            _vector[j] = _vector[j - 1];
            j--;
        }
        _vector[j] = temp_number_next;
    }
}

void PmergeMe::insertionSortList(int start, int middle) {
    for (int i = start; i < middle; i++) {
        // Get the value at index (i + 1)
        int temp_number_next = *std::next(_list.begin(), i + 1);

        int j = i + 1;
        // Shift elements to the right to make space for the current element
        while (j > start && *std::next(_list.begin(), j - 1) > temp_number_next) {
            *std::next(_list.begin(), j) = *std::next(_list.begin(), j - 1);
            j--;
        }
        *std::next(_list.begin(), j) = temp_number_next;
    }
}

void PmergeMe::mergeVector(int start, int middle, int end) {
    int number1_index = middle - start + 1;
    int number2_index = end - middle;
    std::vector<int> left_chunck(number1_index);
    std::vector<int> right_chunk(number2_index);

    // Copy elements from the left sublist to left_chunck
    for (int i = 0; i < number1_index; i++) {
        left_chunck[i] = _vector[start + i];
    }
    // Copy elements from the right sublist to right_chunk
    for (int i = 0; i < number2_index; i++) {
        right_chunk[i] = _vector[middle + 1 + i];
    }

    int left_index = 0;
    int right_index = 0;
    // Merge left_chunck and right_chunk into the container
    for (int i = start; i <= end; i++) {
        if (right_index == number2_index) {
            _vector[i] = left_chunck[left_index];
            left_index++;
        } else if (left_index == number1_index) {
            _vector[i] = right_chunk[right_index];
            right_index++;
        } else if (right_chunk[right_index] > left_chunck[left_index]) {
            _vector[i] = left_chunck[left_index];
            left_index++;
        } else {
            _vector[i] = right_chunk[right_index];
            right_index++;
        }
    }
}

void PmergeMe::mergeList(int start, int middle, int end) {
    int number1_index = middle - start + 1;
    int number2_index = end - middle;
    std::list<int> left_chunck;
    std::list<int> right_chunk;

    // Copy elements from the left sublist to left_chunck
    for (int i = 0; i < number1_index; i++) {
        left_chunck.push_back(*std::next(_list.begin(), start + i));
    }
    // Copy elements from the right sublist to right_chunk
    for (int i = 0; i < number2_index; i++) {
        right_chunk.push_back(*std::next(_list.begin(), middle + 1 + i));
    }

    int left_index = 0;
    int right_index = 0;
    // Merge left_chunck and right_chunk into the container
    for (int i = start; i <= end; i++) {
        if (right_index == number2_index) {
            *std::next(_list.begin(), i) = left_chunck.front();
            left_chunck.pop_front();
            left_index++;
        } else if (left_index == number1_index) {
            *std::next(_list.begin(), i) = right_chunk.front();
            right_chunk.pop_front();
            right_index++;
        } else if (right_chunk.front() > left_chunck.front()) {
            *std::next(_list.begin(), i) = left_chunck.front();
            left_chunck.pop_front();
            left_index++;
        } else {
            *std::next(_list.begin(), i) = right_chunk.front();
            right_chunk.pop_front();
            right_index++;
        }
    }
}
