/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:17:09 by ryusupov          #+#    #+#             */
/*   Updated: 2025/03/05 16:02:25 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.tpp"
#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

void print(int &i) {
	std::cout << i << " ";
}

int main(void)
{
	int num[] = {4, 7, 3, 6, 8, 1, 5, 2, 9, 0};
	int	*found_num;

	std::vector<int> vec(num, num + sizeof(num) / sizeof(int));
	std::deque<int> deq(num, num + sizeof(num) / sizeof(int));
	std::list<int> lis(num, num + sizeof(num) / sizeof(int));
	std::for_each(vec.begin(), vec.end(), print);
	std::cout << std::endl;

	std::cout << std::endl;
	try {
		found_num = ::easyfind(vec, 7);
		*found_num += 100;
		std::for_each(vec.begin(), vec.end(), print);
		std::cout << std::endl;
	}catch (std::exception &e) {
		std::cerr << "Container does not contain this integer!" << std::endl;
	}

	try {
		found_num = ::easyfind(vec, 2);
		*found_num += 100;
		std::for_each(vec.begin(), vec.end(), print);
		std::cout << std::endl;
	}catch (std::exception &e) {
		std::cerr << "Container does not contain this integer!" << std::endl;
	}

	try {
		found_num = ::easyfind(vec, 9);
		*found_num += 100;
		std::for_each(vec.begin(), vec.end(), print);
		std::cout << std::endl;
	}catch (std::exception &e) {
		std::cerr << "Container does not contain this integer!" << std::endl;
	}
}
