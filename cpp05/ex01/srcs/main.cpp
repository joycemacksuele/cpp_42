/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/13 18:31:00 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Form.hpp>

int main() {
	std::string bureaucratName;
	std::cout << std::endl << "Bureaucat will be created...";
	std::cout << "Name the bureaucrat: ";
	std::cin >> bureaucratName;
	//std::cout << std::endl;

	while (1) {
		unsigned int bureaucratGrade;
		std::cout << std::endl << "Choose a grade for the bureaucrat (1 to 150): ";
		std::cin >> bureaucratGrade;
		std::cout << std::endl;

		try {
			Bureaucrat bureaucrat = Bureaucrat(bureaucratName, bureaucratGrade);
			std::cout << bureaucrat;

	/*************************************************************************/

			std::string formName;
			unsigned int formGradeToSign;
			unsigned int formGradeToExecute;
			std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
			std::cout << "A Form will be created and signed (but not executed today)..." << std::endl << std::endl;
			std::cout << "Name of the form: ";
			std::cin >> formName;
			std::cout << std::endl;
			std::cout << "Choose the grade necessary for the form to be signed (1 to 150): ";
			std::cin >> formGradeToSign;
			std::cout << std::endl;
			std::cout << "Choose the grade necessary for the form to be executed (1 to 150): ";
			std::cin >> formGradeToExecute;
			std::cout << std::endl;

			try {
				Form form = Form(formName, formGradeToSign, formGradeToExecute);
				std::cout << form;
				try {
					form.beSigned(bureaucrat);
				} catch (const std::exception& e) {
					std::cerr << std::endl << BOLD RED "Error2: " RESET BOLD << e.what() << RESET << std::endl << std::endl;
				}

	/*************************************************************************/

				if (form.getIsSigned() == false) {

					std::string yesOrNo;
					std::cout << "want to increase or decrease the " << bureaucrat.getName() << "'s grade? (increase/decrease/no): ";
					std::cin >> yesOrNo;
					std::cout << std::endl;

					if (std::strcmp(yesOrNo.c_str(), "decrease") == 0) {
						try {
							bureaucrat.decrementGrade();
							std::cout << bureaucrat;
							std::cout << form;
						} catch (const std::exception& e) {
							std::cerr << std::endl << BOLD RED "Error3: " RESET BOLD << e.what() << RESET << std::endl << std::endl;
						}
					} if (std::strcmp(yesOrNo.c_str(), "decrease") == 0) {
						try {
							bureaucrat.incrementGrade();
							std::cout << bureaucrat;
							std::cout << form;
						} catch (const std::exception& e) {
							std::cerr << std::endl << BOLD RED "Error: " RESET BOLD << e.what() << RESET << std::endl << std::endl;
						}
					} else {
						std::cout << YELLOW << "Wrong choice and Bureaucrat " << bureaucrat.getName() << \
						" could not sign the form. Try aain later! Bye." << RESET << std::endl << std::endl;
						break ;
					}
				}

			} catch (const std::exception& e) {
				std::cerr << std::endl << BOLD RED "Error4: " RESET BOLD << e.what() << RESET << std::endl << std::endl;
				continue ;
			}

		} catch (const std::exception& e) {
			std::cerr << std::endl << BOLD RED "Error1: " RESET BOLD << e.what() << RESET << std::endl << std::endl;
			continue ;
		}

		break ;
	}
	return 0;
}
