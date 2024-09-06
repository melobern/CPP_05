/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:48:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/06 09:45:11 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../includes/Bureaucrat.hpp"

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
