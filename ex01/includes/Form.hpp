/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:06:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/15 13:56:06 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_INCLUDES_FORM_HPP_
#define EX01_INCLUDES_FORM_HPP_
# include <iostream>
# include <string>
# include <stdexcept>
# include "Form.hpp"
# include "../includes/Bureaucrat.hpp"

class Form {
 private:
  const std::string       _name;
  bool                    _signed;
  const int               _gradeToSign;
  const int               _gradeToExec;
  Form(void);
  Form &operator=(const Form &form);

 public:
  Form(std::string const &name, int gradeToSign, int gradeToExec);
  Form(const Form &form);
  ~Form();

  std::string const &getName(void) const;
  int const         &getGradeToSign(void) const;
  int const         &getGradeToExec(void) const;
  bool const         &getSignedStatus(void) const;
  void              beSigned(const Bureaucrat &bureaucrat);
  class GradeTooLowException : public std::exception {
   public:
      const char* what() const throw() {
        return ("grade is too low !");
      }
  };
  class GradeTooHighException : public std::exception {
   public:
      const char* what() const throw() {
        return ("grade is too high !");
      }
  };
};

#endif  //  EX01_INCLUDES_FORM_HPP_
