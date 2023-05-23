/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_newcontent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:20:14 by nrossel           #+#    #+#             */
/*   Updated: 2023/05/23 15:09:24 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_node	*ft_dlst_newcontent(void *data, t_list **trash_lst)
{
	t_node	*new_node;
	int		*data_mllc;

	new_node = my_malloc(0, sizeof(t_node), trash_lst);
	data_mllc = my_malloc(0, sizeof(void), trash_lst);
	if (!new_node || !data_mllc)
		return (0);
	data_mllc = data;
	new_node->data = data_mllc;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
