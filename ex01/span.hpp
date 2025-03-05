/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:31:28 by ryusupov          #+#    #+#             */
/*   Updated: 2025/03/05 18:19:11 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	private:
		typedef std::vector<int> ::iterator InputIt;
		unsigned int		max;
		unsigned int		count;
		std::vector<int>	vector;

		Span();

	public:
		Span(const unsigned int N);
		Span(const Span &src);
		~Span();

		Span &operator=(const Span &src);

		void	addNumber(const unsigned int N);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			addRange(InputIt start, InputIt end);
		unsigned int	getCount() const;
		int				getItem(int item) const;

		class EmptySpaceException : public std::exception {
			const char	*what() const throw();
		};
		class OnlyOneException : public std::exception {
			const char *what() const throw();
		};
		class FullSpaceException : public std::exception {
			const char *what() const throw();
		};
		class RangeTooLargeException : public std::exception {
			const char *what() const throw();
		};
};

		std::ostream &operator<<(std::ostream &o, const Span &span);

#endif
