
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try {
		Intern someRandomIntern;
		AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
		AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Fry");
		AForm* form4 = someRandomIntern.makeForm("unknown form", "Nobody");

		Bureaucrat boss("Boss", 1);

		if (form1) {
			boss.signForm(*form1);
			boss.executeForm(*form1);
			std::cout << *form1 << std::endl;
			delete form1;
		}
		if (form2) {
			boss.signForm(*form2);
			boss.executeForm(*form2);
			std::cout << *form2 << std::endl;
			delete form2;
		}
		if (form3) {
			boss.signForm(*form3);
			boss.executeForm(*form3);
			std::cout << *form3 << std::endl;
			delete form3;
		}
		if (form4) {
			boss.signForm(*form4);
			boss.executeForm(*form4);
			delete form4;
		}
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}