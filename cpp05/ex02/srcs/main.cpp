/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/09/01 13:09:15 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>

int main(int argc, char** argv) {
	std::cout << std::endl;

	if (argc != 2) {
		std::cout << "Available arguments:" << std::endl;
		std::cout << GREEN << "1" << RESET << " (for a ShrubberyCreationForm)." << std::endl;
		std::cout << GREEN << "2" << RESET << " (for a RobotomyRequestForm)." << std::endl;
		std::cout << GREEN << "3" << RESET << " (for a PresidentialPardonForm)." << std::endl;
		std::cout << std::endl;
		return 0;
	}

	std::string bureaucratName;
	std::cout << GREEN << "Bureaucat will be created..." << RESET << std::endl;
	std::cout << std::endl << "Name the bureaucrat: ";
	std::getline(std::cin, bureaucratName);

	while (1) {
		std::string bureaucratGrade;
		std::cout << std::endl << "Choose a grade for the bureaucrat (1 to 150): ";
		std::getline(std::cin, bureaucratGrade);
		unsigned int bureaucratGradeNumber = std::atoi(bureaucratGrade.c_str());

		try {
			if (bureaucratGradeNumber == 0 && std::strcmp(bureaucratGrade.c_str(), "0") != 0) {
				throw std::string("Wrong input.");
			}
			std::cout << std::endl;
			Bureaucrat bureaucrat = Bureaucrat(bureaucratName, bureaucratGradeNumber);
			sleep(1);
			std::cout << bureaucrat;

			/*************************************************************************/

			std::string target;

			std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
			if (std::strcmp(argv[1], "1") == 0) {
				std::cout << "A ShrubberyCreationForm will be created, signed and executed..." << std::endl << std::endl;
			}
			ShrubberyCreationForm form = ShrubberyCreationForm(target);
			//} //else if (std::strcmp(argv[1], "2") == 0) {
//				std::cout << "A RobotomyRequestForm will be created, signed and executed..." << std::endl << std::endl;
//			} else if (std::strcmp(argv[1], "3") == 0) {
//				std::cout << "A  PresidentialPardonFormwill be created, signed and executed..." << std::endl << std::endl;
//			}

			std::cout << std::endl << "Choose a target for the form: ";
			std::getline(std::cin, target);
			//std::cout << std::endl;

			bool isSigned = false;
			while (isSigned == false) {
				try {
					//std::cout << std::endl;

					try {
						form.beSigned(bureaucrat);
						if (form.getIsSigned() == true) {
							isSigned = true;
						}
						sleep(1);
						std::cout << form;
					} catch (const std::exception& e) {
						sleep(1);
						std::cerr << std::endl << BOLD RED "Error2: " RESET BOLD << e.what() << RESET << std::endl <<std::endl;
					}
					
					// TODO Execute form now

					/*************************************************************************/

					if (form.getIsSigned() == false) {
						std::string yesOrNo;
						std::cout << "Want to increase or decrease the " << bureaucrat.getName() << "'s grade? (increase/decrease/no): ";
						std::getline(std::cin, yesOrNo);

						sleep(1);
						if (std::strcmp(yesOrNo.c_str(), "decrease") == 0) {
							try {
								bureaucrat.decrementGrade();
								std::cout << bureaucrat;
								std::cout << std::endl << "----------------------------------------" << std::endl;
								form.beSigned(bureaucrat);
								if (form.getIsSigned() == true) {
									isSigned = true;
									sleep(1);
									std::cout << form;
								}

							} catch (const std::exception& e) {
								sleep(1);
								std::cerr << std::endl << BOLD RED "Error3: " RESET BOLD << e.what() << RESET << std::endl;
							}
						} else if (std::strcmp(yesOrNo.c_str(), "increase") == 0) {
							try {
								sleep(1);
								bureaucrat.incrementGrade();
								std::cout << bureaucrat;
								std::cout << std::endl << "----------------------------------------" << std::endl;
								form.beSigned(bureaucrat);
								if (form.getIsSigned() == true) {
									isSigned = true;
									sleep(1);
									std::cout << form;
								}
							} catch (const std::exception& e) {
								sleep(1);
								std::cerr << std::endl << BOLD RED "Error4: " RESET BOLD << e.what() << RESET << std::endl;
							}
						} else {
							sleep(1);
							std::cout << YELLOW << std::endl << "Wrong choice or Bureaucrat " << bureaucrat.getName() << \
								" could not sign or execute the form. Try again later! Bye." << RESET << std::endl;
							break ;
						}
					}

				} catch (const std::exception& e) {
					sleep(1);
					std::cerr << std::endl << BOLD RED "Error5: " RESET BOLD << e.what() << RESET << std::endl;
					std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
					continue ;
				} catch (const std::string& ee) {
					sleep(1);
					std::cerr << std::endl << BOLD RED "Error1.1: " RESET BOLD << ee << RESET << std::endl;
					std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
					continue ;
				}
			}

		} catch (const std::exception& e) {
			sleep(1);
			std::cerr << std::endl << BOLD RED "Error1: " RESET BOLD << e.what() << RESET << std::endl;
			std::cout << std::endl << "----------------------------------------" << std::endl;
			continue ;
		} catch (const std::string& ee) {
			sleep(1);
			std::cerr << std::endl << BOLD RED "Error1.1: " RESET BOLD << ee << RESET << std::endl;
			std::cout << std::endl << "----------------------------------------" << std::endl;
			continue ;
		}

		break ;
	}
	return 0;
}
