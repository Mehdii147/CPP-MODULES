
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	srand(time(NULL));

	try {
		
	std::cout << "\033[33m" << std::endl << "Test ex02" << "\033[0m" << std::endl;

	std::cout << "\033[33m" << std::endl << "Test ShrubberyCreationForm" << "\033[0m" << std::endl;
	Bureaucrat Mr_Shrubby("Mr_Shrubby", 137);
	ShrubberyCreationForm Shrubby_form("chagra");
	std::cout << std::endl;
	std::cout << Shrubby_form;
	Mr_Shrubby.signForm(Shrubby_form);
	std::cout << Shrubby_form;
	Mr_Shrubby.executeForm(Shrubby_form);

	std::cout << "\033[33m" << std::endl << "Test RobotomyRequestForm" << "\033[0m" << std::endl;
	RobotomyRequestForm Robot_form("I am a robot form");
	Bureaucrat Mr_Robo("Mr_Robo", 45);
	Mr_Robo.executeForm(Robot_form);
	Mr_Robo.signForm(Robot_form);
	Mr_Robo.executeForm(Robot_form);
	Mr_Robo.executeForm(Robot_form);
	Mr_Robo.executeForm(Robot_form);

	std::cout << "\033[33m" << std::endl << "Test PresidentialPardonForm" << "\033[0m" << std::endl;
	PresidentialPardonForm President_form("I am a robo form");
	Bureaucrat Mr_President("Mr_President", 5);
	Mr_Robo.executeForm(President_form);
	Mr_Robo.signForm(President_form);
	Mr_President.executeForm(President_form);
	Mr_President.signForm(President_form);
	Mr_President.executeForm(President_form);
	
}
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}