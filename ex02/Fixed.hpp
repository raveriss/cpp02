/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:41:54 by raveriss          #+#    #+#             */
/*   Updated: 2024/04/04 14:47:43 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

/**
 * @brief Constructeur par défaut de la classe Fixed
 */
class Fixed {
private:
    /**
     * @brief Valeur du nombre fixe
     */
    int                 _value;

    /**
     * @brief Nombre de bits fractionnaires
     */
    static const int    _fractionalBits = 8;

public:
    /**
     * @brief Constructeur par défaut
     */
    Fixed();

    /**
     * @brief Constructeur à partir d'un entier
     * @param integer: Valeur entière
     */
    Fixed(const int integer);

    /**
     * @brief Constructeur à partir d'un flottant
     * @param floatingPoint: Valeur flottante
     */
    Fixed(const float floatingPoint);

    /**
     * @brief Constructeur de copie
     * @param src: Objet à copier
     */
    Fixed(const Fixed & src);

    /**
     * @brief Opérateur d'affectation
     * @param rhs: Objet à affecter
     * @return Référence sur l'objet courant
     */
    Fixed & operator=(const Fixed & rhs);

    /**
     * @brief Destructeur
     */
    ~Fixed();

    /**
     * @brief Opérateur de comparaison supérieur
     * @param rhs: Objet à comparer
     * @return Résultat de la comparaison
     */
    bool operator>(const Fixed & rhs) const;

    /**
     * @brief Opérateur de comparaison inférieur
     * @param rhs: Objet à comparer
     * @return Résultat de la comparaison
     */
    bool operator<(const Fixed & rhs) const;

    /**
     * @brief Opérateur de comparaison supérieur ou égal
     * @param rhs: Objet à comparer
     * @return Résultat de la comparaison
     */
    bool operator>=(const Fixed & rhs) const;

    /**
     * @brief Opérateur de comparaison inférieur ou égal
     * @param rhs: Objet à comparer
     * @return Résultat de la comparaison
     */
    bool operator<=(const Fixed & rhs) const;

    /**
     * @brief Opérateur d'égalité
     * @param rhs: Objet à comparer
     * @return Résultat de la comparaison
     */
    bool operator==(const Fixed & rhs) const;

    /**
     * @brief Opérateur de différence
     * @param rhs: Objet à comparer
     * @return Résultat de la comparaison
     */
    bool operator!=(const Fixed & rhs) const;

    /**
     * @brief Opérateur d'addition
     * @param rhs: Opérande de droite
     * @return Résultat de l'addition
     */
    Fixed operator+(const Fixed & rhs) const;

    /**
     * @brief Opérateur de soustraction
     * @param rhs: Opérande de droite
     * @return Résultat de la soustraction
     */
    Fixed operator-(const Fixed & rhs) const;

    /**
     * @brief Opérateur de multiplication
     * @param rhs: Opérande de droite
     * @return Résultat de la multiplication
     */
    Fixed operator*(const Fixed & rhs) const;

    /**
     * @brief Opérateur de division
     * @param rhs: Opérande de droite
     * @return Résultat de la division
     */
    Fixed operator/(const Fixed & rhs) const;

    /**
     * @brief Opérateur d'incrémentation préfixe
     * @return Référence sur l'objet courant
     */
    Fixed & operator++();

    /**
     * @brief Opérateur d'incrémentation postfixe
     * @return Copie de l'objet avant incrémentation
     */
    Fixed operator++(int);

    /**
     * @brief Opérateur de décrémentation préfixe
     * @return Référence sur l'objet courant
     */
    Fixed & operator--();

    /**
     * @brief Opérateur de décrémentation postfixe
     * @return Copie de l'objet avant décrémentation
     */
    Fixed operator--(int);

    /**
     * @brief Minimum de deux nombres fixes
     * @param a: Premier nombre
     * @param b: Deuxième nombre
     * @return Référence sur le plus petit nombre
     */
    static Fixed & min(Fixed & a, Fixed & b);

    /**
     * @brief Minimum de deux nombres fixes constants
     * @param a: Premier nombre
     * @param b: Deuxième nombre
     * @return Référence constante sur le plus petit nombre
     */
    static const Fixed & min(const Fixed & a, const Fixed & b);

    /**
     * @brief Maximum de deux nombres fixes
     * @param a: Premier nombre
     * @param b: Deuxième nombre
     * @return Référence sur le plus grand nombre
     */
    static Fixed & max(Fixed & a, Fixed & b);

    /**
     * @brief Maximum de deux nombres fixes constants
     * @param a: Premier nombre
     * @param b: Deuxième nombre
     * @return Référence constante sur le plus grand nombre
     */
    static const Fixed & max(const Fixed & a, const Fixed & b);

    /**
     * @brief Récupérer la valeur brute du nombre fixe
     * @return Valeur brute
     */
    int getRawBits(void) const;

    /**
     * @brief Définir la valeur brute du nombre fixe
     * @param raw: Nouvelle valeur brute
     */
    void setRawBits(int const raw);

    /**
     * @brief Convertir le nombre fixe en flottant
     * @return Valeur flottante
     */
    float toFloat(void) const;

    /**
     * @brief Convertir le nombre fixe en entier
     * @return Valeur entière
     */
    int toInt(void) const;

};

/**
 * @brief Opérateur de flux de sortie
 * @param out: Flux de sortie
 * @param value: Nombre fixe à afficher
 * @return Flux de sortie modifié
 */
std::ostream & operator<<(std::ostream & out, const Fixed & value);

#endif
