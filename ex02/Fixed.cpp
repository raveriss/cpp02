/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:43:38 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/03 23:05:40 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/**
 * @brief Conversion en float
 * @return Valeur en float
 */
float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / std::pow(2, _fractionalBits);
}

/**
 * @brief Conversion en int
 * @return Valeur en int
 */
int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

/**
 * @brief Constructeur par défaut
 * @param _value: Valeur initiale à 0
 */
Fixed::Fixed() : _value(0)
{}

/**
 * @brief Constructeur à partir d'un entier
 * @param integer: Valeur entière
 * @param _value: Valeur entière décalée
 */
Fixed::Fixed(const int integer) : _value(integer << _fractionalBits)
{}

/**
 * @brief Constructeur à partir d'un float
 * @param floatingPoint: Valeur flottante
 * @param _value: Valeur flottante arrondie
 */
Fixed::Fixed(const float floatingPoint)
	: _value(static_cast<int>(roundf(floatingPoint * (1 << _fractionalBits))))
{}

/**
 * @brief Constructeur de copie
 * @param src: Objet à copier
 */
Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

/**
 * @brief Opérateur d'affectation
 * @param rhs: Objet à affecter
 * @return Référence sur l'objet courant
 */
Fixed& Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

/**
 * @brief Destructeur
 */
Fixed::~Fixed()
{}

/**
 * @brief Récupération des bits bruts
 * @return Valeur brute
 */
int Fixed::getRawBits(void) const
{
	return this->_value;
}

/**
 * @brief Définition des bits bruts
 * @param raw: Nouvelle valeur brute
 */
void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

/**
 * @brief Opérateur de comparaison supérieur
 * @param rhs: Objet à comparer
 * @return Résultat de la comparaison
 */
bool Fixed::operator>(const Fixed &rhs) const
{
	return this->_value > rhs._value;
}

/**
 * @brief Opérateur de comparaison inférieur
 * @param rhs: Objet à comparer
 * @return Résultat de la comparaison
 */
bool Fixed::operator<(const Fixed &rhs) const
{
	return this->_value < rhs._value;
}

/**
 * @brief Opérateur de comparaison supérieur ou égal
 * @param rhs: Objet à comparer
 * @return Résultat de la comparaison
 */
bool Fixed::operator>=(const Fixed &rhs) const
{
	return this->_value >= rhs._value;
}

/**
 * @brief Opérateur de comparaison inférieur ou égal
 * @param rhs: Objet à comparer
 * @return Résultat de la comparaison
 */
bool Fixed::operator<=(const Fixed &rhs) const
{
	return this->_value <= rhs._value;
}

/**
 * @brief Opérateur d'égalité
 * @param rhs: Objet à comparer
 * @return Résultat de la comparaison
 */
bool Fixed::operator==(const Fixed &rhs) const
{
	return this->_value == rhs._value;
}

/**
 * @brief Opérateur de différence
 * @param rhs: Objet à comparer
 * @return Résultat de la comparaison
 */
bool Fixed::operator!=(const Fixed &rhs) const
{
	return this->_value != rhs._value;
}

/**
 * @brief Opérateur d'addition
 * @param rhs: Opérande de droite
 * @return Résultat de l'addition
 */
Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_value + rhs._value);
	return result;
}

/**
 * @brief Opérateur de soustraction
 * @param rhs: Opérande de droite
 * @return Résultat de la soustraction
 */
Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_value - rhs._value);
	return result;
}

/**
 * @brief Opérateur de multiplication
 * @param rhs: Opérande de droite
 * @return Résultat de la multiplication
 */
Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	long temp = static_cast<long>(this->_value) * static_cast<long>(rhs._value);
	result.setRawBits(static_cast<int>(temp >> _fractionalBits));
	return result;
}

/**
 * @brief Opérateur de division
 * @param rhs: Opérande de droite
 * @return Résultat de la division
 */
Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed result;
	if (rhs._value == 0)
	{
		std::cerr << "Error: Division by zero." << std::endl;
		return result;
	}
	long temp = (static_cast<long>(this->_value) << _fractionalBits) / rhs._value;
	result.setRawBits(static_cast<int>(temp));
	return result;
}

/**
 * @brief Opérateur d'incrémentation préfixe
 * @return Référence sur l'objet courant
 */
Fixed& Fixed::operator++()
{
	++(this->_value);
	return *this;
}

/**
 * @brief Opérateur d'incrémentation postfixe
 * @return Copie de l'objet avant incrémentation
 */
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

/**
 * @brief Opérateur de décrémentation préfixe
 * @return Référence sur l'objet courant
 */
Fixed& Fixed::operator--()
{
	--(this->_value);
	return *this;
}

/**
 * @brief Opérateur de décrémentation postfixe
 * @return Copie de l'objet avant décrémentation
 */
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return temp;
}

/**
 * @brief Minimum de deux nombres fixes
 * @param a: Premier nombre
 * @param b: Deuxième nombre
 * @return Référence sur le plus petit nombre
 */
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

/**
 * @brief Minimum de deux nombres fixes constants
 * @param a: Premier nombre
 * @param b: Deuxième nombre
 * @return Référence constante sur le plus petit nombre
 */
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

/**
 * @brief Maximum de deux nombres fixes
 * @param a: Premier nombre
 * @param b: Deuxième nombre
 * @return Référence sur le plus grand nombre
 */
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

/**
 * @brief Maximum de deux nombres fixes constants
 * @param a: Premier nombre
 * @param b: Deuxième nombre
 * @return Référence constante sur le plus grand nombre
 */
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

/**
 * @brief Opérateur de flux de sortie
 * @param out: Flux de sortie
 * @param value: Nombre fixe à afficher
 * @return Flux de sortie modifié
 */
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}
