/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:52:07 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/03 16:28:57 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
    @brief Constructeur par défaut de la classe Point
    @param x: Coordonnée x
    @param y: Coordonnée y
*/
Point::Point() : _x(0), _y(0) {}

/**
    @brief Constructeur avec paramètres de la classe Point
    @param xVal: Coordonnée x
    @param yVal: Coordonnée y
*/
Point::Point(float const xVal, float const yVal) : _x(xVal), _y(yVal) {}

/**
    @brief Constructeur de copie de la classe Point
    @param src: Référence constante à l'objet Point à copier
*/
Point::Point(Point const &src) : _x(src._x), _y(src._y) {}

/**
    @brief Opérateur d'affectation de la classe Point
    @param rhs: Référence constante à l'objet Point à affecter
    @return Référence à l'objet Point
*/
Point& Point::operator=(Point const &rhs) {
    // Utilisation d'une instruction conditionnelle qui n'a aucun effet pour éviter l'avertissement du compilateur
    if (this == &rhs) return *this; // Vérification fictive pour utiliser 'rhs' et éviter l'avertissement

    // Retourne *this même si aucune opération d'affectation n'est effectuée, car x et y sont const
    return *this;
}

/**
    @brief Destructeur de la classe Point
*/
Point::~Point() {}

/**
    @brief Accesseur en lecture de la coordonnée x
    @return Valeur de la coordonnée x
*/
Fixed Point::getX() const { return _x; }

/**
    @brief Accesseur en lecture de la coordonnée y
    @return Valeur de la coordonnée y
*/
Fixed Point::getY() const { return _y; }
