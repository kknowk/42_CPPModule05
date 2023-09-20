/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:06:20 by khorike           #+#    #+#             */
/*   Updated: 2023/09/20 20:32:46 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// new をカスタム
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

    AForm* shrub = ft_new<ShrubberyCreationForm>("garden");
    AForm* robot = ft_new<RobotomyRequestForm>("R2D2");
    AForm* pardon = ft_new<PresidentialPardonForm>("Han Solo");

    std::cout << *shrub << std::endl;
    std::cout << *robot << std::endl;
    std::cout << *pardon << std::endl;


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
// 	system("leaks -q ex02");
// }

// サイン　実行
// PresidentialPardonForm
// 25 5

// RobotomyRequestForm
// 72 45

// ShrubberyCreationForm
// 145 137