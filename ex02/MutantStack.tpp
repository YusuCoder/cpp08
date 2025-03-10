/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:03:37 by ryusupov          #+#    #+#             */
/*   Updated: 2025/03/10 15:20:27 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() {
	//
};

template<typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "Distructor has been called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src): std::stack<T>(src) {
	//
};

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src){
	std::stack<T>::operator=(src);
	return (*this);
};

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (this->c.end());
}

#endif
