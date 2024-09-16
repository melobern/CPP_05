/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:48:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/12 17:24:03 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_INCLUDES_INTERN_HPP_
#define EX03_INCLUDES_INTERN_HPP_
# include <iostream>
# include <string>
# include <stdexcept>
#include "../includes/AForm.hpp"

class AForm;

class Intern {
 public:
  Intern(void);
  Intern(const Intern &intern);
  Intern &operator=(const Intern &intern);
  ~Intern();

  AForm*          makeForm(std::string const &name, std::string const &target);
};

#endif  //  EX03_INCLUDES_INTERN_HPP_
