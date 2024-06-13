/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minijoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:44:34 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/25 17:44:34 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_minijoin(char *s1, char c)
{
	char	*newstring;
	int		i;
	int		size;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	size = ft_strlen(s1) + 1;
	newstring = (char *)malloc(sizeof(char) * (size + 1));
	if (!newstring)
		return (0);
	i = -1;
	while (++i < size - 1)
		newstring[i] = s1[i];
	newstring[i] = c;
	newstring[++i] = '\0';
	if (s1)
		free(s1);
	return (newstring);
}
