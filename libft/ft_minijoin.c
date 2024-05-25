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

char	*ft_minijoin(char *str, char c)
{
	char	*newstring;
	int		i;
	int		size;

	if (!str)
    {
        str = malloc(sizeof(char));
        str[0] = '\0';
    }
	size = ft_strlen(str) + 1;
	newstring = (char *)malloc(sizeof(char) * (size + 1));
	if (!newstring)
		return (0);
	i = -1;
	while (str[i])
		newstring[i] = str[i];
	newstring[++i] = c;
	newstring[++i] = '\0';
	if (str)
    	free(str);
	return (newstring);
}
