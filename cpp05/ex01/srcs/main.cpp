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
	std::cout << "Bureaucat will be created..." << std::endl;
	std::cout << std::endl << "Name the bureaucrat: ";
	//std::cin >> bureaucratName;
    std::getline(std::cin, bureaucratName);
	//std::cout << std::endl;

	while (1) {
        std::string bureaucratGrade;
		std::cout << std::endl << "Choose a grade for the bureaucrat (1 to 150): ";
		//std::cin >> bureaucratGrade;
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
			//std::cin >> formName;
            std::getline(std::cin, formName);
			std::cout << std::endl;

            bool isSigned = false;
			while (isSigned == false) {
			    std::cout << "Choose the grade necessary for the form to be signed (1 to 150): ";
			    //std::cin >> formGradeToSign;
                std::getline(std::cin, formGradeToSign);
                unsigned int formGradeToSignNumber = std::atoi(formGradeToSign.c_str());
		    	std::cout << std::endl;
			    std::cout << "Choose the grade necessary for the form to be executed (1 to 150): ";
			    //std::cin >> formGradeToExecute;
                std::getline(std::cin, formGradeToExecute);
                unsigned int formGradeToExecuteNumber = std::atoi(formGradeToExecute.c_str());
			    std::cout << std::endl;

                try {
				    Form form = Form(formName, formGradeToSignNumber, formGradeToExecuteNumber);
				    //std::cout << form;
				    try {
					    form.beSigned(bureaucrat);
                        if (form.getIsSigned() == true) {
                            isSigned = true;
                        }
				     std::cout << form << std::endl;
			    	} catch (const std::exception& e) {
			    		std::cerr << std::endl << BOLD RED "Error2: " RESET BOLD << e.what() << RESET << std::endl << std::endl;
			    	}

	/*************************************************************************/

			    	if (form.getIsSigned() == false) {

				    	std::string yesOrNo;
				    	std::cout << "want to increase or decrease the " << bureaucrat.getName() << "'s grade? (increase/decrease/no): ";
				    	//std::cin >> yesOrNo;
                       std::getline(std::cin, yesOrNo);
				    	std::cout << std::endl;

				    	if (std::strcmp(yesOrNo.c_str(), "decrease") == 0) {
					    	try {
						    	bureaucrat.decrementGrade();
						    	std::cout << bureaucrat;
						    	//std::cout << form;
                                std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
                                form.beSigned(bureaucrat);
                                if (form.getIsSigned() == true) {
                                    isSigned = true;
                                }

					    	} catch (const std::exception& e) {
					    		std::cerr << std::endl << BOLD RED "Error3: " RESET BOLD << e.what() << RESET << std::endl << std::endl;
					    	}
				    	} else if (std::strcmp(yesOrNo.c_str(), "increase") == 0) {
					    	try {
						    	bureaucrat.incrementGrade();
						    	std::cout << bureaucrat;
							    //std::cout << form;
                                std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
                                form.beSigned(bureaucrat);
                                if (form.getIsSigned() == true) {
                                    isSigned = true;
                                }
		    				} catch (const std::exception& e) {
			    				std::cerr << std::endl << BOLD RED "Error4: " RESET BOLD << e.what() << RESET << std::endl << std::endl;
				    		}
					    } else {
	    					std::cout << YELLOW << "Wrong choice or Bureaucrat " << bureaucrat.getName() << \
		    				" could not sign the form. Try again later! Bye." << RESET << std::endl << std::endl;
			    			break ;
				    	}
				    }

	    		} catch (const std::exception& e) {
		    		std::cerr << std::endl << BOLD RED "Error5: " RESET BOLD << e.what() << RESET << std::endl << std::endl;
                    std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;
				    continue ;
		    	}
            }

		} catch (const std::exception& e) {
			std::cerr << std::endl << BOLD RED "Error1: " RESET BOLD << e.what() << RESET << std::endl << std::endl;
			continue ;
		}

		break ;
	}
	return 0;
}
