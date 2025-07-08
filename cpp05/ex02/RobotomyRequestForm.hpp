#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
    private:
        std::string target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

        void execute(Bureaucrat const & executor) const;

};

#endif
