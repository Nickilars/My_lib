/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:02:02 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/13 14:26:35 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*gc_strjoin(char const *s1, char const *s2, t_list **trash)
{
	size_t		len_max;
	size_t		i;
	size_t		j;
	char		*str;

	len_max = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	str = my_malloc(len_max, sizeof(char), trash);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] && i < len_max)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && j < len_max)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}

/*int	main (int argc, char **argv)
{
	(void) argc;
	{
		char *str1 = argv[1];
		char *str2 = argv[2];
		char *ret = ft_strjoin(str1, str2);
		printf("%s", ret);
	}
}*/
