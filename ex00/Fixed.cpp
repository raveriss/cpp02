/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:24:22 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/03 23:01:04 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/**
 * @brief Constructeur par défaut de la classe Fixed
 */
Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie de la classe Fixed
 * @param other: instance de Fixed à copier
 */
Fixed::Fixed(const Fixed& other) : _value(other._value)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/**
 * @brief Opérateur d'affectation de la classe Fixed
 * @param other: instance de Fixed à affecter
 * @return référence sur l'instance courante
 */
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

/**
 * @brief Destructeur de la classe Fixed
 */
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Récupère la valeur brute des bits de l'instance
 * @return valeur brute des bits
 */
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

/**
 * @brief Définit la valeur brute des bits de l'instance
 * @param raw: nouvelle valeur brute des bits
 */
void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}


