/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:06:20 by khorike           #+#    #+#             */
/*   Updated: 2023/09/20 20:51:41 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Bureaucrat bureaucrat1("Bureaucrat1", 1);
    Bureaucrat bureaucrat25("Bureaucrat25", 25);
    Bureaucrat bureaucrat26("Bureaucrat26", 26);
    Bureaucrat bureaucrat50("Bureaucrat50", 50);
    Bureaucrat bureaucrat70("Bureaucrat70", 70);
    Bureaucrat bureaucrat100("Bureaucrat100", 100);
    Bureaucrat bureaucrat150("Bureaucrat150", 150);

    std::cout << bureaucrat1 << std::endl;
    std::cout << bureaucrat25 << std::endl;
    std::cout << bureaucrat50 << std::endl;
    std::cout << bureaucrat70 << std::endl;
    std::cout << bureaucrat100 << std::endl;
    std::cout << bureaucrat150 << std::endl;

    // AForm* shrub = new ShrubberyCreationForm("garden");
    // AForm* robot = new RobotomyRequestForm("R2D2");
    // AForm* pardon = new PresidentialPardonForm("Han Solo");

// InternクラスのmakeFormメソッドを使用して各フォームのインスタンスを作成しています。
// これにより、直接フォームクラスをインスタンス化する必要がなくなる
    Intern someRandomIntern;
    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "garden");
    AForm* robot = someRandomIntern.makeForm("robotomy request", "R2D2");
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Han Solo");
    if (!pardon || !robot || !pardon)
    {
        std::cout << "NAME ERROR" << std::endl;
        return 0;
    }
    std::cout << "--------------------------" << std::endl;
    std::cout << *shrub << std::endl;
    std::cout << *robot << std::endl;
    std::cout << pardon << std::endl;


// shrubのサインのテスト
    try {
        bureaucrat1.signForm(*shrub);
    } catch (std::exception &e) {
        std::cerr << "Exception while signing ShrubberyCreationForm: " << e.what() << std::endl;
    }

    try {
        bureaucrat150.signForm(*shrub);
    } catch (std::exception &e) {
        std::cerr << "Exception while signing RobotomyRequestForm: " << e.what() << std::endl;
    }

// robotのサインのテスト
    try {
        bureaucrat1.signForm(*robot);
    } catch (std::exception &e) {
        std::cerr << "Exception while signing ShrubberyCreationForm: " << e.what() << std::endl;
    }

    try {
        bureaucrat100.signForm(*robot);
    } catch (std::exception &e) {
        std::cerr << "Exception while signing RobotomyRequestForm: " << e.what() << std::endl;
    }

// pardonのサインのテスト
    try {
        bureaucrat1.signForm(*pardon);
    } catch (std::exception &e) {
        std::cerr << "Exception while signing ShrubberyCreationForm: " << e.what() << std::endl;
    }

    try {
        bureaucrat26.signForm(*pardon);
    } catch (std::exception &e) {
        std::cerr << "Exception while signing RobotomyRequestForm: " << e.what() << std::endl;
    }


// shrubの実行のテスト
    try {
        bureaucrat1.executeForm(*shrub);
    } catch (std::exception &e) {
        std::cerr << "Exception while executing ShrubberyCreationForm: " << e.what() << std::endl;
    }

    try {
        bureaucrat150.executeForm(*shrub);
    } catch (std::exception &e) {
        std::cerr << "Exception while executing RobotomyRequestForm: " << e.what() << std::endl;
    }

// robotの実行のテスト
    try {
        bureaucrat1.executeForm(*robot);
    } catch (std::exception &e) {
        std::cerr << "Exception while executing PresidentialPardonForm: " << e.what() << std::endl;
    }

    try {
        bureaucrat50.executeForm(*robot);
    } catch (std::exception &e) {
        std::cerr << "Exception while executing PresidentialPardonForm: " << e.what() << std::endl;
    }

// pardonの実行のテスト
    try {
        bureaucrat1.executeForm(*pardon);
    } catch (std::exception &e) {
        std::cerr << "Exception while executing PresidentialPardonForm: " << e.what() << std::endl;
    }

    try {
        bureaucrat25.executeForm(*pardon);
    } catch (std::exception &e) {
        std::cerr << "Exception while executing PresidentialPardonForm: " << e.what() << std::endl;
    }

    delete shrub;
    delete robot;
    delete pardon;

    return 0;
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q ex03");
// }

// サイン　実行
// PresidentialPardonForm
// 25 5

// RobotomyRequestForm
// 72 45

// ShrubberyCreationForm
// 145 137


// Internクラスを使用してフォームを作成することで、
// 追加のフォームタイプが必要な場合や変更があった場合に、
// それを簡単に追加・変更できるというメリットがあります。