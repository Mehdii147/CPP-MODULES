/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:01:27 by ehafiane          #+#    #+#             */
/*   Updated: 2025/07/03 14:06:15 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

    private:
        const std::string name;
        int grade;

    public:
    Bureaucrat(void);
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void signForm(AForm &form);

    void promote();
    void demote();

    void executeForm(const AForm &form);

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
