/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:02:31 by khorike           #+#    #+#             */
/*   Updated: 2023/09/19 20:55:50 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), be_signed(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const Form& other) 
	: name(other.name), be_signed(other.be_signed), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

// be_signedのみ代入。その他のメンバはconstなので変更できぬ。
Form& Form::operator=(const Form& other)
{
	be_signed = other.be_signed;
	return *this;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), be_signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
	{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

const std::string &Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return be_signed;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	else
		be_signed = true;
}


const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form Name: " << form.getName() << "\n"
		<< "Is Form Signed? " << (form.getIsSigned() ? "Yes" : "No") << "\n"
		<< "Grade Required to Sign: " << form.getGradeToSign() << "\n"
		<< "Grade Required to Execute: " << form.getGradeToExecute();
	return os;
}
