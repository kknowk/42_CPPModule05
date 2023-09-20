/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:27:36 by khorike           #+#    #+#             */
/*   Updated: 2023/09/20 20:25:45 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

template <typename T, typename Args>
T* ft_new(Args args)
{
	T* obj = new (std::nothrow) T(args);
	if (!obj)
	{
		std::cerr << "Memory allocation failed." << '\n';
		std::exit(EXIT_FAILURE);
	}
	return obj;
}

AForm* createShrubberyForm(const std::string& target) { return ft_new<ShrubberyCreationForm>(target); }
AForm* createRobotomyForm(const std::string& target) { return ft_new<RobotomyRequestForm>(target); }
AForm* createPresidentialForm(const std::string& target) { return ft_new<PresidentialPardonForm>(target); }

Intern::FormCreatorFunc Intern::formCreators[3] = { createShrubberyForm, createRobotomyForm, createPresidentialForm };

Intern::Intern() 
{
	forms[0] = "shrubbery creation";
	forms[1] = "robotomy request";
	forms[2] = "presidential pardon";
}

Intern::Intern(const Intern& other)
{
	for (int i = 0; i < 3; i++)
	{
		forms[i] = other.forms[i];
	}
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 3; i++)
		{
			forms[i] = other.forms[i];
		}
	}
	return *this;
}

Intern::~Intern()
{
}

AForm* Intern::clone(int i, const std::string& target)
{
	if (i >= 0 && i < 3)
		return formCreators[i](target);
	return (NULL);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName) 
		{
			AForm* form = clone(i, target);
			return (form);
		}
	}
	return (NULL);
}
