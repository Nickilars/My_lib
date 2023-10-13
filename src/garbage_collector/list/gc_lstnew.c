/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:32:17 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/13 14:46:19 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_list	*gc_lstnew(void *data, t_list **trash_lst)
{
	t_list	*list;

	list = my_malloc(0, sizeof(t_list), trash_lst);
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}
