/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:11:59 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/28 16:21:55 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

/**
 * @brief Classe représentant un nombre à virgule fixe
 */
class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif


