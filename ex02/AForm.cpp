/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:02:31 by khorike           #+#    #+#             */
/*   Updated: 2023/09/19 20:57:17 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), be_signed(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const AForm& other) 
	: name(other.name), be_signed(other.be_signed), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), target(other.target) {}

// be_signedのみ代入。その他のメンバはconstなので変更できぬ。
AForm& AForm::operator=(const AForm& other)
{
	be_signed = other.be_signed;
	target = other.target;
	return *this;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute, std::string const &target)
	: name(name), be_signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target) 
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

const std::string &AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return be_signed;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	else
		be_signed = true;
}


const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm Name: " << form.getName() << "\n"
		<< "Is Form Signed? " << (form.getIsSigned() ? "Yes" : "No") << "\n"
		<< "Grade Required to Sign: " << form.getGradeToSign() << "\n"
		<< "Grade Required to Execute: " << form.getGradeToExecute();
	return os;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw std::runtime_error("Form is not signed!");
	(void)executor;
	if (executor.getGrade() > gradeToExecute)
		throw std::runtime_error("Bureaucrat's grade too low to execute the form!");
	executeImplementation();
}

const std::string &AForm::getTarget() const
{
	return target;
}