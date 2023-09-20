/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:27:38 by khorike           #+#    #+#             */
/*   Updated: 2023/09/19 20:40:10 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* clone(int i, const std::string& target);

	AForm* makeForm(const std::string& formName, const std::string& target); // フォームを作成する関数
private:
	typedef AForm* (*FormCreatorFunc)(const std::string&); 
	static FormCreatorFunc formCreators[3];
	std::string forms[3];
};

#endif
