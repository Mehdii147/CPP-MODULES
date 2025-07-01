/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:16:40 by ehafiane          #+#    #+#             */
/*   Updated: 2025/07/01 15:43:29 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Default"), grade(150) {
    std::cout << "Bureaucrat default constructor called for " << this->getName() << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Bureaucrat constructor called for " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
    std::cout << "Bureaucrat copy constructor called for " << this->getName() << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->grade = other.grade;
        std::cout << "Bureaucrat assignment operator called for " << this->getName() << std::endl;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called for " << this->getName() << std::endl;
}

std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
    }
}

void Bureaucrat::promote() {
    if (this->grade <= 1)
    throw GradeTooHighException();
    this->grade--;
    std::cout << this->getName() << " promoted to grade " << this->getGrade() << std::endl;
}

void Bureaucrat::demote() {
    if (this->grade >= 150)
    throw GradeTooLowException();
    this->grade++;
    std::cout << this->getName() << " demoted to grade " << this->getGrade() << std::endl;
}

void Bureaucrat::executeForm(const AForm &form){
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

