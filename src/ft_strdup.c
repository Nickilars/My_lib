/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:21:49 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/13 14:09:49 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*s_cpy;

	i = 0;
	len = ft_strlen(s1);
	s_cpy = malloc((len + 1) * sizeof(char));
	if (!s_cpy)
		return (0);
	while (i <= len && s1[i])
	{
		s_cpy[i] = s1[i];
		i++;
	}
	s_cpy[i] = 0;
	return (s_cpy);
}
