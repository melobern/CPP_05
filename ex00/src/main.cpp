/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:29:57 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/06 09:30:12 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/Bureaucrat.hpp"

#define CYAN "\033[0;36m"
#define YELLOW "\033[0;33m"
#define promotion "\033[0;32m promotion \033[0m"
#define demotion "\033[0;31m demotion \033[0m"

static void junior_tests(void) {
  Bureaucrat junior;
  std::cout << CYAN << "--------------JUNIOR TESTS--------------" << RESET;
  std::cout << std::endl;
  std::cout << "Hi ! My name is " << junior.getName();
  std::cout << ", I just beginned so my grade is ";
  std::cout << YELLOW << junior.getGrade() << RESET;
  std::cout << " !";
  std::cout << std::endl;
  junior.incrementGrade();
  std::cout << "Wow look ! I got a" << promotion << "! Now, my grade is ";
  std::cout << YELLOW << junior.getGrade() << RESET << " !";
  std::cout << std::endl;
  junior.decrementGrade();
  std::cout << "Oh, nevermind. They thought I was the other Junior. ";
  std::cout << "My grade is ";
  std::cout << YELLOW << junior.getGrade() << RESET << " again.";
  std::cout << std::endl;
  std::cout << CYAN << "--------------------------------------------" << RESET;
  std::cout << std::endl;
  return;
}

static void check_args(int ac, char **av) {
  if (ac == 1) {
    junior_tests();
    exit(0);
  } else if (ac == 2) {
    std::cout << RED << "NOT ENOUGH ARGUMENTS !" << RESET;
    std::cout << std::endl;
    exit(1);
  } else if (ac > 3) {
    std::cout << RED << "TOO MANY ARGUMENTS !" << RESET;
    std::cout << std::endl;
    exit(1);
  } else if (!std::isdigit(av[2][0])
    && (av[2][0] != '-' || (!av[2][1] || !std::isdigit(av[2][1])))) {
    std::cout << RED << "ARG 2 DOES NOT BEGIN BY A DIGIT !" << RESET;
    std::cout << std::endl;
    std::cout << "Correct usage : ./Bureaucrat [str] [int]";
    std::cout << std::endl;
    exit(1);
  }
}

int main(int ac, char **av) {
    check_args(ac, av);
    try {
        Bureaucrat paperLover(av[1], atoi(av[2]));

        junior_tests();
        std::cout << CYAN << "--------------ARGS TESTS--------------" << RESET;
        std::cout << std::endl;
        std::cout << "Hi ! My name is " << paperLover.getName();
        std::cout << ", I'm a bureaucrat of grade ";
        std::cout << YELLOW << paperLover.getGrade() << RESET << " !";
        std::cout << std::endl;
        std::cout << "Feel free to give me all necessary papers...";
        std::cout << std::endl;
        paperLover.incrementGrade();
        std::cout << "Wow look ! I got a" << promotion << "! Now, my grade is ";
        std::cout << YELLOW << paperLover.getGrade() << RESET << " !";
        std::cout << std::endl;
        paperLover.decrementGrade();
        paperLover.decrementGrade();
        std::cout << "Oh no ! It was a mistake, I got a" << demotion << ":'( ";
        std::cout << "Now, my grade is ";
        std::cout << YELLOW << paperLover.getGrade() << RESET << " !";
        std::cout << std::endl;
        std::cout << CYAN << "--------------------------------------" << RESET;
        std::cout << std::endl;
        std::cout << CYAN << "--------------TWIN TESTS--------------" << RESET;
        std::cout << std::endl;
        Bureaucrat twin = paperLover;
        std::cout << "Hi, I'm " << paperLover.getName();
        std::cout << "'s twin, my name is also ";
        std::cout << twin.getName() << ". My grade is ";
        std::cout << YELLOW << twin.getGrade() << RESET << ".";
        std::cout << std::endl;
        std::cout << CYAN << "--------------------------------------" << RESET;
        std::cout << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << "Exiting main" << std::endl;
        return (1);
    }
    return (0);
}

