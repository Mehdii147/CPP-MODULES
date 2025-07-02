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
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    (void)executor; // To avoid unused parameter warning
    // srand(time(NULL)); katb9a tbaza 3la real time 
    int randomValue = rand() % 2;
    if (randomValue == 1)
        std::cout << "Bzzzzzzzzzz! " << this->target << " has been robotomized successfully!" << std::endl;
    else
        throw RobotomyFailureException();
}

const char *RobotomyRequestForm::RobotomyFailureException::what() const throw() {
    return "Robotomy failed!";
}
