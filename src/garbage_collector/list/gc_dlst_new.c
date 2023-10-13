/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:10:54 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/13 14:26:06 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_dlist	*gc_dlst_new(t_list **trash_lst)
{
	t_dlist	*new_list;

	new_list = my_malloc(0, sizeof(t_dlist), trash_lst);
	if (!new_list)
		return (0);
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->len = 0;
	return (new_list);
}
