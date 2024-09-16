/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:48:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/12 17:24:43 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

#define GREEN "\033[0;32m"

Intern::Intern(void) {
    return;
}

Intern::Intern(const Intern &intern) {
    *this = intern;
    return;
}

Intern& Intern::operator=(Intern const &intern) {
    (void)intern;
    return (*this);
}

Intern::~Intern() {
    return;
}

AForm* Intern::makeForm(std::string const &name, std::string const &target) {
    std::string tab[3] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"};

    int i = 0;
    while (i < 3) {
        if (name == tab[i]) {
            std::cout << GREEN << "Intern creates " << name;
            std::cout << "." << RESET << std::endl;
            break;
        }
        i++;
    }
    switch (i) {
        case 0:
            return new RobotomyRequestForm(target);
        case 1:
            return new PresidentialPardonForm(target);
        case 2:
            return new ShrubberyCreationForm(target);
        default:
            throw AForm::InvalidFormNameException();
    }
}
