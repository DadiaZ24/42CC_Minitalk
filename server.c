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

void    welcome_message(void)
{
    ft_printf("\033[1;32m_______________________________________________________________________\n\n");
    ft_printf("\033[1;31m __   __  ___   __    _  ___   _______  _______  ___      ___   _ \n");
    ft_printf("\033[1;31m|  |_|  ||   | |  |  | ||   | |       ||   _   ||   |    |   | | |\n");
    ft_printf("\033[1;31m|       ||   | |   |_| ||   | |_     _||  |_|  ||   |    |   |_| |\n");
    ft_printf("\033[1;31m|       ||   | |       ||   |   |   |  |       ||   |    |      _|\n");
    ft_printf("\033[1;31m|       ||   | |  _    ||   |   |   |  |       ||   |___ |     |_ \n");
    ft_printf("\033[1;32m| ||_|| ||   | | | |   ||   |   |   |  |   _   ||       ||    _  |\n");
    ft_printf("\033[1;32m|_|   |_||___| |_|  |__||___|   |___|  |__| |__||_______||___| |_|\n\n\033[0m");
    ft_printf("\033[1;31mAuthor: \033[32mddias-fe                                  \033[1;31mServer PID: \033[32m%d\n", getpid());
    ft_printf("_______________________________________________________________________\n\n");
    ft_printf("                                 SERVER\n\n\033[0m");
}

void    receive_message(int bitsignal)
{
    static int     bit;
    static unsigned char    c;
    static char   *msg;

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

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 1)
        return (ft_printf("\033[0;31mERROR: You should only use './server' and nothing more!\n"));
    welcome_message();
    ft_printf("Waiting for client interaction...\n\033[1;32m");
    while (1)
    {
        signal(SIGUSR1, receive_message);
        signal(SIGUSR2, receive_message);
    }
    return (0);
}
