/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:52:07 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/14 18:56:04 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const xVal, float const yVal) : x(xVal), y(yVal) {}

Point::Point(Point const &src) : x(src.x), y(src.y) {}

Point& Point::operator=(Point const &rhs) {
    // Utilisation d'une instruction conditionnelle qui n'a aucun effet pour éviter l'avertissement du compilateur
    if (this == &rhs) return *this; // Vérification fictive pour utiliser 'rhs' et éviter l'avertissement

    // Retourne *this même si aucune opération d'affectation n'est effectuée, car x et y sont const
    return *this;
}


Point::~Point() {}

Fixed Point::getX() const { return x; }

Fixed Point::getY() const { return y; }
