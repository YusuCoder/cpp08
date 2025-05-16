/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:19:30 by ryusupov          #+#    #+#             */
/*   Updated: 2025/05/16 14:02:32 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>


int main()
{

	std::srand(static_cast<unsigned>(std::time(NULL)));
	Span sp = Span(20000);

	std::set<int> uniqueNumbers;
	while (uniqueNumbers.size() < 10000)
    	uniqueNumbers.insert(std::rand() % 20000);

	std::vector<int> numbers(uniqueNumbers.begin(), uniqueNumbers.end());
	sp.addRange(numbers.begin(), numbers.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;

}


// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }
