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

#ifndef EX02_INCLUDES_BUREAUCRAT_HPP_
#define EX02_INCLUDES_BUREAUCRAT_HPP_
# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

#define RED "\033[31m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

class AForm;

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
  void              signAForm(AForm *AForm);
  class GradeTooHighException : public std::exception {
   public:
      const char* what() const throw() {
        return ("Error : Grade too high !");
      }
  };
  class GradeTooLowException : public std::exception {
   public:
      const char* what() const throw() {
        return ("Error : Grade too low !");
      }
  };
};

#endif  //  EX02_INCLUDES_BUREAUCRAT_HPP_
