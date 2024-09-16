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
        homeTrees.execute(senior);
        metalTrees.execute(middle);
        fireTrees.execute(junior);
    } catch (std::exception &e) {
        std::cerr << "Error detected : stopping Shrubbery Tests" << std::endl;
        return;
    }
}

static void robotsTests(void) {
    Bureaucrat junior("Junior", 150);
    Bureaucrat middle("Middle", 75);
    Bureaucrat senior("Senior", 1);\
    RobotomyRequestForm robotomy("Robotomy");

    try {
        robotomy.beSigned(senior);
        for (int i = 0; i < 10; i++) {
            robotomy.execute(senior);
        }
        robotomy.execute(middle);
        robotomy.execute(junior);
    } catch (std::exception & e) {
        std::cerr << "Error detected : stopping Robotomy Tests" << std::endl;
        return;
    }
}

int main(void) {
    std::cout << CYAN << "-------Shrubbery tests-------" << RESET << std::endl;
    shrubberyTests();
    std::cout << CYAN << "-----------------------------" << RESET << std::endl;
    std::cout << std::endl;
    std::cout << CYAN << "-------Robots tests-------" << RESET << std::endl;
    robotsTests();
    std::cout << CYAN << "-----------------------------" << RESET << std::endl;
    return (0);
}
