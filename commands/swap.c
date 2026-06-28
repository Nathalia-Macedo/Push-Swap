/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 12:16:03 by nde-mace          #+#    #+#             */
/*   Updated: 2026/06/27 12:52:25 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*primeiro;
	t_stack	*segundo;

	if (!a || !*a || !(*a)->next)
		return ;
	primeiro = *a;
	segundo = primeiro->next;
	primeiro->next = segundo->next;
	if (segundo->next)
		segundo->next->prev = primeiro;
	segundo->prev = primeiro->prev;
	segundo->next = primeiro;
	primeiro->prev = segundo;
	*a = segundo;
}

void	sb(t_stack **b)
{
	t_stack	*primeiro;
	t_stack	*segundo;

	if (!b || !*b || !(*b)->next)
		return ;
	primeiro = *b;
	segundo = primeiro->next;
	primeiro->next = segundo->next;
	if (segundo->next)
		segundo->next->prev = primeiro;
	segundo->prev = primeiro->prev;
	segundo->next = primeiro;
	primeiro->prev = segundo;
	*b = segundo;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
