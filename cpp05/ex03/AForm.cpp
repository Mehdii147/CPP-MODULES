/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:09:12 by ehafiane          #+#    #+#             */
/*   Updated: 2025/06/25 13:14:51 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("Default"), isSigned(false), signGrade(150), executeGrade(150){  
}

AForm::AForm(const std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{

}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
    
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm()
{
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
        throw GradeTooLowException();
    this->isSigned = true;
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getSignGrade() const
{
    return this->signGrade;
}

int AForm::getExecuteGrade() const
{
    return this->executeGrade;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
    os << "AForm Name: " << AForm.getName() << ", Is Signed: " << (AForm.getIsSigned() ? "Yes" : "No")
       << ", Sign Grade: " << AForm.getSignGrade() << ", Execute Grade: " << AForm.getExecuteGrade();
    return os;
}
