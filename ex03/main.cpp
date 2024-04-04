/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:42:50 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/04 15:02:22 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

/**
 * @brief Main test fonction bsp
 * @details Instanciation points, tests appartenance triangle
 */
int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(0.0f, 3.0f);
	Point c(4.0f, 0.0f);

	Point inside(1.0f, 1.0f);
	Point outside(4.0f, 3.0f);
	Point edge(0.0f, 1.5f);
	Point vertex(0.0f, 0.0f);

	std::cout << "Inside: " << (bsp(a, b, c, inside) ? "True" : "False") << std::endl;
	std::cout << "Outside: " << (bsp(a, b, c, outside) ? "True" : "False") << std::endl;
	std::cout << "Edge: " << (bsp(a, b, c, edge) ? "True" : "False") << std::endl;
	std::cout << "Vertex: " << (bsp(a, b, c, vertex) ? "True" : "False") << std::endl;

	return 0;
}
