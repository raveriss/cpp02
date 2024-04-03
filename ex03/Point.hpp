/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:51:47 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/03 22:45:43 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

/**
	@brief Classe Point avec coordonnées x et y constantes
	@param x: Coordonnée x
	@param y: Coordonnée y
	@param getX: Accesseur en lecture de la coordonnée x
	@param getY: Accesseur en lecture de la coordonnée y
*/
class Point {
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point(float const x, float const y);
	Point(Point const &src);
	Point& operator=(Point const &rhs); // Doit être définie mais ne fera rien car x et y sont const.
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};

#endif
