/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanko <sbanko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by sbanko            #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by sbanko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// escreve uma string inteira no file descriptor fd
// se a string for NULL, nao faz nada (evita crash)
void	ft_putstr_fd(char *s, int fd)
{
	int	len; // tamanho da string

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

// escreve um numero inteiro no file descriptor fd
// trata o caso especial do INT_MIN separado
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

// retorna 1 se c for um digito ('0' a '9'), 0 caso contrario
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// retorna 1 se c for espaco ou tab (horizontal/vertical/formfeed/carriage)
int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
