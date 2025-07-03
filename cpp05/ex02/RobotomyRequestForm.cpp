#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 72, 45), target("default_target") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("Robotomy Request Form", 72, 45), target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
    : AForm(other){
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    srand(time(NULL)); 
    int randomValue = rand() % 2;
    if (randomValue == 1)
        std::cout << "Bzzzzzzzzzz! " << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed!" << std::endl;
}
