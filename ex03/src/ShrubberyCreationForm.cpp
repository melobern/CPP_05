/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:06:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/16 09:25:10 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <fstream>
#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("Shrubbery Creation Form", 145, 137), _target("default") {
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &aform)
    : AForm(aform), _target(aform._target) {
    return;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &aform) {
    if (this != &aform) {
        this->_target = aform._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    return;
}

std::string const &ShrubberyCreationForm::getTarget(void) const {
    return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    try {
        if (!this->getSignedStatus()) {
            throw FormNotSignedException();
        } else if (executor.getGrade() > this->getGradeToExec()) {
            throw GradeTooLowException();
        }
    } catch (std::exception &e) {
        std::cerr << RED << executor.getName() << " couldn't execute ";
        std::cerr << this->getName() << " because " << e.what() << RESET;
        std::cerr << std::endl;
        throw e;
        return;
    }
    std::ofstream ofs;
    ofs.open((this->_target + "_shrubbery").c_str(), std::ios::trunc);
    if (!ofs.is_open()) {
        std::cerr << "Error : couldn't open file" << std::endl;
        return;
    }
    ofs << FOREST;
    ofs.close();
    return;
}
