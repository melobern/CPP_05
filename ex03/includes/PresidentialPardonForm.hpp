/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:45:13 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/16 09:24:12 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_INCLUDES_PRESIDENTIALPARDONFORM_HPP_
#define EX02_INCLUDES_PRESIDENTIALPARDONFORM_HPP_
# include <iostream>
# include <string>
# include <stdexcept>
# include "../includes/Bureaucrat.hpp"
# include "../includes/AForm.hpp"

class PresidentialPardonForm  : public AForm {
 private:
  PresidentialPardonForm(void);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &aform);
  std::string _target;

 public:
  explicit PresidentialPardonForm(std::string const &target);
  PresidentialPardonForm(const PresidentialPardonForm &aform);
  ~PresidentialPardonForm();
  std::string const         &getTarget(void) const;
  virtual void              execute(Bureaucrat const &executor) const;
};

#endif  // EX02_INCLUDES_PRESIDENTIALPARDONFORM_HPP_
