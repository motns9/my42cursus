/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:26:43 by msbita            #+#    #+#             */
/*   Updated: 2025/04/26 16:26:44 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_head;
	t_list	*new_node;
	void	*mapped_content;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	new_list_head = NULL;
	current = lst;
	while (current)
	{
		mapped_content = f(current->content);
		new_node = ft_lstnew(mapped_content);
		if (!new_node)
		{
			del(mapped_content);
			ft_lstclear(&new_list_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list_head, new_node);
		current = current->next;
	}
	return (new_list_head);
}
