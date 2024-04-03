/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:42:25 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/03 23:08:26 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/**
 * @brief Constructeur par défaut
 */
Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur à partir d'un entier
 * @param integer: valeur entière à convertir
 */
Fixed::Fixed(const int integer) : _value(integer << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

/**
 * @brief Constructeur à partir d'un nombre à virgule flottante
 * @param floatingPoint: valeur à virgule flottante à convertir
 */
Fixed::Fixed(const float floatingPoint)
    : _value(roundf(floatingPoint * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie
 * @param other: instance à copier
 */
Fixed::Fixed(const Fixed& other) : _value(other._value)
{
    std::cout << "Copy constructor called" << std::endl;
    std::cout << "Copy assignment operator called" << std::endl;
}

/**
 * @brief Destructeur
 */
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Opérateur d'affectation
 * @param other: instance à affecter
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
 * @brief Récupère la valeur brute des bits
 * @return valeur brute des bits
 */
int Fixed::getRawBits(void) const
{
    return this->_value;
}

/**
 * @brief Définit la valeur brute des bits
 * @param raw: nouvelle valeur brute des bits
 */
void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

/**
 * @brief Convertit le nombre à virgule fixe en nombre à virgule flottante
 * @return valeur du nombre à virgule fixe en nombre à virgule flottante
 */
float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_value) / (1 << _fractionalBits);
}

/**
 * @brief Convertit le nombre à virgule fixe en entier
 * @return valeur du nombre à virgule fixe en entier
 */
int Fixed::toInt(void) const
{
    return this->_value >> _fractionalBits;
}

/**
 * @brief Opérateur d'insertion pour afficher un nombre à virgule fixe
 * @param os: flux de sortie
 * @param fixed: instance de Fixed à afficher
 * @return flux de sortie modifié
 */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}