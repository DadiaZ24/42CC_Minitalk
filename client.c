/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:34:01 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/04/28 13:34:01 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	send_to_server(int pid, char *str)
{
	int	bit;
	int	i;
	int	strsize;

	i = 0;
	strsize = ft_strlen(str);
	while (i <= strsize)
	{
		bit = 0;
		while (bit < 8)
		{
			if (((str[i] >> bit) & 1))
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			usleep(200);
			bit++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*error;
	char	*error2;

	error = "ERROR: Wrong usage of the program.";
	error2 = "Use './client [PID] [Message]\n";
	error = ft_strjoin(error, error2);
	if (argc != 3)
		return (ft_printf("%s", error));
	free(error);
	i = -1;
	pid = ft_atoi(argv[1]);
	send_to_server(pid, argv[2]);
	return (0);
}
