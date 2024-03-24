/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:51:47 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/14 18:51:48 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const x;
    Fixed const y;

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
