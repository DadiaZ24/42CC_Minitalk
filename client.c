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

int dynamic_sleep(int n)
{
    if (n <= 100)
        return (10);
    else if (n < 10000)
        return (100);
    else if (n < 100000)
        return (200);
    else
        return (500);
}

void send_to_server(int pid, char *str)
{
    int bit;
    int i;
    int strsize;

    i = 0;
    strsize = ft_strlen(str);
    while (i <= strsize)
    {
        bit = 0;
        while (bit < 8)
        {
            if (((str[i] >> bit) & 1) == 1)
                kill (pid, SIGUSR1);
            else
                kill (pid, SIGUSR2);
            usleep(dynamic_sleep(strsize));
            bit++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int     pid;
    int     i;
    char    *msg;

    msg = NULL;
    msg = ft_minijoin(msg, 'D');
    if (argc != 3)
        return (ft_printf("ERROR: Wrong usage of the program. Use './client [PID] [Message]\n"));
    i = -1;
    msg = "\033[1;32mCLIENT MESSAGE: \033[0m";
    pid = ft_atoi(argv[1]);
    send_to_server(pid, msg);
    send_to_server(pid, argv[2]);
    send_to_server(pid, "\n");
    return (0);
}
