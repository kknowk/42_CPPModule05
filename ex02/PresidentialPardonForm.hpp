/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:06:01 by khorike           #+#    #+#             */
/*   Updated: 2023/09/19 14:03:11 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	virtual ~PresidentialPardonForm();

protected:
	void executeImplementation() const;
};

#endif



// 「Zaphod Beeblebrox」は、ダグラス・アダムズのSFコメディ小説『銀河ヒッチハイク・ガイド』
// シリーズに登場するキャラクターで、
// このシリーズの主要キャラクターの1人です。
// 彼は非常に特異な性格を持つ宇宙の冒険家であり、
// 物語の中でさまざまなユニークな状況や事件に巻き込まれます。
// 特に初期の物語で彼は銀河帝国の大統領として登場し、
// その役職とは裏腹に無責任で自由奔放な行動を繰り返します。
// あの金髪のやつ