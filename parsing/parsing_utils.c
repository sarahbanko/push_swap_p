/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:53:21 by sbanko            #+#    #+#             */
/*   Updated: 2026/07/29 16:52:56 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

int    is_empty_or_onlyspace(char *str)
{
    int i;
    
    i = 0;
    if (!str[i])
        return (1);
    while (str[i])
    {
        if (!(str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
            return (0);
        i++;
    }
    return (1);
}

int  has_duplicate(char **str)
{
    int i;
    int j;

	if (!str)
		return (0);
    i = 0;
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if (ft_strcmp(str[i], str[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
