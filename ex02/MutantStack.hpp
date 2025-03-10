/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:58:10 by ryusupov          #+#    #+#             */
/*   Updated: 2025/03/10 15:35:47 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <vector>
#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T> {
	private:

	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack();
		MutantStack(const MutantStack &src);
		~MutantStack();

		MutantStack &operator=(const MutantStack &src);

		iterator begin();
		iterator end();
};

#endif
coc
