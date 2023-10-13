/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:55:37 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/13 14:50:41 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*gc_calloc(size_t size, size_t type, t_list **trash)
{
	char	*str;

	str = my_malloc(size, type, trash);
	if (!str)
		return (str);
	ft_bzero(str, type * size);
	return (str);
}
