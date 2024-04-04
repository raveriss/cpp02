/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:57:35 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/04 15:01:58 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_HPP
#define BSP_HPP

#include "Point.hpp"

/**
 * @brief Test appartenance point triangle
 * @param a, b, c: sommets triangle
 * @param point: point tester
 * @return Booléen appartenance
 */
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
