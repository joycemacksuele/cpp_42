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
    std::cout << std::endl;
	std::string bureaucratName;
	std::cout << GREEN << "Bureaucat will be created..." << RESET << std::endl;
	std::cout << std::endl << "Name the bureaucrat: ";
    std::getline(std::cin, bureaucratName);

	while (1) {
        std::string bureaucratGrade;
		std::cout << std::endl << "Choose a grade for the bureaucrat (1 to 150): ";
        std::getline(std::cin, bureaucratGrade);
        unsigned int bureaucratGradeNumber = std::atoi(bureaucratGrade.c_str());

		std::cout << std::endl;

		try {
			Bureaucrat bureaucrat = Bureaucrat(bureaucratName, bureaucratGradeNumber);
			std::cout << bureaucrat;

	/*************************************************************************/

			std::string formName;
            std::string formGradeToSign;
            std::string formGradeToExecute;
			std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
			std::cout << "A Form will be created and signed (but not executed today)..." << std::endl << std::endl;
			std::cout << "Name of the form: ";
            std::getline(std::cin, formName);
			std::cout << std::endl;

            bool isSigned = false;
			while (isSigned == false) {
			    std::cout << "Choose the grade necessary for the form to be signed (1 to 150): ";
                std::getline(std::cin, formGradeToSign);
                unsigned int formGradeToSignNumber = std::atoi(formGradeToSign.c_str());
		    	std::cout << std::endl;
			    std::cout << "Choose the grade necessary for the form to be executed (1 to 150): ";
                std::getline(std::cin, formGradeToExecute);
                unsigned int formGradeToExecuteNumber = std::atoi(formGradeToExecute.c_str());
			    std::cout << std::endl;

                try {
				    Form form = Form(formName, formGradeToSignNumber, formGradeToExecuteNumber);
				    try {
					    form.beSigned(bureaucrat);
                        if (form.getIsSigned() == true) {
                            isSigned = true;
                        }
				     std::cout << form;
			    	} catch (const std::exception& e) {
			    		std::cerr << std::endl << BOLD RED "Error2: " RESET BOLD << e.what() << RESET << std::endl <<std::endl;
			    	}

	/*************************************************************************/

			    	if (form.getIsSigned() == false) {

				    	std::string yesOrNo;
				    	std::cout << "Want to increase or decrease the " << bureaucrat.getName() << "'s grade? (increase/decrease/no): ";
                       std::getline(std::cin, yesOrNo);

				    	if (std::strcmp(yesOrNo.c_str(), "decrease") == 0) {
					    	try {
						    	bureaucrat.decrementGrade();
						    	std::cout << bureaucrat;
                                std::cout << std::endl << "----------------------------------------" << std::endl;
                                form.beSigned(bureaucrat);
                                if (form.getIsSigned() == true) {
                                    isSigned = true;
				                    std::cout << form;
                                }

					    	} catch (const std::exception& e) {
					    		std::cerr << std::endl << BOLD RED "Error3: " RESET BOLD << e.what() << RESET << std::endl;
					    	}
				    	} else if (std::strcmp(yesOrNo.c_str(), "increase") == 0) {
					    	try {
						    	bureaucrat.incrementGrade();
						    	std::cout << bureaucrat;
                                std::cout << std::endl << "----------------------------------------" << std::endl;
                                form.beSigned(bureaucrat);
                                if (form.getIsSigned() == true) {
                                    isSigned = true;
				                    std::cout << form;
                                }
		    				} catch (const std::exception& e) {
			    				std::cerr << std::endl << BOLD RED "Error4: " RESET BOLD << e.what() << RESET << std::endl;
				    		}
					    } else {
	    					std::cout << YELLOW << std::endl << "Wrong choice or Bureaucrat " << bureaucrat.getName() << \
		    				" could not sign the form. Try again later! Bye." << RESET << std::endl;
			    			break ;
				    	}
				    }

	    		} catch (const std::exception& e) {
		    	std::cerr << std::endl << BOLD RED "Error5: " RESET BOLD << e.what() << RESET << std::endl;
                    std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
				    continue ;
		    	}
            }

		} catch (const std::exception& e) {
			std::cerr << std::endl << BOLD RED "Error1: " RESET BOLD << e.what() << RESET << std::endl;
			continue ;
		}

		break ;
	}
	return 0;
}
