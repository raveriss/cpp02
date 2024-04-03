/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:52:28 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/03 22:56:09 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Calcul de l'orientation de trois points dans le plan.
 *        Règle du déterminant" ou "formule du déterminant"
 * @param p1, p2, p3: Points calcul signature
 * @return Fixed: Résultat calcul orientation
 */
static Fixed sign(Point p1, Point p2, Point p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

/**
 * @brief Vérifie point dans triangle excluant arêtes
 *        bsp : Binary Space Partitioning
 * @param a, b, c: Sommets triangle
 * @param point: Point tester
 * @return Booléen: Vrai si point strictement dans triangle
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1, d2, d3;
	bool neg, pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	// La condition modifiée pour exclure les points sur les arêtes ou les sommets
	return !(neg && pos) && !(d1 == 0 || d2 == 0 || d3 == 0);
}

