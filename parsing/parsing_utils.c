/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 16:05:05 by adrperei          #+#    #+#             */
/*   Updated: 2026/08/07 16:05:07 by adrperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsing.h"
#include "ft_utils.h"
#include <limits.h>

// compara duas strings char por char, retorna 1 se forem identicas
// usado pra identificar flags como "--simple", "--bench", etc
int	match_flag(const char *arg, const char *ref)
{
	int	i; // anda nas duas strings ao mesmo tempo

	i = 0;
	while (ref[i])
	{
		if (arg[i] != ref[i])
			return (0); // diferenca encontrada, nao eh igual
		i++;
	}
	return (arg[i] == '\0'); // garante que arg acabou junto com ref
}

// retorna 1 se o value ja existe na stack, 0 se nao
// anda pela lista circular usando o contador de tamanho
int	has_duplicate(t_stack *a, int value)
{
	t_node	*node; // bookmark pra andar na lista
	int		pos; // contador de quantos nodes ja olhamos

	if (!a || a->size == 0) // stack vazia ou nao existe, nada duplicado
		return (0);
	node = a->top; // comeca no topo
	pos = 0;
	while (pos < a->size)
	{
		if (node->content == value)
			return (1); // achou duplicado
		node = node->next; // vai pro proximo
		pos++;
	}
	return (0); // deu a volta inteira, nada duplicado
}

// parte do is_valid_int: consome digitos e acumula o numero
// i e result sao ponteiros porque o is_valid_int precisa dos valores atualizados
static int	parse_digits(const char *str, int *i, long *result, int sign)
{
	while (ft_isdigit(str[*i]))
	{
		*result = *result * 10 + (str[*i] - '0'); // converte char pra numero
		if (*result * sign > INT_MAX || *result * sign < INT_MIN)
			return (0); // overflow, numero muito grande
		(*i)++;
	}
	return (1); // todos os digitos consumidos sem overflow
}

// nosso atoi seguro: retorna 1 se a string for um int valido
// escreve o valor convertido em *value
// rejeita overflow, caracteres invalidos, strings vazias
int	is_valid_int(const char *str, int *value)
{
	long	result; // acumulador, long pra detectar overflow antes do cast
	int		sign; // 1 ou -1
	int		i; // indice andando na string

	sign = 1;
	result = 0;
	i = 0;
	while (ft_isspace(str[i])) // pula espacos no inicio
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-') // se for '-', inverte o sinal
			sign = -1;
	if (!ft_isdigit(str[i])) // depois do sinal, precisa ter numero
		return (0);
	if (!parse_digits(str, &i, &result, sign)) // acumula os digitos
		return (0);
	while (ft_isspace(str[i])) // pula espacos no final (ex: " 123 ")
		i++;
	if (str[i] != '\0') // se sobrou alguma coisa, nao eh valido
		return (0);
	*value = (int)(result * sign); // cast seguro, overflow ja foi verificado
	return (1);
}
