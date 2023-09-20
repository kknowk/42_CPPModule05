/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:06:20 by khorike           #+#    #+#             */
/*   Updated: 2023/09/15 13:00:24 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat john("John", 2);
		std::cout << john << std::endl;

		john.incrementGrade();
		// john.incrementGrade();
		std::cout << john << std::endl;

		john.decrementGrade();
		// for(int i = 0; i < 147; i++)
		// {
		// 	john.decrementGrade();
		// }
		// john.decrementGrade();
		std::cout << john << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
