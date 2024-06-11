/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:44:04 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/11 11:40:03 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!*s1 || *s1 != *s2)
		return ((t_u8)(*s1) - (t_u8)(*s2));
	return (ft_strcmp(s1 + 1, s2 + 1));
}
