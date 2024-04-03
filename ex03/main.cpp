/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:42:50 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/03 22:56:43 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Fixed.hpp"
// #include <iostream>

// int main( void ) {
//     Fixed           a;
//     Fixed const     b( Fixed( 5.05f ) * Fixed( 2 ) );
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

/**
 * @brief Test appartenance point triangle
 * @param a, b, c: sommets triangle
 * @param point: point tester
 * @return Booléen appartenance
 */
bool bsp(Point const a, Point const b, Point const c, Point const point);

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
