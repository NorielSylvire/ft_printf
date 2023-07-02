/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:28:54 by fhongu            #+#    #+#             */
/*   Updated: 2023/04/09 22:26:53 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*retcopy;

	if (!lst)
		return (NULL);
	ret = ft_calloc(1, sizeof (t_list));
	if (!ret)
		return (NULL);
	retcopy = ret;
	while (lst != NULL)
	{
		retcopy->content = (*f)(lst->content);
		if (lst->next != NULL)
			retcopy->next = ft_calloc(1, sizeof (t_list));
		else
			break ;
		if (!retcopy->next)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		retcopy = retcopy->next;
		lst = lst->next;
	}
	return (ret);
}
