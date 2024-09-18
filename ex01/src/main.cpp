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

#include <cstdlib>
#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

#define CYAN "\033[0;36m"

static bool   is_full_digits(std::string str) {
    int    x = 0;
    int    zeros = 0;

    if (str[0] && str[0] == '-' && str[1]) {
        x++;
        zeros++;
    }
    while (str[zeros] && str[zeros] == '0')
        zeros++;
    while (str[x]) {
        if (!std::isdigit(str[x])) {
            std::cout << RED << "ARG 2 MUST BE DIGITS ONLY !" << RESET;
            std::cout << std::endl;
            return (0);
        }
        if (x - zeros > 8) {
            std::cout << RED << "VALUE TOO HIGH OR TOO SMALL ! ";
            std::cout << "PLEASE PROVIDE A NUMBER BETWEEN ";
            std::cout << "-999999999 and 999999999." << RESET;
            std::cout << std::endl;
            return (0);
        }
        x++;
    }
    return (1);
}

static void check_args(int ac, char **av) {
    if (ac != 4) {
        std::cout << RED << "Incorrect number of arguments !" << RESET;
        std::cout << std::endl;
        std::cout << "Correct usage : ./Form [str] [int] [int]";
        std::cout << std::endl;
        exit(1);
    } else if (!is_full_digits(av[2]) || !is_full_digits(av[3])) {
        std::cout << "Correct usage : ./Form [str] [int] [int]";
        std::cout << std::endl;
        exit(1);
    }
}

static void employee_test(Bureaucrat *bureaucrat, Form *form) {
    std::cout << *form;
    std::cout << *bureaucrat;
    std::cout << "I'm trying to sign the " << form->getName() << " form.";
    std::cout << std::endl;
    bureaucrat->signForm(form);
    std::cout << *form;
    std::cout << std::endl;
}

int main(int ac, char **av) {
    check_args(ac, av);
    try {
        Bureaucrat junior("Junior", 150);
        Bureaucrat middle("Middle", 75);
        Bureaucrat senior("Senior", 1);
        Form       form(av[1], atoi(av[2]), atoi(av[3]));
        Form       juniorForm("Simple", 150, 150);
        Form       middleForm("Middle", 75, 75);
        Form       seniorForm("Senior", 1, 1);
        employee_test(&junior, &juniorForm);
        employee_test(&middle, &middleForm);
        employee_test(&senior, &seniorForm);
        employee_test(&senior, &form);
        employee_test(&middle, &form);
        employee_test(&junior, &form);
    } catch (Form::GradeTooHighException& e) {
        std::cerr << "Error : " << e.what() << std::endl;
        std::cerr << "Exiting main" << std::endl;
        return (1);
    } catch (Form::GradeTooLowException& e) {
        std::cerr << "Error : " << e.what() << std::endl;
        std::cerr << "Exiting main" << std::endl;
        return (1);
    } catch (std::exception & e) {
        std::cerr << "Exiting main" << std::endl;
        return (1);
    }
    return (0);
}

