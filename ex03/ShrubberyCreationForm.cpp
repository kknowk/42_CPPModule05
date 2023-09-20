/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:06:08 by khorike           #+#    #+#             */
/*   Updated: 2023/09/19 14:03:44 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137, "") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) 
	: AForm("ShrubberyCreation", 145, 137, target)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) 
	: AForm(src) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeImplementation() const
{
	std::ofstream file(getTarget() + "_shrubbery");
	if (!file.is_open())
		throw std::runtime_error("Unable to open file: " + getTarget() + "_shrubbery");

	file << GREEN;
	file << "     ccee88oo\n";
	file << "  C8O8O8O8O8O8o8o8oo\n";
	file << "dOB69TTSOO8O8O8O8O8O8Oo\n";
	file << "CoooO8O8O8O8O8O8O8O8O8Oo\n";
	file << "   \"\"O8O8O8O8O8O8O8O8O8Oo\n";
	file << "      TSO8O8O8O8O8O8O8O8O8Oo\n";
	file << "     oooO8O8O8O8O8O8O8O8O8Oo\n";
	file << "    O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << "   O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << "  *O8O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << " O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << " \"\"O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O\n";
	file << "    TSO8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8o\n";
	file << "    oooO8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << "   O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << "  *O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << " O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << " \"\"O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << "    TSO8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8o\n";
	file << "    oooO8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << "   O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << "  *O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << " O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << " \"\"O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8O8Oo\n";
	file << RESET;

	file.close();
}