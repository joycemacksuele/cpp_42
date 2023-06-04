/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2023/05/29 14:39:09 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char **argv) {
    if (argc != 2) {
        std::cout << RED << "Error: missing second argument"<< RESET << std::endl;
        return -1;
    }
    BitcoinExchange bitcoinExchange;
    return bitcoinExchange.bitcoinValuePerDay(argv[1]);
}
