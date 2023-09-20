/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:06:11 by khorike           #+#    #+#             */
/*   Updated: 2023/09/19 14:03:37 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <fstream>
#include <stdexcept>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &src);

	ShrubberyCreationForm(std::string const &target);

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	virtual ~ShrubberyCreationForm();
	
protected:
	void executeImplementation() const;
};

#endif

// Shrubbery
// 低木(林)、(庭園内などの)低木