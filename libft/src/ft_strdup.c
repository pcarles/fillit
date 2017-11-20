/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:09:15 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/10 14:58:40 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char const *s1)
{
	char	*p;

	p = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (p)
	{
		return (ft_strcpy(p, s1));
	}
	return (NULL);
}
