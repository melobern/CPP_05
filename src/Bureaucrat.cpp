/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:48:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/02 13:43:36 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#define RED "\033[31m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

Bureaucrat::Bureaucrat(void) : _name("Anonymous"), _grade(150) {
    return;
}

Bureaucrat(std::string const &name, int grade)
            : _name("Anonymous") {
    if (grade < 1 || grade > 150)
        throw std::
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
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    return;
}

std::string const& Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() {
    return (this->_name);
}

void              Bureaucrat::incrementGrade(void) {

    return;
}

void              Bureaucrat::decrementGrade(void) {
    return;
}
