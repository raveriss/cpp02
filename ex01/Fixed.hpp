/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:43:59 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/04 13:21:29 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _value;
	static const int _fractionalBits = 8;

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
	 * @brief Insère une représentation en virgule flottante de l'objet Fixed 
	 * 		  dans le flux de sortie.
	 * @param os Flux de sortie dans lequel l'objet doit être inséré.
	 * @param fixed L'objet Fixed à insérer dans le flux.
	 * @return Référence au flux de sortie, permettant le chaînage des insertions.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif
