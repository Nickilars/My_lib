/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:54:29 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/13 14:19:47 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*my_malloc(size_t size, size_t type, t_list **trash)
{
	char	*str;
	t_list	*new;

	if (size > 0)
	{
		str = malloc(size * type);
		if (!str)
			return (0);
	}
	else
	{
		str = malloc(type);
		if (!str)
			return (0);
	}
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->data = &str;
	ft_lstadd_back(trash, new);
	printf("Nb ptr: %d\n", ft_lstsize(*trash));
	return (str);
}
