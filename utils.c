/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:50:00 by nde-mace          #+#    #+#             */
/*   Updated: 2026/06/09 14:35:52 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libt/libft/libft.h"
#include "push_swap.h"

double	ft_chaos(const int *numbers, int len)
{
	int	j;
	int	k;
	int	hits;
	int	mistakes;

	k = 0;
	hits = 0;
	mistakes = 0;
	if (!numbers || len <= 1)
		return (0.0);
	while (k < len)
	{
		j = k + 1;
		while (j < len)
		{
			if (numbers[k] > numbers[j++])
				mistakes++;
			else
				hits++;
		}
		k++;
	}
	return ((double)hits / (hits + mistakes));
}

void	orchestration_sorting(t_stack **a, t_stack **b, int len, int *numbers)
{
	double	taxa_chaos;

	taxa_chaos = ft_chaos(numbers, len);
	if (taxa_chaos < 0.2)
		ft_sort_small(a, b);
	else if (taxa_chaos <= 0.5)
		ft_sort_mechanical(a, b);
	else
		ft_sort_complex(a, b);
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
		min_pos = ft_find_min_pos(*a);
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
				min_pos = ft_find_min_pos(*a);
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
