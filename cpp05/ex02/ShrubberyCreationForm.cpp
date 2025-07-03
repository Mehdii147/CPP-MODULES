#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target("default_target") {
}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("Shrubbery Creation Form", 145, 137), target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)  : AForm(other) {
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    file << "         _-_-_\n";
    file << "      /~~       ~~\\\n";
    file << "   /~~             ~~\\\n";
    file << "  |                   |\n";
    file << "   \\__            __/\n";
    file << "      ~-_____-~\n";
    file << "      ~-_____-~\n";
    file << "      ~-_____-~\n";
    file << "      ~-_____-~\n";
    file << "      ~-_____-~\n";
    file << "      ~-_____-~\n";
    file << "      ~-_______-~\n";
    file << "      ~-________-~\n";
    file << "      ~-________-~\n";
    file << "      ~-_________-~\n";
    file << "      ~-___________-~\n";
    
    
    file.close();
}