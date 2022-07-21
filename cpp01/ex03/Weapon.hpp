/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:53:30 by shaas             #+#    #+#             */
/*   Updated: 2022/07/21 23:21:38 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Weapon {
	private:
		std::string	type;

	public:
		Weapon(std::string type);
		const std::string&	getType(void);
		void				setType(std::string type);
} ;
