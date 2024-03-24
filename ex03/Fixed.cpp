/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:43:38 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/14 17:53:02 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// ...autres méthodes de Fixed...

float Fixed::toFloat(void) const {
    return static_cast<float>(_value) / std::pow(2, _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

Fixed::Fixed() : _value(0) {
    // Ici, _value est initialisé à 0, représentant 0 en virgule fixe.
}

Fixed::Fixed(const int integer) : _value(integer << _fractionalBits) {
}

Fixed::Fixed(const float floatingPoint)
    : _value(static_cast<int>(roundf(floatingPoint * (1 << _fractionalBits)))) {
}

Fixed::Fixed(const Fixed &src) {
    *this = src;
}

Fixed& Fixed::operator=(const Fixed &rhs) {
    if (this != &rhs) {
        this->_value = rhs.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

bool Fixed::operator>(const Fixed &rhs) const {
    return this->_value > rhs._value;
}

bool Fixed::operator<(const Fixed &rhs) const {
    return this->_value < rhs._value;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return this->_value >= rhs._value;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return this->_value <= rhs._value;
}

bool Fixed::operator==(const Fixed &rhs) const {
    return this->_value == rhs._value;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return this->_value != rhs._value;
}

Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->_value + rhs._value);
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->_value - rhs._value);
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed result;
    long temp = static_cast<long>(this->_value) * static_cast<long>(rhs._value);
    result.setRawBits(static_cast<int>(temp >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    Fixed result;
    if (rhs._value == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        return result;
    }
    long temp = (static_cast<long>(this->_value) << _fractionalBits) / rhs._value;
    result.setRawBits(static_cast<int>(temp));
    return result;
}

Fixed& Fixed::operator++() {
    ++(this->_value);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    --(this->_value);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}
