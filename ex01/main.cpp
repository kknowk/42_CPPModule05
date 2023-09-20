/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:06:20 by khorike           #+#    #+#             */
/*   Updated: 2023/09/19 20:53:24 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	// try {
	// 	Bureaucrat john("John", 2);
	// 	std::cout << john << std::endl;

	// 	john.incrementGrade();
	// 	// john.incrementGrade();
	// 	std::cout << john << std::endl;

	// 	john.decrementGrade();
	// 	// for(int i = 0; i < 147; i++)
	// 	// {
	// 	// 	john.decrementGrade();
	// 	// }
	// 	// john.decrementGrade();
	// 	std::cout << john << std::endl;
	// } catch (std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }

	Bureaucrat bob("Bob", 2);
	Bureaucrat Jhon("Jhon", 6);
	Form form1("Form1", 1, 5);
	Form form2("Form2", 2, 5);
	Form form3("Form3", 7, 7);
	
	std::cout << bob << std::endl;
	std::cout << Jhon << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;

	std::cout << form1.getName() << " is signed: " << form1.getIsSigned() << std::endl;
	std::cout << form2.getName() << " is signed: " << form2.getIsSigned() << std::endl;
	std::cout << form3.getName() << " is signed: " << form3.getIsSigned() << std::endl;
	
	try {
		bob.signForm(form1);
	} catch (std::exception &e) {
		std::cerr << "Bob couldn't sign Form1 because " << e.what() << std::endl;
	}

	try {
		bob.signForm(form2);
	} catch (std::exception &e) {
		std::cerr << "Bob couldn't sign Form2 because " << e.what() << std::endl;
	}
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form1.getName() << " is signed: " << form1.getIsSigned() << std::endl;
	std::cout << form2.getName() << " is signed: " << form2.getIsSigned() << std::endl;
	
	try {
		Jhon.signForm(form1);
	} catch (std::exception &e) {
		std::cerr << "Jhon couldn't sign Form1 because " << e.what() << std::endl;
	}
	
	try {
		Jhon.signForm(form3);
	} catch (std::exception &e) {
		std::cerr << "Jhon couldn't sign Form2 because " << e.what() << std::endl;
	}
	
	std::cout << form1.getName() << " is signed: " << form1.getIsSigned() << std::endl;
	std::cout << form2.getName() << " is signed: " << form2.getIsSigned() << std::endl;
	std::cout << form3.getName() << " is signed: " << form3.getIsSigned() << std::endl;

	// サインの数は増えない
	try {
		Jhon.signForm(form2);
	} catch (std::exception &e) {
		std::cerr << "Jhon couldn't sign Form2 because " << e.what() << std::endl;
	}
	std::cout << form2.getName() << " is signed: " << form2.getIsSigned() << std::endl;

// bool の確認
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
	return 0;
}
