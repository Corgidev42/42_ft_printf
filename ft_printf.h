/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:15:24 by dev               #+#    #+#             */
/*   Updated: 2025/02/13 10:05:47 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

/**
 * @brief Écrit un caractère sur la sortie standard.
 *
 * @param c Le caractère à écrire.
 * @return Le nombre d'octets écrits (toujours 1).
 */
int		ft_putchar(unsigned char c);

/**
 * @brief Écrit une chaîne de caractères sur la sortie standard.
 *
 * @param s La chaîne de caractères à écrire.
 * @return Le nombre de caractères écrits. Écrit "(null)" si la chaîne est NULL.
 */
int		ft_putstr(char *s);

/**
 * @brief Affiche un pointeur sous forme hexadécimale précédé de "0x".
 *
 * @param ptr L'adresse mémoire à afficher.
 * @return Le nombre de caractères écrits.
 */
int		ft_putptr(unsigned long ptr);

/**
 * @brief Affiche un entier signé sur la sortie standard.
 *
 * @param n L'entier à afficher.
 * @return Le nombre de caractères écrits.
 */
int		ft_putnbr(int n);

/**
 * @brief Affiche un entier non signé sur la sortie standard.
 *
 * @param n L'entier non signé à afficher.
 * @return Le nombre de caractères écrits.
 */
int		ft_putunbr(unsigned int n);

/**

	* @brief Calcule le nombre de caractères nécessaires pour afficher un entier signé.
 *
 * @param n L'entier dont on veut connaître la taille.
 * @return Le nombre de caractères nécessaires pour afficher l'entier.
 */
int		number_size(int n);

/**

	* @brief Calcule le nombre de caractères nécessaires pour afficher un entier non signé.
 *
 * @param n L'entier non signé dont on veut connaître la taille.
 * @return Le nombre de caractères nécessaires pour afficher l'entier.
 */
int		unsigned_number_size(unsigned int n);

/**
 * @brief Affiche un entier non signé en base hexadécimale en minuscules.
 *
 * @param n L'entier non signé à afficher en hexadécimal.
 * @return Le nombre de caractères écrits.
 */
int		ft_putnbrhexlow(unsigned int n);

/**
 * @brief Affiche un entier non signé en base hexadécimale en majuscules.
 *
 * @param n L'entier non signé à afficher en hexadécimal.
 * @return Le nombre de caractères écrits.
 */
int		ft_putnbrhexup(unsigned int n);

/**
 * @brief Gère les conversions des spécificateurs de format pour ft_printf.
 *

	* Cette fonction est utilisée en interne par ft_printf pour traiter les différents
 * spécificateurs de format (c, s, d, i, u, x, X, p, %).
 *
 * @param format Le caractère de spécification de format.
 * @param args La liste des arguments variadiques.
 * @param num Un pointeur sur le compteur de caractères affichés.
 */
void	ft_printf_conversions(char format, va_list *args, int *num);

/**
 * @brief Une version personnalisée de la fonction printf.
 *
 * Cette fonction affiche une chaîne formatée sur la sortie standard,
	en prenant en charge
 * les spécificateurs suivants : %c, %s, %p, %d, %i, %u, %x, %X, %%.
 *
 * @param format La chaîne de format contenant le texte et les spécificateurs.
 * @param ... Les arguments correspondants aux spécificateurs.
 * @return Le nombre total de caractères affichés.
 */
int		ft_printf(const char *format, ...);
#endif
