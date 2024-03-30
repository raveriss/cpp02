/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:41:54 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/30 18:10:02 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

/**
 * @brief Constructeur par défaut de la classe Fixed
 */
class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int integer);
    Fixed(const float floatingPoint);
    Fixed(const Fixed &src);
    Fixed& operator=(const Fixed &rhs);
    ~Fixed();

    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    Fixed& operator++();    // Pré-incrémentation
    Fixed operator++(int);  // Post-incrémentation
    Fixed& operator--();    // Pré-décrémentation
    Fixed operator--(int);  // Post-décrémentation

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
