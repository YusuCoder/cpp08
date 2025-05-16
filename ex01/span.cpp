/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:45:49 by ryusupov          #+#    #+#             */
/*   Updated: 2025/05/16 13:47:19 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

typedef std::vector<int>::iterator InputIt;

Span::Span() {
	//
}

Span::Span(const unsigned int N): max(N), count(0){
	//
}

Span::Span(const Span &src): max(src.max), count(src.count), vector(src.vector) {
	//
}

Span::~Span() {
	std::cout << "Destructor has been called!" << std::endl;
}

Span &Span::operator=(const Span &src) {
	if (this == &src)
		return *this;
	this->max = src.max;
	this->count = src.count;
	this->vector = src.vector;
	return *this;
}

void Span::addNumber(const unsigned int N) {
	if (this->count >= this->max)
		throw Span::FullSpaceException();
	this->count++;
	this->vector.push_back(N);
}

unsigned int Span::getCount() const{
	return this->count;
}

int Span::getItem(int i) const {
	return this->vector[i];
}

//to find smallest difference between any two numbers
unsigned int Span::shortestSpan() {
	unsigned int	shortestOne;

	if (this->count == 0)
		throw Span::EmptySpaceException();
	if (this->count == 1)
		throw Span::OnlyOneException();
	std::vector<int> sorted(this->vector);
	std::sort(sorted.begin(), sorted.end());
	shortestOne = *(sorted.begin() + 1) - sorted.front();
	if (shortestOne == 0)
		return 0;
	for (InputIt i = (sorted.begin() + 1); i != sorted.end() - 1; i++) {
		if (static_cast<unsigned long>(*(i + 1) - *i) < shortestOne) {
			shortestOne = *(i + 1) - *i;
			if (shortestOne == 0)
				return 0;
		}
	}
	return shortestOne;
}

//to find longest difference between any two numbers
unsigned int Span::longestSpan() {
	unsigned int longestOne;

	if (this->count == 0)
		throw Span::EmptySpaceException();
	if (this->count == 1)
		throw Span::OnlyOneException();
	longestOne = *std::max_element(this->vector.begin(), (this->vector.end())) - *std::min_element(this->vector.begin(), (this->vector.end()));
	return longestOne;
}

void Span::addRange(InputIt start, InputIt end) {
	unsigned int range = std::distance(start, end);

	if (range * this->count > this->max)
		throw Span::RangeTooLargeException();
	this->vector.insert(this->vector.end(), start, end);
	this->count += range;
}

const char *Span::EmptySpaceException::what() const throw() {
	return ("There is no elements in Span!");
}

const char *Span::OnlyOneException::what() const throw() {
	return ("There is only one element in Span!");
}

const char *Span::FullSpaceException::what() const throw() {
	return ("There are no space to store in Span!");
}

const char *Span::RangeTooLargeException::what() const throw() {
	return ("The range is too large!");
}

std::ostream &operator<<(std::ostream &o, const Span &span) {
	for (unsigned int i = 0; i < span.getCount(); i++)
		o << span.getItem(i) << " ";
	return o;
}


