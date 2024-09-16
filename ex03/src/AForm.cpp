/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:06:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/15 13:59:50 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../includes/AForm.hpp"

AForm::AForm(void)
    : _name("aform"), _signed(false), _gradeToSign(20), _gradeToExec(20) {
    return;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExec)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExec > 150)
        throw AForm::GradeTooLowException();
    return;
}

AForm::AForm(const AForm &aform)
    : _name(aform._name),
      _signed(aform._signed),
      _gradeToSign(aform._gradeToSign),
      _gradeToExec(aform._gradeToExec) {
    *this = aform;
    return;
}

AForm& AForm::operator=(AForm const &aform)  {
    if (this != &aform) {
        this->_signed = aform._signed;
    }
    return (*this);
}

AForm::~AForm() {
    return;
}

void    AForm::beSigned(const Bureaucrat &bureaucrat) {
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

std::string const &AForm::getName(void) const {
    return (this->_name);
}

int const& AForm::getGradeToSign(void) const {
    return (this->_gradeToSign);
}

int const& AForm::getGradeToExec(void) const {
    return (this->_gradeToExec);
}

bool const& AForm::getSignedStatus(void) const {
    return (this->_signed);
}
