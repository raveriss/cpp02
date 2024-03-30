/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:43:59 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/30 18:24:16 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int value;
	static const int fractionalBits = 8;

public:
	/**
	 * @brief Constructeur de la classe Fixed à partir d'un entier
	 * @param integer: valeur entière à convertir en nombre à virgule fixe
	 */
	Fixed();

	/**
	 * @brief Constructeur de la classe Fixed à partir d'un nombre à virgule flottante
	 * @param floatingPoint: valeur à virgule flottante à convertir en nombre à virgule fixe
	 */
	Fixed(const float floatingPoint);

	
	Fixed(const int integer);
	Fixed(const Fixed& other);
	~Fixed();

	Fixed& operator=(const Fixed& other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	
	/**
	 * @brief Convertit le nombre à virgule fixe en nombre à virgule flottante
	 * @return valeur du nombre à virgule fixe en nombre à virgule flottante
	 */    
	float toFloat(void) const;

	/**
	 * @brief Convertit le nombre à virgule fixe en entier
	 * @return valeur du nombre à virgule fixe en entier
	 */
	int toInt(void) const;

	/**
	 * @brief Opérateur d'insertion pour afficher un nombre à virgule fixe
	 * @param os: flux de sortie
	 * @param fixed: instance de Fixed à afficher
	 * @return flux de sortie modifié
	 */
	friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif
