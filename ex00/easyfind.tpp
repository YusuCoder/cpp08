/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:34:21 by ryusupov          #+#    #+#             */
/*   Updated: 2025/03/05 15:57:55 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP
#include "easyfind.hpp"
#include <algorithm>

template<typename T>
int	*easyfind(T &container, int n) {
	typename T::iterator it = container.begin();

	it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return (&(*it));
	else throw std::exception();
}

#endif
