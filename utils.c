/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:50:00 by nde-mace          #+#    #+#             */
/*   Updated: 2026/06/28 17:15:46 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
double  ft_chaos(const int *numbers, int len)
{
    int j;
    int k;
    int mistakes;
    int total_pairs;

    k = 0;
    mistakes = 0;
    total_pairs = 0;
    if (!numbers || len <= 1)
        return (0.0);
    while (k < len)
    {
        j = k + 1;
        while (j < len)
        {
            total_pairs++; // Conta cada par testado, exatamente como o assunto pede
            if (numbers[k] > numbers[j])
                mistakes++;
            j++; // Incremento limpo e isolado no fim do loop interno
        }
        k++;
    }
    // Divide os erros pelo total de pares possíveis
    return ((double)mistakes / total_pairs);
}

void	orchestration_sorting(t_stack **a, t_stack **b, int len, int *numbers)
{
	double	taxa_chaos;

	taxa_chaos = ft_chaos(numbers, len);
	if (taxa_chaos < 0.2)
		ft_sort_small(a, b);
	/* else if (taxa_chaos <= 0.5)
		ft_sort_mechanical(a, b);
	else
		ft_sort_complex(a, b); */
}

int	ft_stack_len(t_stack **a)
{
	t_stack	*temp;
	int		count;

	if (*a == NULL)
		return (0);
	temp = *a;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp -> next;
	}
	return (count);
}

void	ft_sort_small(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	middle;

	while (ft_stack_len(a) > 3)
	{
		min_pos = ft_find_min_pos(a);
		middle = ft_stack_len(a) / 2;
		if (min_pos <= middle)
		{
			while (min_pos > 0)
			{
				ra(a);
				min_pos--;
			}
		}
		else
		{
			while (min_pos > 0)
			{
				rra(a);
				min_pos = ft_find_min_pos(a);
			}
		}
		pb(a, b);
	}
}

int	ft_find_min_pos(t_stack **a)
{
	t_stack	*temp;
	int		min;
	int		position_atual;
	int		position_menor;

	temp = *a;
	position_atual = 0;
	position_menor = 0;
	min = (*a)->value;
	while (temp != NULL)
	{
		if ((temp)->value < min)
		{
			min = (temp)->value;
			position_menor = position_atual;
		}
		temp = (temp)->next;
		position_atual++;
	}
	return (position_menor);
}
