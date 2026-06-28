/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_t_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 12:49:05 by nde-mace          #+#    #+#             */
/*   Updated: 2026/06/28 16:30:34 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

long    ft_atol(const char *str)
{
    long sign;
    long result;
    int i;

    sign = 1;
    result = 0;
    i = 0;
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i]>= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        if (result > __INT_MAX__) 
            return (result * sign);
        i++;
    }
    if ((result * sign) > 2147483647 || (result * sign) < -2147483647)
        return(3000000000);
    return(result * sign);
}

t_stack *ft_newstack(long n)
{
    t_stack *new_nbr;
        
    new_nbr = malloc(sizeof(t_stack));
        if (!new_nbr)
            return (NULL);
    new_nbr->value = n;
    new_nbr->index = 0;
    new_nbr->next = NULL;
    new_nbr->prev = NULL;
    return(new_nbr);
}

t_stack *ft_init_stack(t_stack **a, int *numbers, int len_numbers)
{
   int      i;
   t_stack *new_node;
   t_stack *temp;
   
   i = 0;
   while(i < len_numbers)
   {
    new_node = ft_newstack(numbers[i]);
    if(!new_node)
        return (NULL);
    if(*a == NULL)
    {
        *a = new_node;
        temp = *a;
        
    }
    else
    {
        temp->next = new_node;
        new_node->prev = temp;
        temp = new_node;
    }
    i++;
   }
   return (*a);
}
void    ft_free_stack(t_stack **a)
{
    t_stack *temp;
    t_stack *atual;
    
    temp = *a;
    while(temp != NULL)
    {
        atual = temp;
        temp = temp->next;
        free(atual);
    }
    *a = NULL;
}