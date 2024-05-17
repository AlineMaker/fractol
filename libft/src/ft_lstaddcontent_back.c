/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddcontent_back.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:00:04 by sueno-te          #+#    #+#             */
/*   Updated: 2024/03/02 02:00:05 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddcontent_back(t_list **lst, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return (NULL);
	ft_lstadd_back(lst, new);
	return (new);
}
