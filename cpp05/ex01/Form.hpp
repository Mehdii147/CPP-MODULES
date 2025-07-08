/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:06:04 by ehafiane          #+#    #+#             */
/*   Updated: 2025/07/03 14:06:26 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat; 

class Form {
    
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;
    public:
    Form(void);
    Form(const std::string name, int signGrade, int executeGrade);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    void beSigned(const Bureaucrat &bureaucrat);
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif