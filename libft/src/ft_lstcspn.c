/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:00:14 by sueno-te          #+#    #+#             */
/*   Updated: 2024/03/02 02:00:15 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstcspn(t_list *lst, const char *reject)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count = 0;
	while (lst != NULL)
	{
		i = 0;
		while (((unsigned char *)lst->content)[i] != '\0')
		{
			j = 0;
			while (reject[j] != '\0')
			{
				if (((unsigned char *)lst->content)[i] == reject[j])
					return (count);
				j++;
			}
			count++;
			i++;
		}
		lst = lst->next;
	}
	return (count);
}
