#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &other) {
    (void)other; 
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    AForm *form = nullptr;

    if (formName == "robotomy request") {
        form = new RobotomyRequestForm(target);
    } else if (formName == "presidential pardon") {
        form = new PresidentialPardonForm(target);
    } else if (formName == "shrubbery creation") {
        form = new ShrubberyCreationForm(target);
    } else {
        std::cerr << "Error: Form type '" << formName << "' is not recognized." << std::endl;
        return nullptr;
    }

    std::cout << "Intern creates " << form->getName() << "." << std::endl;
    return form;
}