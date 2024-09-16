/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:45:13 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/16 09:24:12 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_INCLUDES_SHRUBBERYCREATIONFORM_HPP_
#define EX02_INCLUDES_SHRUBBERYCREATIONFORM_HPP_
# include <iostream>
# include <string>
# include <stdexcept>
# include "../includes/Bureaucrat.hpp"
# include "../includes/AForm.hpp"

class ShrubberyCreationForm  : public AForm {
 private:
  ShrubberyCreationForm(void);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &aform);
  std::string _target;

 public:
  explicit ShrubberyCreationForm(std::string const &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &aform);
  ~ShrubberyCreationForm();
  std::string const         &getTarget(void) const;
  virtual void              execute(Bureaucrat const &executor) const;
};

#define FOREST "\
       _-_               _-_               _-_               _-_\n\
    /~~   ~~\\         /~~   ~~\\         /~~   ~~\\         /~~   ~~\\\n\
 /~~         ~~\\   /~~         ~~\\   /~~         ~~\\   /~~         ~~\\\n\
{               } {               } {               } {               }\n\
 \\  _-     -_  /   \\  _-     -_  /   \\  _-     -_  /   \\  _-     -_  /\n\
   ~  \\\\ //  ~       ~  \\\\ //  ~       ~  \\\\ //  ~       ~  \\\\ //  ~\n\
_- -   | | _- _   _- -   | | _- _   _- -   | | _- _   _- -   | | _- _\n\
  _ -  | |   -_     _ -  | |   -_     _ -  | |   -_      _ - | |   -_\n\
      // \\\\             // \\\\             // \\\\             // \\\\\n"
#endif  //  EX02_INCLUDES_SHRUBBERYCREATIONFORM_HPP_
