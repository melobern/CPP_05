/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:56:06 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/16 08:53:11 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_INCLUDES_AFORM_HPP_
#define EX02_INCLUDES_AFORM_HPP_
# include <iostream>
# include <string>
# include <stdexcept>
# include "../includes/Bureaucrat.hpp"
# define BLUE "\033[94m"
# define MAGENTA "\033[35m"

class AForm {
 private:
  const std::string       _name;
  bool                    _signed;
  const int               _gradeToSign;
  const int               _gradeToExec;
  AForm(void);
  AForm &operator=(const AForm &aform);

 public:
  AForm(std::string const &name, int gradeToSign, int gradeToExec);
  AForm(const AForm &aform);
  ~AForm();

  std::string const &getName(void) const;
  int const         &getGradeToSign(void) const;
  int const         &getGradeToExec(void) const;
  bool const        &getSignedStatus(void) const;
  void              beSigned(const Bureaucrat &bureaucrat);
  virtual void              execute(Bureaucrat const &executor) const = 0;
  class GradeTooLowException : public std::exception {
   public:
      const char* what() const throw();
  };
  class GradeTooHighException : public std::exception {
   public:
      const char* what() const throw();
  };
  class FormNotSignedException : public std::exception {
   public:
      const char* what() const throw();
  };
  class InvalidFormNameException : public std::exception {
   public:
      const char* what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif  //  EX02_INCLUDES_AFORM_HPP_
