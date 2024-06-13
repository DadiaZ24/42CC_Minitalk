/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:17:39 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/04/28 13:17:39 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	receive_message(int bitsignal)
{
	static int				bit;
	static unsigned char	c;
	static char				*msg;

	if (!msg)
		msg = NULL;
	if (bitsignal == SIGUSR1)
		c = c | (1 << bit);
	bit += 1;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_printf("%s", msg);
			free(msg);
			msg = NULL;
		}
		else
			msg = ft_minijoin(msg, c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	char	*error;
	char	*error2;

	error = "\033[0;31mERROR: You should only use './server'";
	error2 = " and nothing more!\n";
	(void)argv;
	error = ft_strjoin(error, error2);
	if (argc != 1)
		return (ft_printf("%s", error));
	free(error);
	welcome_message();
	ft_printf("Waiting for client interaction...\n\033[1;32m");
	while (1)
	{
		signal(SIGUSR1, receive_message);
		signal(SIGUSR2, receive_message);
	}
	return (0);
}
