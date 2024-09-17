/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:48:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/12 17:24:03 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_INCLUDES_BUREAUCRAT_HPP_
#define EX01_INCLUDES_BUREAUCRAT_HPP_
# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[31m"
#define YELLOW "\033[0;33m"
#define BRIGHT_YELLOW "\033[1;93m"
#define RESET "\033[0m"

class Form;

class Bureaucrat {
 private:
  std::string       _name;
  int               _grade;

 public:
  Bureaucrat(void);
  explicit Bureaucrat(std::string const &name, int grade = 150);
  Bureaucrat(const Bureaucrat &bureaucrat);
  Bureaucrat &operator=(const Bureaucrat &bureaucrat);
  ~Bureaucrat();

  std::string const &getName(void) const;
  int         const &getGrade(void) const;
  void              incrementGrade(void);
  void              decrementGrade(void);
  void              signForm(Form *Form);
  class GradeTooHighException : public std::exception {
   public:
      const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
      const char* what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif  //  EX01_INCLUDES_BUREAUCRAT_HPP_
