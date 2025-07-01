/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:46:17 by ehafiane          #+#    #+#             */
/*   Updated: 2025/06/28 14:28:59 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 50);
        std::cout << &b1 << std::endl;

        b1.promote();
        std::cout << &b1 << std::endl;

        b1.demote();
        std::cout << &b1 << std::endl;

        Bureaucrat b2("Bob", 0); // This will throw an exception
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}