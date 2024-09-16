/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:29:57 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/15 14:07:20 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

#define CYAN "\033[0;36m"

void internTest(std::string const &name, std::string const &target) {
    Bureaucrat someRandomBureaucrat("Some random bureaucrat", 1);
    Intern someRandomIntern;
    AForm* form;

    try {
        form = someRandomIntern.makeForm(name, target);
    } catch (AForm::InvalidFormNameException &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
        return;
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
        return;
    }
    form->beSigned(someRandomBureaucrat);
    someRandomBureaucrat.executeForm(*form);
    delete form;
}

int main(void) {
    std::cout << CYAN << "--------Intern test---------" << RESET << std::endl;
    internTest("robotomy request", "Bender");
    internTest("presidential pardon", "Marvin");
    internTest("shrubbery creation", "Poison Ivy");
    internTest("delulu request", "Idiot");
    std::cout << CYAN << "-----------------------------" << RESET << std::endl;
    return (0);
}
