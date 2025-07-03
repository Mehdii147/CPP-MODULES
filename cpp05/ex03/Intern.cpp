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

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    const std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    AForm* (*formCreators[])(const std::string&) = {
        &Intern::createRobotomy,
        &Intern::createPardon,
        &Intern::createShrubbery
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Intern could not find form: " << formName << std::endl;
    return NULL;
}