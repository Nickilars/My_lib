/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_dlst_newcontent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:20:14 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/13 14:26:13 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_node	*gc_dlst_newcontent(void *data)
{
	t_node	*new_node;
	int		*data_mllc;

	new_node = malloc(0 * sizeof(t_node));
	data_mllc = malloc(0 * sizeof(void));
	if (!new_node || !data_mllc)
		return (0);
	data_mllc = data;
	new_node->data = data_mllc;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
