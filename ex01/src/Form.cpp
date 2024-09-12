/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:06:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/12 17:21:49 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../includes/Form.hpp"

Form::Form(void)
    : _name("form"), _signed(false), _gradeToSign(20), _gradeToExec(20) {
    return;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExec)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec) {
    return;
}

Form::Form(const Form &form)
    : _name(form._name),
      _signed(form._signed),
      _gradeToSign(form._gradeToSign),
      _gradeToExec(form._gradeToExec) {
    *this = form;
    return;
}

Form& Form::operator=(Form const &form)  {
    if (this != &form) {
        this->_signed = form._signed;
    }
    return (*this);
}

Form::~Form() {
    return;
}

void    Form::beSigned(const Bureaucrat &bureaucrat) {
    try {
        if (bureaucrat.getGrade() > this->getGradeToSign()
            || bureaucrat.getGrade() > this->getGradeToExec()) {
            throw GradeTooLowException();
        }
    }
    catch (std::exception & e) {
        std::cerr << RED << bureaucrat.getName() << " couldn't sign ";
        std::cerr << this->getName() << " because " << e.what() << RESET;
        std::cerr << std::endl;
        throw e;
        return;
    }
    this->_signed = true;
}

std::string const& Form::getName(void) const {
    return (this->_name);
}

int const& Form::getGradeToSign(void) const {
    return (this->_gradeToSign);
}

int const& Form::getGradeToExec(void) const {
    return (this->_gradeToExec);
}
