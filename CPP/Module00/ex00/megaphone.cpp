/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:30:46 by marigome          #+#    #+#             */
/*   Updated: 2025/01/09 19:31:50 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // Proporciona herramientas para la entrada y salida estándar
#include <string> // Soporte para manipular cadena de carácteres (size(), substr(), string)
#include <locale> // Soporte para configuraciones locales (Formatos de números, fechas y carácteres específicos)
#include <stdio.h> // Librería heredada de C que proporciona funciones básicas de entrada/salida (printf)

/*  Salida estándar en C++
 
    std::cout es el flujo de salida estándar en C++.
    Se utiliza para imprimir datos en la consola.
    Proviene de la biblioteca <iostream> y pertenece al espacio de nombres estándar (std), por lo que es necesario usar el prefijo std::.
    Ej -> std::cout << MENSAJE << std::endl;


    << std::endel
    
    std::endl es un manipulador de flujo en C++.
    Significa "end line" (fin de línea) y se utiliza para:
    Insertar un carácter de nueva línea (\n) en el flujo de salida.
    Forzar el vaciado del búfer de salida (flush).

    Diferencias entre <<std::endl y /n
    
    std::endl:
    Inserta un salto de línea.
    Limpia (vacía) el búfer del flujo de salida, asegurando que todo lo enviado con std::cout se muestre inmediatamente.

    \n:
    Solo inserta un salto de línea, sin limpiar el búfer.

    */

   int  main(int argc, char **argv)
   {
        if (argc != 2)
            std::cout << "Please insert just one argument" << std::endl;
        
        char *input = argv[1];
        for (int i = 0; input[i++]; i != '\0')
        {
            input[i] = std::toupper(input[i]);
        }
        
   }