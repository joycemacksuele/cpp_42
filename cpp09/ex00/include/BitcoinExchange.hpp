/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2023/05/29 14:39:09 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <map>

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

#define LEAP_YEAR(x) (((x % 4 == 0) && (x % 100 != 0)) || (x % 400 == 0)) ? 29 : 28

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const & rhs);// Copy constructor
    BitcoinExchange& operator=(BitcoinExchange const & rhs);// Assignment operator
    ~BitcoinExchange();

    /************************ getters and setters *************************/

    /************************** member methods ****************************/
    short bitcoinValuePerDay(const char *file);

    /************************* member variables ***************************/
    static bool verbose;

private:
    std::map<std::string, double> _map_data;

    /************************** member methods ****************************/
    bool handleDataBaseFile();
    double findRate(std::string date);
    std::string getClosestDate(std::string const& date);
    std::string formatDate(unsigned short possible_prev_year, unsigned short possible_prev_month, unsigned short prev_day);
    bool checkInput(std::ifstream & input_file);
    bool checkDate(std::string const& date);

    template<typename T, class FUNC>
    std::pair<T, bool> checkValue(const char* value, FUNC func) {
        try {
            T ret = func(value);
            //std::cerr << BLUE << "ret => " << ret << RESET << std::endl;
            return std::make_pair(ret, true);
        } catch (...) {
            std::cout << YELLOW << "string to float/int/long failed" << RESET << std::endl;
            return std::make_pair(0, false);
        }
    }
};

#endif
