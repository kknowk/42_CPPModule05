/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:02:34 by khorike           #+#    #+#             */
/*   Updated: 2023/09/19 20:52:36 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
public:

	Form();
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	Form(const std::string &name, int gradeToSign, int gradeToExecute);

	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	const std::string name;
	bool be_signed;
	const int gradeToSign;
	const int gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif