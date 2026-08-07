/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:46:49 by adrperei          #+#    #+#             */
/*   Updated: 2026/08/07 15:46:53 by adrperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// calcula o tamanho total de caracteres juntando todos os argv
// pulamos o argv[0] (nome do programa) e somamos +1 pra cada
// espaco entre os argumentos
static int	args_total_len(int argc, char **argv)
{
	int	total; // soma total de caracteres
	int	i; // qual argumento estamos vendo
	int	j; // anda dentro do argumento

	total = 0;
	i = 1; // comeca do primeiro argumento de verdade
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			j++;
		total += j + 1; // +1 pelo espaco entre argumentos
		i++;
	}
	return (total);
}

// junta todos os argv em uma string so, separados por espaco
// isso serve pra tratar "./push_swap "1 2" 3" como "1 2 3"
static char	*join_args(int argc, char **argv)
{
	char	*joined; // a string gigante com tudo junto
	int		i; // qual argumento
	int		j; // posicao dentro do argumento
	int		pos; // posicao dentro da string final

	joined = (char *)malloc(args_total_len(argc, argv) + 1);
	if (!joined)
		return (NULL);
	pos = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			joined[pos++] = argv[i][j++];
		if (i < argc - 1) // nao coloca espaco depois do ultimo
			joined[pos++] = ' ';
		i++;
	}
	joined[pos] = '\0';
	return (joined);
}

// monta o novo array de argumentos no formato que o parse_args espera
// dst[0] = argv[0] (nome do programa), o resto = os tokens do split
static char	**build_dst(char **split, int count, char **argv, int *out_argc)
{
	char	**dst; // novo array de argumentos
	int		j; // contador pra copiar

	dst = (char **)malloc(sizeof(char *) * (count + 2));
	if (!dst)
		return (NULL);
	dst[0] = argv[0]; // copia o nome do programa
	j = 0;
	while (j < count)
	{
		dst[j + 1] = split[j];
		j++;
	}
	dst[count + 1] = NULL;
	*out_argc = count + 1; // +1 porque tem o argv[0] no inicio
	return (dst);
}

// funcao principal: transforma qualquer formato de input
// (ex: "1 2" 3 ou 1 2 3) em um argv padronizado
// que o parse_args consegue ler sem problema
char	**build_args(int argc, char **argv, int *out_argc)
{
	char	*joined; // todos os argv colados em uma string
	char	**split; // resultado do ft_split
	char	**dst; // o array final que vamos retornar
	int		i; // conta quantos tokens o split gerou

	joined = join_args(argc, argv);
	if (!joined)
		return (NULL);
	split = ft_split(joined, ' ');
	free(joined); // ja fizemos o split, nao precisa mais da string colada
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
		i++;
	if (i == 0 && argc > 1) // so tinha espacos, nada valido
	{
		ft_free_split(split);
		write(2, "Error\n", 6);
		return (NULL);
	}
	dst = build_dst(split, i, argv, out_argc);
	free(split); // o build_dst copiou os ponteiros, nao precisa mais do array
	return (dst);
}
