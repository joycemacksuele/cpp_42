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
#include <cstdlib>
#include <algorithm>

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
    void mergeInsertVector();
    void mergeInsertList();

    template<typename T>
    int getContainerSize() const {
        if (std::string(typeid(T).name()).find("vector") != std::string::npos) {
            return _vector.size();
        } else {
            return _list.size();
        }
    };

    /************************* member variables ***************************/
    static bool verbose;
    static bool std_lib;

private:
    PmergeMe();
    std::vector<int> _vector;
    std::list<int> _list;
    short _chunk_size;

    /************************** private member methods ****************************/
    void setChunckSize(int size);

    // https://iq.opengenus.org/merge-insertion-sort/
    void mergeInsertVector(int start, int end);
    void mergeInsertList(int start, int end);

    void insertionSortVector(int start, int stop);
    void insertionSortList(int start, int stop);

    void mergeVector(int start, int stop, int end);
    void mergeList(int start, int stop, int end);
};

#endif
