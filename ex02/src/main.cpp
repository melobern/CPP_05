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

#define CYAN "\033[0;36m"

static void shrubberyTests(void) {
    Bureaucrat junior("Junior", 150);
    Bureaucrat middle("Middle", 75);
    Bureaucrat senior("Senior", 1);
    ShrubberyCreationForm homeTrees("Home");
    ShrubberyCreationForm metalTrees("Metal");
    ShrubberyCreationForm fireTrees("Fire");

    try {
        homeTrees.beSigned(senior);
        metalTrees.beSigned(senior);
        fireTrees.beSigned(middle);
        senior.executeForm(homeTrees);
        middle.executeForm(metalTrees);
        junior.executeForm(fireTrees);
    } catch (std::exception &e) {
        std::cerr << "Error detected : stopping Shrubbery Tests." << std::endl;
        return;
    }
}

static void robotsTests(void) {
    Bureaucrat junior("Junior", 150);
    Bureaucrat middle("Middle", 75);
    Bureaucrat senior("Senior", 1);
    RobotomyRequestForm robotomy("Tomy");

    try {
        robotomy.beSigned(senior);
        for (int i = 0; i < 10; i++) {
             senior.executeForm(robotomy);
        }
        middle.executeForm(robotomy);
        junior.executeForm(robotomy);
    } catch (std::exception & e) {
        std::cerr << "Error detected : stopping Robotomy Tests." << std::endl;
        return;
    }
}

static void presidentTests(void) {
    Bureaucrat senior("Senior", 1);
    Bureaucrat middle("Middle", 75);
    PresidentialPardonForm pardon("Marvin");

    try {
        pardon.beSigned(senior);
        senior.executeForm(pardon);
        middle.executeForm(pardon);
    } catch (std::exception & e) {
        std::cerr << "Error detected : stopping President Tests." << std::endl;
        return;
    }
}

int main(void) {
    std::cout << CYAN << "-------Shrubbery tests-------" << RESET << std::endl;
    shrubberyTests();
    std::cout << CYAN << "-----------------------------" << RESET << std::endl;

    std::cout << CYAN << "---------Robot tests---------" << RESET << std::endl;
    robotsTests();
    std::cout << CYAN << "-----------------------------" << RESET << std::endl;

    std::cout << CYAN << "-------President tests-------" << RESET << std::endl;
    presidentTests();
    std::cout << CYAN << "-----------------------------" << RESET << std::endl;
    return (0);
}
