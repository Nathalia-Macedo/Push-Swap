/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:50:23 by nde-mace          #+#    #+#             */
/*   Updated: 2026/06/03 19:54:38 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libt/libft/libft.h"

int	main(int argc, char **argv)
{
	int		*numeros;
	int		tamanho;
	double	resultado;

	if (argc < 2)
	{
		printf("Uso: ./push_swap [lista de numeros]\n");
		return (0);
	}
	numeros = ft_valid(argc, argv);
	if (!numeros)
		return (1);
	tamanho = argc - 1;
	resultado = ft_chaos(numeros, tamanho);
	printf("Taxa de caos (ordenacao): %f\n", resultado);
	free(numeros);
	return (0);
}
