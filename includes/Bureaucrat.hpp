/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:48:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/02 13:43:16 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_INCLUDES_BUREAUCRAT_HPP_
#define EX00_INCLUDES_BUREAUCRAT_HPP_
# include <iostream>
# include <string>
# include <stdexcept>
# include "IBureaucrat.hpp"
# include "AMateria.hpp"

class Bureaucrat {
 public:
  Bureaucrat(void);
  Bureaucrat(std::string const &name, int grade = 150);
  Bureaucrat(const Bureaucrat &bureaucrat);
  Bureaucrat &operator=(const Bureaucrat &bureaucrat);
  ~Bureaucrat();

  std::string const &getName(void) const;
  int         const &getGrade(void) const;
  void              incrementGrade(void);
  void              decrementGrade(void);
  class GradeTooHighException : public std::exception {
  }
  class GradeTooLowException : public std::exception {
  }
 private:
  const std::string       _name;
  int                     _grade;
};

#endif  //  EX00_INCLUDES_BUREAUCRAT_HPP_
