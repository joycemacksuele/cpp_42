/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/01 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2023/06/02 14:39:09 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <stdexcept>
#include <list>
#include <vector>
#include <typeinfo>
#include <stdlib.h>

#define RESET         "\033[0m"
#define RED           "\033[31m"
#define GREEN         "\033[32m"
#define YELLOW        "\033[33m"
#define BLUE          "\033[34m"
#define MAGENTA       "\033[35m"
#define CYAN          "\033[36m"
#define BOLD          "\x1B[1m"
#define CLEAR_SCREEN  "\033c"
#define ERASE_LINE    "\033[2K"
#define JUMP_ONE_LINE "\033[1B"

class PmergeMe {
public:
    PmergeMe(int argc, char** argv);
    PmergeMe(PmergeMe const & rhs);// Copy constructor
    PmergeMe& operator=(PmergeMe const& rhs);// Assignment operator
    ~PmergeMe();

    /************************** member methods ****************************/
    template<typename T>
    int getContainerSize() const {
        if (std::string(typeid(T).name()).find("vector") != std::string::npos) {
            return _vector.size();
        } else {
            return _list.size();
        }
    };

    // https://iq.opengenus.org/merge-insertion-sort/
    template<typename T>
    void mergeInsert(int start, int end) {
        // Getting a good division of the container where each chunk won't have more than 25 numbers
        short chunk_size = end / 2;
        while (1) {
            if (chunk_size > 25) {
                chunk_size = chunk_size / 2;
            } else {
                break;
            }
        }

        // If current container size is smaller or equal than the chunk_size, use insertion sort
        if (end - start <= chunk_size) {
            insertionSort<T>(start, end);
        } else {
            int stop = (start + end) / 2;
            // In Merge sort we split the given array (or a chunk of it) in two parts and
            // sort them individually (using the insertion sort) -> unless the array or chunk is
            // already small enough, then only insertion sort is faster:
            mergeInsert<T>(start, stop);
            mergeInsert<T>(stop + 1, end);
            // Then we merge the both sorted halves (it is based on divide and conquer algorithm):
            merge<T>(start, stop, end);
        }
    };

    /************************* member variables ***************************/
    static bool verbose;

private:
    PmergeMe();
    std::vector<int> _vector;
    std::list<int> _list;

    /************************** member methods ****************************/
    template<typename T>
    void insertionSort(int start, int stop) {
        if (verbose) {
            std::cout << "insertionSort with: " << typeid(T).name() << std::endl;
        }

        // If we are dealing with a vector (NSt3__16vectorIiNS_9allocatorIiEEEE)
        if (std::string(typeid(T).name()).find("vector") != std::string::npos) {
            for (int i = start; i < stop; i++) {
                int temp_number_next = _vector[i + 1];
                int j = i + 1;
                while (j > start && _vector[j - 1] > temp_number_next) {
                    _vector[j] = _vector[j - 1];
                    j--;
                }
                _vector[j] = temp_number_next;
            }
        }
        // If we are dealing with a list (NSt3__14listIiNS_9allocatorIiEEEE)
        else if (std::string(typeid(T).name()).find("list") != std::string::npos) {
            for (int i = start; i < stop; i++) {
                int temp_number_next = 0;
                int temp_number = 0;
                // A list has no easy element access methods in c++98, only begin and end (and std::next is c++11)
                // create an iterator to point to the first element of the list
                typename T::iterator it;
                for (it = _list.begin(); it <= i + 1; ++it) {
                    if (it == i) {
                        temp_number = *it;
                    }
                    if (it == i + 1) {
                        temp_number_next = *it;
                    }
                }

                int j = i + 1;
                // Shift elements to the right to make space for the current element
                while (j > start && temp_number > temp_number_next) {
                    for (it = _list.begin(); it <= j; ++it) {
                        if (it == j - 1) {
                            temp_number = *it;
                        }
                        if (it == j) {
                            _list.push_back(temp_number);
                            // *std::next(_list.begin(), j) = *std::next(_list.begin(), j - 1);
                        }
                    }
                    j--;
                }
                for (it = _list.begin(); it <= j; ++it) {
                    if (it == i) {
                        _list.push_back(temp_number_next);
                        // *std::next(_list.begin(), j) = temp_number_next;
                    }
                }
            }
        }
    };

    template<typename T>
    void merge(int start, int stop, int end) {
        typename T::iterator it;
        int number1 = stop - start + 1;
        int number2 = end - stop;
        T left_chunck, right_chunk;
        // Copy elements from the left sublist to left_chunck
        for (int i = 0; i < number1; i++) {
            if (std::string(typeid(T).name()).find("vector") != std::string::npos) {
                left_chunck[i] = _vector[start + i];
            } else if (std::string(typeid(T).name()).find("list") != std::string::npos) {
                // left_chunck.push_back(*std::next(_list.begin(), start + i));
                for (it = _list.begin(); it <= (start + i); ++it) {
                    if (it == (start + i)) {
                        left_chunck.push_back(*it);
                    }
                }
            }
        }
        // Copy elements from the right sublist to right_chunk
        for (int i = 0; i < number2; i++) {
            if (std::string(typeid(T).name()).find("vector") != std::string::npos) {
                right_chunk[i] = _vector[stop + 1 + i];
            } else if (std::string(typeid(T).name()).find("list") != std::string::npos) {
                // right_chunk.push_back(*std::next(_list.begin(), stop + 1 + i));
                for (it = _list.begin(); it <= (stop + 1 + i); ++it) {
                    if (it == (stop + 1 + i)) {
                        right_chunk.push_back(*it);
                    }
                }
            }
        }

        int left_index, right_index = 0;
        // Merge left_chunck and right_chunk into the container
        for (int i = start; i <= end; i++) {
            if (right_index == number2) {
                if (std::string(typeid(T).name()).find("vector") != std::string::npos) {
                    _vector[i] = left_chunck[left_index];
                }
                *std::next(_list.begin(), i) = left_chunck.front();
                left_chunck.pop_front();
                left_index++;
            } else if (left_index == number1) {
                if (std::string(typeid(T).name()).find("vector") != std::string::npos) {
                    _vector[i] = right_chunk[right_index];
                }
                *std::next(_list.begin(), i) = right_chunk.front();
                right_chunk.pop_front();
                right_index++;
            } else if (right_chunk.front() > left_chunck.front()) {
                if (std::string(typeid(T).name()).find("vector") != std::string::npos) {
                    _vector[i] = left_chunck[left_index];
                }
                *std::next(_list.begin(), i) = left_chunck.front();
                left_chunck.pop_front();
                left_index++;
            } else {
                if (std::string(typeid(T).name()).find("vector") != std::string::npos) {
                    _vector[i] = right_chunk[right_index];
                } else
                *std::next(_list.begin(), i) = right_chunk.front();
                right_chunk.pop_front();
                right_index++;
            }
        }
    };
};

#endif
