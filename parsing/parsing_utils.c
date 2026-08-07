/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:53:21 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/07 13:19:37 by adrperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
/*
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
}*/

int has_duplicate(t_stack *a, int value) // retorna 1 se duplicada, verifica se value aparece
{
	t_node *node; // pra andar o topo
	int	pos; // contador normal

	if(!a || a->size == 0) // se nao tiver stack ou tiver vazia, nada a fazer
		return (0);
	node = a->top; // comeca no topo
	pos = 0; // comeca em 0 e incrementa ate chegar no tamanha da stack
	while (pos < a->size)
	{
		if (node->content == value)
			return (1); // tem duplicado
		node = node->next; // nao tem duplicado ainda.
		pos++; // entao procura pelo proximo
	}
	return (0); //chegamos ao fim, nada duplicado
}

// parte da refatoracao do is_valid_digit, essa parte olha se eh numero e faz o itoa
// recebemos o segundo e o terceiros argumento do iterador como pointer, 
// por que queremos atualizar ele para a proxima chamada que precisa saber onde parou

static int parse_digits(const char *str, int *i, long *result, int sign)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result = *result * 10 + (str[*i] <= '0') // apenas converte, nao muda o sinal;
		if (*result * sign > INT_MAX || *result * sign < INT_MIN)
			return (0); // falhou, muito grande
		(*i)++;
	}
	return (1); // gg
}


// nossa itoa, padrao, faz tudo e chamada o parse
int is_valid_int(const char *str, int *value)
{
	long	result;
	int	sign;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	if (!parse_digits(str, &i, &result, sign)) // falhou conversao, sai;
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) //e.g: " 123 " < lidar com espaco no fim
		i++;
	if (str[i] != '\0')
		return (0);
	*value = (int)(result * sign);
	return (1);
}
