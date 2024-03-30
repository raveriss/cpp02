/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:42:25 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/30 18:03:57 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/**
 * @brief Constructeur par défaut
 */
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur à partir d'un entier
 * @param integer: valeur entière à convertir
 */
Fixed::Fixed(const int integer) : value(integer << fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

/**
 * @brief Constructeur à partir d'un nombre à virgule flottante
 * @param floatingPoint: valeur à virgule flottante à convertir
 */
Fixed::Fixed(const float floatingPoint)
    : value(roundf(floatingPoint * (1 << fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie
 * @param other: instance à copier
 */
Fixed::Fixed(const Fixed& other) : value(other.value) {
    std::cout << "Copy constructor called" << std::endl;
    std::cout << "Copy assignment operator called" << std::endl;
}

/**
 * @brief Destructeur
 */
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Opérateur d'affectation
 * @param other: instance à affecter
 * @return référence sur l'instance courante
 */
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->value = other.getRawBits();
    }
    return *this;
}

/**
 * @brief Récupère la valeur brute des bits
 * @return valeur brute des bits
 */
int Fixed::getRawBits(void) const {
    return this->value;
}

/**
 * @brief Définit la valeur brute des bits
 * @param raw: nouvelle valeur brute des bits
 */
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

/**
 * @brief Convertit le nombre à virgule fixe en nombre à virgule flottante
 * @return valeur du nombre à virgule fixe en nombre à virgule flottante
 */
float Fixed::toFloat(void) const {
    return static_cast<float>(this->value) / (1 << fractionalBits);
}

/**
 * @brief Convertit le nombre à virgule fixe en entier
 * @return valeur du nombre à virgule fixe en entier
 */
int Fixed::toInt(void) const {
    return this->value >> fractionalBits;
}

/**
 * @brief Opérateur d'insertion pour afficher un nombre à virgule fixe
 * @param os: flux de sortie
 * @param fixed: instance de Fixed à afficher
 * @return flux de sortie modifié
 */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}