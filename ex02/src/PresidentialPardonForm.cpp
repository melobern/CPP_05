/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:06:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/16 09:25:10 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cstdlib>
#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("Presidential Pardon Form", 25, 5), _target("default") {
    return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("Presidential Pardon Form", 25, 5), _target(target) {
    return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &aform)
    : AForm(aform), _target(aform._target) {
    return;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &aform)  {
    if (this != &aform) {
        this->_target = aform._target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    return;
}

std::string const &PresidentialPardonForm::getTarget(void) const {
    return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    try {
        if (!this->getSignedStatus()) {
            throw FormNotSignedException();
        } else if (executor.getGrade() > this->getGradeToExec()) {
            throw GradeTooLowException();
        }
    }
    catch (std::exception & e) {
        std::cerr << RED << executor.getName() << " couldn't execute ";
        std::cerr << this->getName() << " because " << e.what() << RESET;
        std::cerr << std::endl;
        throw e;
        return;
    }
    std::cout << this->getTarget() << " ";
    std::cout << "has been pardoned by Zaphod Beeblebrox 🏳️" << std::endl;
    return;
}
