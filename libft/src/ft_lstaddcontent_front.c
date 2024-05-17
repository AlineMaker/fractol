/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddcontent_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:00:07 by sueno-te          #+#    #+#             */
/*   Updated: 2024/03/02 02:00:08 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddcontent_front(t_list **lst, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return (NULL);
	ft_lstadd_front(lst, new);
	return (new);
}
