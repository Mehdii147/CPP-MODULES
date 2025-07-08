#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"


class AForm;

class Intern {
    public:
        Intern();
        Intern(const Intern &other);
        ~Intern();
        Intern &operator=(const Intern &other);
        
        static AForm *createRobotomy(const std::string &target);
        static AForm *createPardon(const std::string &target);
        static AForm *createShrubbery(const std::string &target);

        AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif