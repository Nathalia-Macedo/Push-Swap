/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 12:52:30 by nde-mace          #+#    #+#             */
/*   Updated: 2026/06/27 13:06:02 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*primeiro;
	t_stack	*segundo;
	t_stack	*ultimo;

	primeiro = *a;
	segundo = primeiro->next;
	ultimo = primeiro;
	while (ultimo->next != NULL)
		ultimo = ultimo->next;
	*a = segundo;
	segundo->prev = NULL;
	ultimo->next = primeiro;
	primeiro->prev = ultimo;
	primeiro->next = NULL;
}

void	rb(t_stack **b)
{
	t_stack	*primeiro;
	t_stack	*segundo;
	t_stack	*ultimo;

	primeiro = *b;
	segundo = primeiro->next;
	ultimo = primeiro;
	while (ultimo->next != NULL)
		ultimo = ultimo->next;
	*b = segundo;
	segundo->prev = NULL;
	ultimo->next = primeiro;
	primeiro->prev = ultimo;
	primeiro->next = NULL;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack **a)
{
	t_stack	*primeiro;
	t_stack	*penultimo;
	t_stack	*ultimo;

	primeiro = *a;
	penultimo = NULL;
	ultimo = primeiro;
	while (ultimo->next != NULL)
	{
		penultimo = ultimo;
		ultimo = ultimo->next;
	}
	ultimo->prev = NULL;
	ultimo->next = primeiro;
	primeiro->prev = ultimo;
	penultimo->next = NULL;
}

void	rrb(t_stack **b)
{
	t_stack	*primeiro;
	t_stack	*penultimo;
	t_stack	*ultimo;

	primeiro = *b;
	penultimo = NULL;
	ultimo = primeiro;
	while (ultimo->next != NULL)
	{
		penultimo = ultimo;
		ultimo = ultimo->next;
	}
	ultimo->prev = NULL;
	ultimo->next = primeiro;
	primeiro->prev = ultimo;
	penultimo->next = NULL;
}
