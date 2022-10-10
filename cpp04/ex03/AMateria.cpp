/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:39:09 by shaas             #+#    #+#             */
/*   Updated: 2022/10/10 16:39:42 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ------------------------------- CONSTRUCTOR --------------------------------*/

AMateria::AMateria() {
	std::cout << "AMateria default constructor called" << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

AMateria::AMateria(std::string name) {
	std::cout << "AMateria name constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

AMateria::AMateria(const AMateria &orig) {
	std::cout << "AMateria copy constructor called" << std::endl;
	this->name = orig.name;
	this->hitPoints = orig.hitPoints;
	this->energyPoints = orig.energyPoints;
	this->attackDamage = orig.attackDamage;
}

AMateria&	AMateria::operator=(AMateria const &rhs) {
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */
void AMateria::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout	<< "AMateria " << this->name << " attacks " << target
					<< ", causing " << this->attackDamage
					<< " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else {
		std::cout	<< "AMateria " << this->name
					<< " doesn't have enough energy and hit points left to attack."
					<< std::endl;
	}
}

void AMateria::takeDamage(unsigned int amount) {
	std::cout	<< "AMateria " << this->name << " takes "
				<< amount << " damage!" << std::endl;
	if ((this->hitPoints - (int)amount) < 0)
		this->hitPoints = 0;
	else
		this->hitPoints-=amount;
}

void AMateria::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout	<< "AMateria " << this->name << " repairs itself, regaining "
					<< amount << " hit points!" << std::endl;
		this->hitPoints+=amount;
		this->energyPoints--;
	}
	else {
		std::cout	<< "AMateria " << this->name
					<< " doesn't have enough energy and hit points left to repair itself."
					<< std::endl;
	}
}

void	AMateria::printAttributes(std::ostream &out) {
	out << "Name: " << this->name
		<< "\nHit Points: " << this->hitPoints
		<< "\nEnergy Points: " << this->energyPoints
		<< "\nAttack Damage: " << this->attackDamage
		<< std::endl;
}

/* --------------------------------- OVERLOAD --------------------------------- */