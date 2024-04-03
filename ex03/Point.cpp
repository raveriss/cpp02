/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:52:07 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/03 22:57:34 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{}

Point::Point(float const xVal, float const yVal) : _x(xVal), _y(yVal)
{}

Point::Point(Point const &src) : _x(src._x), _y(src._y)
{}

Point& Point::operator=(Point const &rhs)
{
	// Utilisation d'une instruction conditionnelle qui n'a aucun effet pour éviter l'avertissement du compilateur
	if (this == &rhs)
		return *this; // Vérification fictive pour utiliser 'rhs' et éviter l'avertissement

	// Retourne *this même si aucune opération d'affectation n'est effectuée, car x et y sont const
	return *this;
}


Point::~Point()
{}

Fixed Point::getX() const
{ 
	return _x;
}

Fixed Point::getY() const
{ 
	return _y;
}
