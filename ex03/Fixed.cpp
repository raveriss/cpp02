/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:43:38 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/04 10:38:42 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/**
 * @brief Conversion valeur fixe en flottant
 * @return Float: Valeur en flottant
 */
float Fixed::toFloat(void) const
{	
	return static_cast<float>(_value) / std::pow(2, _fractionalBits);
}

/**
 * @brief Conversion valeur fixe en entier
 * @return Int: Valeur en entier
 */
int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

/**
 * @brief Constructeur par défaut valeur fixe
 * @details Initialisation valeur 0
 */
Fixed::Fixed() : _value(0)
{}

/**
 * @brief Constructeur avec entier pour valeur fixe
 * @details Conversion entier en fixe, décalage bits
 */
Fixed::Fixed(const int integer) : _value(integer << _fractionalBits)
{}

/**
 * @brief Constructeur avec flottant pour valeur fixe
 * @details Conversion flottant en fixe, arrondi
 */
Fixed::Fixed(const float floatingPoint)
	: _value(static_cast<int>(roundf(floatingPoint * (1 << _fractionalBits))))
{}

/**
 * @brief Constructeur de copie pour valeur fixe
 * @details Copie valeur d'un autre objet Fixed
 */
Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

/**
 * @brief Opérateur d'affectation pour valeur fixe
 *        right-hand side
 * @details Copie bits si objets différents
 * @return Référence objet courant
 */
Fixed& Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

/**
 * @brief Destructeur pour valeur fixe
 */
Fixed::~Fixed()
{}

/**
 * @brief Accesseur bits bruts valeur fixe
 * @return Entier: bits bruts
 */
int Fixed::getRawBits(void) const
{
	return this->_value;
}

/**
 * @brief Mutateur bits bruts pour valeur fixe
 * @param raw: nouvelle valeur bits bruts
 */
void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

/**
 * @brief Comparaison supérieur valeur fixe
 * @param rhs: valeur droite comparaison
 * @return Booléen: vrai si supérieur
 */
bool Fixed::operator>(const Fixed &rhs) const
{
	return this->_value > rhs._value;
}

/**
 * @brief Comparaison inférieur valeur fixe
 * @param rhs: valeur droite comparaison
 * @return Booléen: vrai si inférieur
 */
bool Fixed::operator<(const Fixed &rhs) const
{
	return this->_value < rhs._value;
}

/**
 * @brief Comparaison supérieur ou égal valeur fixe
 * @param rhs: valeur droite comparaison
 * @return Booléen: vrai si supérieur ou égal
 */
bool Fixed::operator>=(const Fixed &rhs) const
{
	return this->_value >= rhs._value;
}

/**
 * @brief Comparaison inférieur ou égal valeur fixe
 * @param rhs: valeur droite comparaison
 * @return Booléen: vrai si inférieur ou égal
 */
bool Fixed::operator<=(const Fixed &rhs) const
{
	return this->_value <= rhs._value;
}

/**
 * @brief Comparaison égalité valeur fixe
 * @param rhs: valeur droite comparaison
 * @return Booléen: vrai si égal
 */
bool Fixed::operator==(const Fixed &rhs) const
{
	return this->_value == rhs._value;
}

/**
 * @brief Comparaison non-égalité valeur fixe
 * @param rhs: valeur droite comparaison
 * @return Booléen: vrai si différent
 */
bool Fixed::operator!=(const Fixed &rhs) const
{
	return this->_value != rhs._value;
}

/**
 * @brief Addition valeurs fixes
 * @param rhs: opérande droite
 * @return Fixed: résultat addition
 */
Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_value + rhs._value);
	return result;
}

/**
 * @brief Soustraction valeurs fixes
 * @param rhs: opérande droite
 * @return Fixed: résultat soustraction
 */
Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_value - rhs._value);
	return result;
}

/**
 * @brief Multiplication valeurs fixes
 * @param rhs: opérande droite
 * @details Utilise conversion long pour précision
 * @return Fixed: résultat multiplication
 */
Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	long temp = static_cast<long>(this->_value) * static_cast<long>(rhs._value);
	result.setRawBits(static_cast<int>(temp >> _fractionalBits));
	return result;
}

/**
 * @brief Division valeurs fixes
 * @param rhs: opérande droite
 * @details Gestion division par zéro, décalage pour précision
 * @return Fixed: résultat division
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
 * @brief Incrémentation préfixe valeur fixe
 * @return Référence objet incrémenté
 */
Fixed& Fixed::operator++()
{
	++(this->_value);
	return *this;
}

/**
 * @brief Incrémentation postfixe valeur fixe
 * @details Retourne valeur avant incrémentation
 * @return Fixed: objet avant incrémentation
 */
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

/**
 * @brief Décrémentation préfixe valeur fixe
 * @return Référence objet décrémenté
 */
Fixed& Fixed::operator--()
{
	--(this->_value);
	return *this;
}

/**
 * @brief Décrémentation postfixe valeur fixe
 * @details Retourne valeur avant décrémentation
 * @return Fixed: objet avant décrémentation
 */
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return temp;
}

/**
 * @brief Minimum entre deux valeurs fixes
 * @param a: première valeur
 * @param b: seconde valeur
 * @return Référence à la plus petite valeur
 */
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

/**
	@brief Retourne la référence à l'objet Fixed le plus petit
	@param a: Référence à l'objet Fixed
	@param b: Référence à l'objet Fixed
	@return Référence à l'objet Fixed le plus petit
*/
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

/**
	@brief Retourne la référence à l'objet Fixed le plus grand
	@param a: Référence à l'objet Fixed
	@param b: Référence à l'objet Fixed
	@return Référence à l'objet Fixed le plus grand
*/
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

/**
	@brief Retourne la référence à l'objet Fixed le plus grand
	@param a: Référence constante à l'objet Fixed
	@param b: Référence constante à l'objet Fixed
	@return Référence constante à l'objet Fixed le plus grand
*/
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

/**
	@brief Surcharge de l'opérateur d'insertion pour la classe Fixed
	@param out: Référence à l'objet ostream
	@param value: Référence constante à l'objet Fixed
	@return Référence à l'objet ostream
*/
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}
