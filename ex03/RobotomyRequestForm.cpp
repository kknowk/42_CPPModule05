/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:06:04 by khorike           #+#    #+#             */
/*   Updated: 2023/09/19 15:23:20 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequest", 72, 45, "") {}


RobotomyRequestForm::RobotomyRequestForm(std::string const &target) 
	: AForm("RobotomyRequest", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeImplementation() const
{
	std::cout << "Drilling noises..." << std::endl;

	srand(time(0)); // シードの設定
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy on " << getTarget() << " failed!" << std::endl;
}

// srand は "seed random" の略で、
// 擬似乱数生成器にシード（種）を設定する関数

// 通常、現在の時刻などの変化する値を使用することが多いです。
// 具体的には time(0) を使用すると、現在の時刻（エポックからの経過秒数）
// がシードとして使われ、毎回異なるシードが生成されます。

// srand(time(0)) を使うことで、実行するたびに異なるシードが生成され、
// 異なる乱数列が得られるようになります。これにより、乱数生成がランダムになり、
// 異なる結果が得られることが保証されます。