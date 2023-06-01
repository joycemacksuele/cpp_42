/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2023/05/29 14:39:09 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>

bool BitcoinExchange::verbose = false;

BitcoinExchange::BitcoinExchange() {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Default constructor called" << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & rhs)
    : _map_data(rhs._map_data) {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Copy constructor called" << std::endl;
    }
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & rhs) {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Assignment operator called" << std::endl;
    }
    if (this != &rhs) {
        this->_map_data = std::map<std::string, double>(rhs._map_data);
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    if (verbose) {
        std::cout << GREEN << __FUNCTION__ << RESET;
        std::cout << " Destructor called" << std::endl;
    }
}

bool BitcoinExchange::handleDataBaseFile() {
    std::ifstream file("resources/data.csv");
    if (file.fail()) {
        std::cerr << RED << "Error: Failed to open resources/data.csv file." << RESET << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line);// Skipping the first line
    if (not file) {
        return false;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        if (ss.fail()) {
            return false;
        }
        std::string date, value;
        std::getline(ss, date, ',');
        std::getline(ss, value, ',');
        if (not ss) {
            return false;
        }
        // Your program will use the value in your input file (being added as the key "date" on the map):
        _map_data[date] = std::stod(value);
    }
    return true;
}

bool BitcoinExchange::checkInput(std::ifstream & input_file) {
    if (not input_file) {
        std::cerr << RED << "Error: Failed to open input file." << RESET << std::endl;
        return false;
    }
    // check the first line
    std::string first_line;
    std::getline(input_file, first_line);
    if (first_line != "date | value") {
        std::cerr << RED << "Error: First line of file is not 'date | value'." << RESET << std::endl;
        return false;
    }
    return true;
}

short BitcoinExchange::bitcoinValuePerDay(const char *file) {
    if (not handleDataBaseFile()) {
        return -1;
    }
    std::ifstream input_file(file);
    if (not checkInput(input_file)) {
        return -1;
    }

    // Continue parsing
    std::string line;
    while (std::getline(input_file, line)) {
        std::istringstream iss(line);
        // A valid date will always be in the following format: Year-Month-Day.
        std::string date;
        // A valid value must be either a float or a positive integer between 0 and 1000.
        std::string value;
        // Separator here is a '|'
        char seperator;
        iss >> date >> seperator >> value;

        if (not iss.fail() && seperator == '|' && checkDate(date) && checkValue<float>(value.c_str(), atof).second) {
            if(checkValue<float>(value.c_str(), atof).first < 0) {
                std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
            } else if(checkValue<long>(value.c_str(), atol).first > INT_MAX) {
                std::cerr << RED << "Error: too large a number." << RESET << std::endl;
            } else if (checkValue<float>(value.c_str(), atof).first > 0 && checkValue<float>(value.c_str(), atof).first < INT_MAX) {
                // Your program should display on the standard output the result of the value
                // multiplied by the exchange rate according to the date indicated in your database:
                float mult = atof(value.c_str()) * findRate(date);
                std::cout << date << " => " << value << " = " << std::setprecision(2) << mult << std::endl;
            }
        } else {
            std::cerr << RED << "Error: bad input => " << date << RESET << std::endl;
        }
    }
    input_file.close();
    return 0;
}

double BitcoinExchange::findRate(std::string date) {
    std::map<std::string, double>::const_iterator it = _map_data.find(date);
    if (it != _map_data.end()) {
        return it->second;
    } else {
        // If the date used in the input does not exist in your DB then you
        // must use the closest date contained in your DB. Be careful to use the
        // lower date and not the upper one:
        std::string previousDay = getClosestDate(date);
        if (previousDay == "not valid date")
            return 0;
        return findRate(previousDay);
    }
}

std::string BitcoinExchange::formatDate(unsigned short possible_prev_year, unsigned short possible_prev_month, unsigned short prev_day) {
    std::string full_date;

    // Formatting year as -> XXXX-
    full_date = std::to_string(possible_prev_year) + "-";

    // Formatting month as -> 0X- or X-
    full_date += (possible_prev_month < 10) ? "0" : "";
    full_date += std::to_string(possible_prev_month) + "-";

    // Formatting day as -> 0X or X
    full_date += (prev_day < 10) ? "0" : "";
    full_date += std::to_string(prev_day);

    // std::cout << YELLOW << full_date << RESET << std::endl;
    return (full_date);
}

std::string BitcoinExchange::getClosestDate(std::string const& date) {
    // Extracting the year, month, and day:
    unsigned short year, month, day;
    unsigned short prev_day, possible_prev_month, possible_prev_year;
    sscanf(date.c_str(), "%hd-%hd-%hd", &year, &month, &day);// todo use istringstream

    prev_day = day - 1;
    possible_prev_month = month;
    possible_prev_year = year;
    // If we are at the previous month, the day has to be the last day of it:
    if (prev_day == 0) {
        possible_prev_month = month - 1;
        switch (possible_prev_month) {
            case 0: {
                possible_prev_month = 12;
                possible_prev_year = year - 1;
                if (possible_prev_year < 2009) {
                    return "not valid date";
                }
            } case 2: {
                // Handle leap years for February
                prev_day = LEAP_YEAR(possible_prev_year);
                break;
            }
            // All down below before we break are 30 days months
            case 4:
            case 6:
            case 9:
            case 11: {
                prev_day = 30;
                break;
            } default:
                prev_day = 31;
        }
    }
    return formatDate(possible_prev_year, possible_prev_month, prev_day);
}

bool BitcoinExchange::checkDate(std::string const& date) {
    if (date.length() == 10) {
        int year, month, day;
        // separator here is '-'
        char separator1, separator2;

        std::istringstream ss(date);
        ss >> year >> separator1 >> month >> separator2 >> day;
        bool leap_year = LEAP_YEAR(year) == 29;
        // std::istringstream fail() returns true if an error has occurred on the associated stream
        if (ss.fail() || separator1 != '-' || separator2 != '-' ||
            year < 0 || (month == 2 && (leap_year ? day > 29 : day > 28)) ||
            month < 1 || month > 12 || day < 1 || day > 31 ||
            ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
            return false;
        }
        return true;
    }
     std::cout << YELLOW << "checkDate returned false" << RESET << std::endl;

    return false;
}
