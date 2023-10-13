/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:29:27 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/13 14:45:07 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	**new_split(char const *s, char c, t_list **trash);
static char	*word_cpy(const char *str, int start, int fin, t_list **lst);
static int	nb_char(const char *str, char c);

char	**gc_split(char const *s, char c, t_list **trash)
{
	char	**split;
	t_list	*new_node;

	if (!*s)
		return (0);
	split = new_split(s, c, trash);
	new_node = gc_lstnew(&split, trash);
	ft_lstadd_back(trash, new_node);
	return (split);
}

static char	**new_split(char const *s, char c, t_list **trash)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((nb_char(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_cpy(s, index, i, trash);
			index = -1;
		}
	}
	split[j] = 0;
	return (split);
}

static char	*word_cpy(const char *str, int start, int fin, t_list **lst)
{
	char	*word;
	int		i;

	i = 0;
	word = my_malloc((fin - start + 1), sizeof(char), lst);
	while (start < fin)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static int	nb_char(const char *str, char c)
{
	int	i;
	int	sep;

	i = 0;
	sep = 0;
	while (*str)
	{
		if (*str != c && sep == 0)
		{
			sep = 1;
			i++;
		}
		else if (*str == c)
			sep = 0;
		str++;
	}
	return (i);
}

