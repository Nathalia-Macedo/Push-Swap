/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:50:00 by nde-mace          #+#    #+#             */
/*   Updated: 2026/06/28 15:18:46 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (!ft_isdigit(str[i]))
			return (ft_error());
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (ft_error());
		i++;
	}
	return (1);
}

int	ft_is_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strncmp(argv[i], argv[j], 11) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int ft_check_all_numbers(int argc, char **argv)
{	
	int	i;
	
	i = 1;
    while (i < argc)
    {
        if (!ft_isnumber(argv[i]))
            return (0);
        i++;
    }
	return (1);
}
int	*ft_valid(int argc, char **argv)
{
	int	i;
	int	*dest;
	long num;

	if (argc < 2 || !ft_check_all_numbers(argc, argv) || !ft_is_dup(argc, argv))
		return (NULL);
	dest = (int *)malloc(sizeof(int) * (argc - 1));
	if (!dest)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num == 3000000000L)
		{
			free(dest);
			ft_error();
			return (NULL);
		}
		dest[i - 1] = num;
		i++;
	}
	return (dest);
}