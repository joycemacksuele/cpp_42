/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/10/01 11:32:30 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>

int main() {
	std::cout << std::endl;
	std::string bureaucratName;
	std::cout << GREEN << "Bureaucat will be created..." << RESET << std::endl;
	std::cout << std::endl << "Name the bureaucrat: ";
	std::getline(std::cin, bureaucratName);
	std::cout << std::endl << "\033[2;37m" << "You will be able to increase or decrease the bureaucrat's grade if the grade is lower than" << std::endl;
	std::cout << "the necessary grade to sign by maximunm 3 grades. Execution will be attempted only once!" << RESET << std::endl;

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

			std::string formName;
			std::string target;
			std::string formGradeToSign;
			std::string formGradeToExecute;
			std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
			std::cout << "A Form will be created, signed and/or executed.." << std::endl << std::endl;
			std::cout << "Choose a target: ";
			std::getline(std::cin, target);
			std::cout << std::endl;

			int i = 4;
			Intern intern;
			AForm* form = NULL;
			while (i >= 0 && form == NULL) {
				if (i == 0) {
					throw -1;
				}
				i--;
				std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
				std::cout << "Pick a form name (shrubbery creation, robotomy request or presidential pardon): ";
				std::getline(std::cin, formName);
				std::cout << std::endl;
				try {
					form = intern.makeForm(formName, target);
				} catch (const std::string& e) {
					std::cerr << BOLD RED "Error: " RESET BOLD << e << RESET << std::endl << std::endl;
					if (i > 0) {
						std::cerr << "Try again " <<  YELLOW << "(you have " << std::to_string(i) << " tries left)." << RESET << std::endl;
					}
					continue ;
				}
			}

			std::cout << std::endl << "----------------------------------------" << std::endl;

			while (form->getIsExecuted() == false) {
				try {
					if (form->getIsSigned() == false) {
						form->beSigned(bureaucrat);
						sleep(1);
						std::cout << *form;
					}
				} catch (const std::exception& e) {
					sleep(1);
					std::cerr << std::endl << BOLD RED "Error2: " RESET BOLD << e.what() << RESET << std::endl <<std::endl;
				}
				if (form->getIsSigned() == true && bureaucrat.getGrade() > form->getGradeToExecute()) {
					bureaucrat.executeForm(*form);
					std::cout << std::endl;
					break ;
				}
				try {
					if (form->getIsExecuted() == false) {
						form->execute(bureaucrat);
						std::cout << *form;
						sleep(1);
						bureaucrat.executeForm(*form);
					}
				} catch (const std::exception& e) {
					sleep(1);
					std::cerr << std::endl << BOLD RED "Error3: " RESET BOLD << e.what() << RESET <<std::endl;
				} catch (const std::string& s) {
					sleep(1);
					std::cerr << BOLD RED "Error3.1: " RESET BOLD << s << RESET << std::endl;
				}

				/*************************************************************************/

				// Will only be able to increment/decrement if the bureaucrat's grade is no more than 3 grades bigger than the form's necesary grade to sign.
				if (bureaucrat.getGrade() - 3 <= form->getGradeToSign() && form->getIsSigned() == false) {
					std::string yesOrNo;
					std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
					std::cout << "Want to increase or decrease the " << bureaucrat.getName() << "'s grade? (increase/decrease/no): ";
					std::getline(std::cin, yesOrNo);

					sleep(1);
					if (std::strcmp(yesOrNo.c_str(), "decrease") == 0) {
						try {
							bureaucrat.decrementGrade();
							std::cout << bureaucrat;
							if (form->getIsSigned() == false) {
								sleep(1);
								std::cout << YELLOW << std::endl << "Attempting to sign the form again..." << RESET << std::endl;
							}
							std::cout << std::endl << "----------------------------------------" << std::endl;
						} catch (const std::exception& e) {
							sleep(1);
							std::cerr << std::endl << BOLD RED "Error4: " RESET BOLD << e.what() << RESET << std::endl;
						}
					} else if (std::strcmp(yesOrNo.c_str(), "increase") == 0) {
						try {
							sleep(1);
							bureaucrat.incrementGrade();
							std::cout << bureaucrat;
							if (form->getIsSigned() == false) {
								sleep(1);
								std::cout << YELLOW << std::endl << "Attempting to sign the form again..." << RESET << std::endl;
							}
							std::cout << std::endl << "----------------------------------------" << std::endl;
						} catch (const std::exception& e) {
							sleep(1);
							std::cerr << std::endl << BOLD RED "Error5: " RESET BOLD << e.what() << RESET << std::endl;
						} catch (const std::string& ee) {
							sleep(1);
							std::cerr << std::endl << BOLD RED "Error5.1: " RESET BOLD << ee << RESET << std::endl;
							std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
							continue ;
						}
					} else {
						sleep(1);
						std::cout << YELLOW << std::endl << "Wrong choice or Bureaucrat " << bureaucrat.getName() << \
							" could not sign or execute the form. Try again later." << RESET << std::endl << std::endl;
						break ;
					}
				} else {
					std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
					break ;
				}
			}
			delete form;
			if (form->getIsExecuted()) {
				break ;
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
		} catch (const int& end) {
			sleep(1);
			std::cerr << YELLOW << "You have no tries left! Bye." << RESET << std::endl << std::endl;
			break ;
		}

		break ;
	}
    //Leaks --atExit -- ./FormByIntern and/or try lldb or gdb
	return 0;
}
