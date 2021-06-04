/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:36:30 by adbenoit          #+#    #+#             */
/*   Updated: 2021/05/31 15:29:40 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template<typename T>
void	swap(T & a, T & b)
{
	T tmp = a;

	a = b;
	b = tmp;
}

template<typename T>
T	min(T const & a, T const & b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T>
T	max(T const & a, T const & b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif