/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:06:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/16 09:25:10 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cstdlib>
#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("Robotomy Request Form", 72, 45), _target("default") {
    return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("Robotomy Request Form", 72, 75), _target(target) {
    return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &aform)
    : AForm(aform), _target(aform._target) {
    return;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &aform) {
    if (this != &aform) {
        this->_target = aform._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    return;
}

std::string const &RobotomyRequestForm::getTarget(void) const {
    return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
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
    std::cout << "🚧⚒️  RRRRRRRRRRRR 🏗️ (Drilling noise)🏗️ ⚙️ 🔨🔧🚧" << std::endl;
    int random = rand() % 2;
    if (random == 1) {
        std::cout << "⚙️ ⚙️  " << this->getTarget();
        std::cout << " has been robotomized successfully 🦾🤖✅" << std::endl;
    } else {
        std::cout << "💥💥 " << this->getTarget();
        std::cout << " robotomization failed 😵❌" << std::endl;
    }
    return;
}
