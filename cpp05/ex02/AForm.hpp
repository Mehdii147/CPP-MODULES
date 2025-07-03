/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:06:04 by ehafiane          #+#    #+#             */
/*   Updated: 2025/07/03 14:06:19 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;
    public:
    AForm(void);
    AForm(const std::string name, int signGrade, int executeGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    ~AForm();

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

    virtual	void execute(Bureaucrat const & executor) const = 0;

};

std::ostream &operator<<(std::ostream &os, const AForm &Aform);

#endif