/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers_test.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:45:56 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/09 13:14:57 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_TEST_HPP
# define CONTAINERS_TEST_HPP

# include <iostream>
# include <iomanip>
# include <cstdio>
# include <cstdlib>

/* Include std containers and adapters */

# include <list>
# include <vector>
# include <map>
# include <stack>
# include <queue>

/* Include ft containers and adapters */

# include "list.hpp"
# include "list_iterator.hpp"
# include "vector.hpp"
# include "vector_iterator.hpp"

/* Define macros for coloured output */

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define PURPLE			"\x1b[35m"
# define LIGHT_BLUE		"\x1b[36m"
# define WHITE			"\x1b[37m"
# define NORMAL			"\x1b[0m"

/* Test functions prototypes for each container and adapter */

void		list_test(void);
void		map_test(void);
void		queue_test(void);
void		stack_test(void);
void		vector_test(void);

/* General comparing function */

template <typename T>
void	compareValues(int const & testNmb, T const & stdValue, T const & ftValue, std::string const & testName)
{
	int len = testName.length();
	
	std::cout << LIGHT_BLUE << std::setw(2) << testNmb << ". ";
	std::cout << testName << " ";
	for (int i = 0; (i + len) < 80; i++)
		std::cout << ".";
	std::cout << " " << NORMAL;
	
	if (stdValue == ftValue)
	{
		std::cout << GREEN << "OK" << NORMAL << std::endl;
		// std::cout << std::setw(86) << "Answer: " << stdValue << std::endl;
	}
	else
	{
		std::cout << RED << "WRONG" << NORMAL << std::endl;
		std::cout << std::setw(86) << "Expected answer: " << stdValue << std::endl;
		std::cout << std::setw(86) << "Your answer: " << ftValue << std::endl;
	}	
}

/* Support functions */

template <class Container>
void print_container (std::string testName, Container cont)
{
	std::cout << testName;
	for (typename Container::iterator it = cont.begin(); it != cont.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

#endif