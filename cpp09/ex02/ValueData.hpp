/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValueData.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:58:54 by shaas             #+#    #+#             */
/*   Updated: 2023/06/22 17:14:24 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUEDATA_HPP
# define VALUEDATA_HPP

# include <deque>
# include <vector>
# include <cstddef>

struct ValueData_deque {
	int								value;
	std::deque<ValueData_deque*>	lower;

	/* careful! this will delete the returned value from the list */
	ValueData_deque*	getNewestLower(void);

	ValueData_deque();
	ValueData_deque(ValueData_deque* lower);
	bool	operator==(const ValueData_deque &rhs);
};

struct ValueData_vector{
	int								value;
	std::vector<ValueData_vector*>	lower;

	/* careful! this will delete the returned value from the list */
	ValueData_vector*	getNewestLower(void);

	ValueData_vector();
	ValueData_vector(ValueData_vector* lower);
	bool	operator==(const ValueData_vector &rhs);
};

#endif