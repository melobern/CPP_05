/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:45:13 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/16 09:24:12 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_INCLUDES_ROBOTOMYREQUESTFORM_HPP_
#define EX02_INCLUDES_ROBOTOMYREQUESTFORM_HPP_
# include <iostream>
# include <string>
# include <stdexcept>
# include "../includes/Bureaucrat.hpp"
# include "../includes/AForm.hpp"

class RobotomyRequestForm  : public AForm {
 private:
  RobotomyRequestForm(void);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &aform);
  std::string _target;

 public:
  explicit RobotomyRequestForm(std::string const &target);
  RobotomyRequestForm(const RobotomyRequestForm &aform);
  ~RobotomyRequestForm();
  std::string const         &getTarget(void) const;
  virtual void              execute(Bureaucrat const &executor) const;
};

#endif  //  EX02_INCLUDES_ROBOTOMYREQUESTFORM_HPP_
