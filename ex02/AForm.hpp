/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:02:34 by khorike           #+#    #+#             */
/*   Updated: 2023/09/19 15:14:51 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
public:

AForm();
AForm(const AForm& other);
AForm& operator=(const AForm& other);
virtual ~AForm();

AForm(std::string const &name, int gradeToSign, int gradeToExecute, std::string const &target);

const std::string &getName() const;
bool getIsSigned() const;
int getGradeToSign() const;
int getGradeToExecute() const;
void beSigned(const Bureaucrat &bureaucrat);
void execute(Bureaucrat const & executor) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

const std::string &getTarget() const;

private:
	std::string name;
	bool be_signed;
	const int gradeToSign;
	const int gradeToExecute;
	
protected:
	virtual void executeImplementation() const = 0;
	std::string target;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif