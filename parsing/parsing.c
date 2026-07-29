/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarahbanko <sarahbanko@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:20:35 by sarahbanko        #+#    #+#             */
/*   Updated: 2026/07/28 14:02:48 by sarahbanko       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc == 1) // não passa nada, apenas o nome do programa 
        return (0);
    i = 0;
    if (argc == 2)
    {
        if (argv[1][0] == '\0')
        {
            write(2, "Error\n", 6);
            return (0);
        }
        else
        {
            
        }
    }
    
    while (i < argc)
    {
        j = 0;
        // pensar ainda
    }
}