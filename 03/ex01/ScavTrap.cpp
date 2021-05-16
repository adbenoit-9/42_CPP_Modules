/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:13:50 by adbenoit          #+#    #+#             */
/*   Updated: 2021/05/16 17:01:14 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	std::cout	<< "\033[1;34m" << name << ": Hodor Hodor !"
				<< "\033[0m" << std::endl;
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_name = name;
	_meleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	_armorDamageReduction = 3;
}

ScavTrap::ScavTrap(const ScavTrap& toCopy)
{
	_hitPoints = toCopy._hitPoints;
	_maxHitPoints = toCopy._maxHitPoints;
	_energyPoints = toCopy._energyPoints;
	_maxEnergyPoints = toCopy._maxEnergyPoints;
	_level = toCopy._level;
	_name = toCopy._name;
	_meleeAttackDamage = toCopy._meleeAttackDamage;
	_rangedAttackDamage = toCopy._rangedAttackDamage;
	_armorDamageReduction = toCopy._armorDamageReduction;
}

ScavTrap::~ScavTrap(void)
{
	if (_hitPoints != 0)
		std::cout	<< "\033[34;1m" << _name << ": I'm taking a break, I want a Kitkat !\033[0m" << std::endl;
	else
		std::cout	<< "\033[34;1m" << _name << " : Hodor..."
					<< "\033[0m" << std::endl;
}

ScavTrap&	ScavTrap::operator = (const ScavTrap& toCopy)
{
	if (this == &toCopy)
		return (*this);
	_hitPoints = toCopy._hitPoints;
	_maxHitPoints = toCopy._maxHitPoints;
	_energyPoints = toCopy._energyPoints;
	_maxEnergyPoints = toCopy._maxEnergyPoints;
	_level = toCopy._level;
	_name = toCopy._name;
	_meleeAttackDamage = toCopy._meleeAttackDamage;
	_rangedAttackDamage = toCopy._rangedAttackDamage;
	_armorDamageReduction = toCopy._armorDamageReduction;
	return (*this);
}

void	ScavTrap::rangedAttack(std::string const & target)
{
	if (_hitPoints == 0)
		return ;
	std::cout	<< "\033[34m" << _name << ": Let my door alone... Hiyah !" << std::endl
				<< "\033[2;3;31m" << _name << " caused " << _rangedAttackDamage
				<< " damages to " << target << "\033[0m" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	if (_hitPoints == 0)
		return ;
	std::cout	<< "\033[34m" << _name << ": I saw you stupid idiot !" << std::endl
				<< "\033[2;2;3;31m" << _name << " caused " << _rangedAttackDamage
				<< " damages to " << target << "\033[0m" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
		return ;
	amount -= _armorDamageReduction;
	if (_hitPoints < amount)
		amount = _hitPoints;
	_hitPoints -= amount;
	if (_hitPoints == 0)
		std::cout	<< "\033[31m" << _name << " x_x\033[0m" << std::endl;
	else
		std::cout	<< "\033[34m" << _name << ": Ridiculous, I don't even feel it !\033[0m" << std::endl;
	std::cout	<< "\033[2;3;31m" << _name << " -" << amount
				<< " damages\033[0m" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	unsigned int repairEnergy = amount;
	unsigned int repairHit = amount;

	if (_maxEnergyPoints - _energyPoints < amount)
		repairEnergy = _maxEnergyPoints - _energyPoints;
	if (_maxHitPoints - _hitPoints < amount)
		repairHit = _maxHitPoints - _hitPoints;
	std::cout  << "\033[2;3;32m" << _name << " +" << repairEnergy << " energy points" << std::endl;
	std::cout << "\033[2;3;32m" << _name << " +" << repairHit << " hit points" << std::endl;
	_energyPoints += repairEnergy;
	_hitPoints += repairHit;
	std::cout	<< "\033[0;34m" << _name << ": YOUHOO another shot please !\033[0m" << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string	challenge[5] = {"bring me a Kitkat.", "ate your feet.",\
							"marry me.", "paint my door in pink.", \
							"singing \"I kissed a girl\" naked."};
	if (_hitPoints == 0)
		return ;
	std::cout	<< "\033[34m" << _name << ": Your challenge is to " << challenge[rand() % 5] << std::endl
				<< "\033[34m" << _name << ": " << "No pity for you " << target
				<< " !\033[0m" << std::endl;
}
