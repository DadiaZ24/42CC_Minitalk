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

void send_to_server(int pid, char str)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if (((str >> bit) & 1) == 1)
            kill (pid, SIGUSR1);
        else
            kill (pid, SIGUSR2);
        usleep(100);
        bit++;
    }
}

int main(int argc, char **argv)
{
    int     pid;
    int     i;
    char    *msg;

    msg = NULL;
    msg = ft_minijoin(msg, 'D');
    printf("%s", msg);
    /*if (argc != 3)
        return (ft_printf("ERROR: Wrong usage of the program. Use './client [PID] [Message]\n"));
    i = -1;
    msg = "\033[1;32mCLIENT MESSAGE: \033[0m";
    pid = ft_atoi(argv[1]);
    while (msg[++i])
        send_to_server(pid, msg[i]);
    i = -1;
    while (argv[2][++i])
        send_to_server(pid, argv[2][i]);
    send_to_server(pid, '\n');
    return (0); */
}
