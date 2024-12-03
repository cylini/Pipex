/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:22:18 by carzhang          #+#    #+#             */
/*   Updated: 2024/06/07 16:27:40 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr -> content = content;
	ptr -> next = NULL;
	return (ptr);
}
/*
int	main(void)
{
	int	a = 12;
	int	*content = &a;

	t_list	*nlist = ft_lstnew(content);
	if ((int *)nlist -> content == content)
	{
		printf("%d\n", *(int *)nlist -> content);
	}
	return (0);
}*/
