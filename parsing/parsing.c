/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:20:35 by sarahbanko        #+#    #+#             */
/*   Updated: 2026/07/30 17:44:45 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

int *ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;

	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (!ft_isdigit(nptr[i + 1]))
			return (0);
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}

int parsing(int argc, char **argv)
{
    int i;
    char **arguments;
    int * numbers;

    i = 0;
    if (argc == 1) // ./push_swap 
        return (0);
    if (argc == 2) // ./push_swap " " // ./push_swap ""
    {
        if (is_empty_or_onlyspace(argv[1]))
        {
            write(2, "Error\n", 6);
            return (0);
        }
        arguments = ft_split(argv[1], ' '); // lembrar do free
        int *int_args = malloc(sizeof(int) * ft_strlen(arguments));
        if (has_duplicate(arguments))
        {
            write(2, "Error\n", 6);
            return (0);
        }
        else 
        {
            numbers = ft_atoi(arguments);
            // verifica se tem letra
            // trata sinal (sinal seguido para o msm numero, ex --, invalido)
            // 
        }
        
    }

    return (0);
}

void atoi_adaptive(char **str, int *result)
{
	int	i;
	int	j;
	int sign;
	int acc;

	sign = 1;
	i = 0;
	acc = 0;
	while (str[i] != NULL)
	{
		while ((str[i][j] >= 9 && str[i][j] <= 13) || str[i][j] == ' ')
			i++;
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] != '-' && str[i][j] != '+' && !ft_isdigit(str[i][j]))
				return ;
			if ((str[i][j] == '+' || str[i][j] == '-'))
			{
				if (!(j == 0))
					return ;

				else
				{
					if (str[i][j] == '-')
						sign = -sign;
				}
			}
			if (str[i][j] >= '0' && str[i][j] <= '9')
			{
				acc = (acc * 10) + (str[i][j] - '0');
			}
			
			j++;
		}
		result[i] = sign * acc;
		sign = 1;
		acc = 0;
		i++;
	}
}

int main() 
{
    char *s[] = {"-10", "50", NULL};

	int result[ft_strlen(s)];

    int size = sizeof(s) / sizeof(s[0]);

    atoi_adaptive(s, result);

    int i = 0;
    while (i < size) printf("%d ", result[i++]);

    return 0;
}