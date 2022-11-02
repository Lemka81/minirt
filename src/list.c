/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaggard <ohaggard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:42:13 by ohaggard          #+#    #+#             */
/*   Updated: 2022/01/21 16:42:13 by ohaggard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_list	*create_list(t_obj *data)
{
	t_list	*out;

	out = malloc(sizeof(t_list));
	if (!out)
		return (0);
	out->data = data;
	out->next = 0;
	return (out);
}

int	push_back(t_list **start, t_obj *data)
{
	if (!*start)
	{
		*start = create_list(data);
		if (!start)
			return (1);
		return (0);
	}
	while ((*start)->next)
		start = &((*start)->next);
	(*start)->next = create_list(data);
	if (!(*start)->next)
		return (1);
	return (0);
}

int	get_list_size(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	free_list(t_list *lst)
{
	t_list	*next;

	if (!lst)
		return ;
	while (lst)
	{
		next = lst->next;
		free(lst->data);
		free(lst);
		lst = next;
	}
}
