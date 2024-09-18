/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:06:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/15 13:59:50 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cstdlib>
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
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
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

bool const& Form::getSignedStatus(void) const {
    return (this->_signed);
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("grade is too low !");
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("grade is too high !");
}

std::ostream& operator<<(std::ostream &out, Form const &form) {
    out << "Form " << BLUE << form.getName() << RESET << " is ";
    if (form.getSignedStatus())
        out << GREEN << "signed" << RESET;
    else
        out << RED << "not signed" << RESET;
    out << " and requires grade " << MAGENTA << form.getGradeToSign() << RESET;
    out << " to sign and grade " << MAGENTA << form.getGradeToExec() << RESET;
    out << " to execute." << std::endl;
    return (out);
}
