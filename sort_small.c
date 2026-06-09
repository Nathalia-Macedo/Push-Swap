/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:45:03 by nde-mace          #+#    #+#             */
/*   Updated: 2026/06/09 14:57:17 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	int	n1;
	int	n2;
	int	n3;

	if (!a || !*a)
		return ;
	n1 = (*a)->value;
	n2 = (*a)->next->value;
	n3 = (*a)->next->next->value;
	if (n1 > n2 && n2 > n3)
	{
		sa(a);
		rra(a);
	}
	else if (n1 > n2 && n3 > n1)
		sa(a);
	else if (n1 > n3 && n3 > n2)
		ra(a);
	else if (n1 > n3 && n2 > n3)
		rra(a);
	return ;
}
