/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:48:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/12 17:24:43 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("Junior"), _grade(150) {
    return;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
            : _name(name) {
    try {
        if (grade < 1) {
            throw GradeTooHighException();
        } else if (grade > 150) {
            throw GradeTooLowException();
        }
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
        throw e;
        return;
    }
    this->_grade = grade;
    return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) {
    *this = bureaucrat;
    return;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &bureaucrat)  {
    if (this != &bureaucrat) {
        this->_name = bureaucrat._name;
        this->_grade = bureaucrat._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    return;
}

std::string const& Bureaucrat::getName(void) const {
    return (this->_name);
}

int const& Bureaucrat::getGrade(void) const {
    return (this->_grade);
}

void              Bureaucrat::incrementGrade(void) {
    try {
        if (this->_grade - 1 < 1) {
            throw GradeTooHighException();
        }
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
        throw e;
        return;
    }
    this->_grade--;
    return;
}

void              Bureaucrat::decrementGrade(void) {
    try {
        if (this->_grade + 1 > 150) {
            throw GradeTooLowException();
        }
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
        throw e;
        return;
    }
    this->_grade++;
    return;
}

void    Bureaucrat::signAForm(AForm *aform) {
    try {
        aform->beSigned(*this);
    }
    catch (std::exception & e) {
        throw e;
        return;
    }
    std::cout << GREEN << this->getName() << " signed " << aform->getName();
    std::cout << RESET << std::endl;
}

void    Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
    }
    catch (std::exception &e) {
        throw e;
        return;
    }
    std::cout << GREEN << this->getName() << " executed " << form.getName();
    std::cout << RESET << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Error : Grade too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Error : Grade too low !");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
    out << "My name is " << BRIGHT_YELLOW << bureaucrat.getName() << RESET;
    out << ", I'm a bureaucrat of grade ";
    out << YELLOW << bureaucrat.getGrade() << RESET << " !";
    out << std::endl;
    return (out);
}
