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

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const & rhs);// Copy constructor
    BitcoinExchange& operator=(BitcoinExchange const & rhs);// Assignment operator
    ~BitcoinExchange();

    /************************ getters and setters *************************/

    /************************** member methods ****************************/
    void bitcoinValuePerDay(char *file);

    /************************* member variables ***************************/
    static bool verbose;

private:
    std::string _data;
    std::map<std::string, double> _map_data;

    /************************** member methods ****************************/
    std::map<std::string, double> readData();
    double findRate(std::string date, std::map<std::string, double> data);
    std::string moveDateBackOneDay(const std::string& date);
    bool ifValidDate(const std::string& date);
    bool ifValidValue(const std::string& value);
};

#endif
