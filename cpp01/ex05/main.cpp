/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:11:12 by shaas             #+#    #+#             */
/*   Updated: 2022/09/07 00:02:47 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int	main(void) {
	Harl	Harl;

	Harl.complain("YEAHHHHH");
	Harl.complain("warning");
	Harl.complain("debug");
	Harl.complain("NOOOOOO");
	Harl.complain("warnig");
	Harl.complain("error");
	Harl.complain("info");

	return (0);
}