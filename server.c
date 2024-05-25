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
    static char    *message;
    static int		i;

	if (!i)
		i = 0;
	if (!message)
		message = NULL;
    if (bitsignal == SIGUSR1)
        c |= (1 << bit);
    bit += 1;
    if (bit == 8)
    {
		if (c == '\n')
		{
			ft_printf("%s", message);
			i = 0;
		}
		else
			message = ft_minijoin(message, c);
        bit = 0;
        c = 0;
    }
}

/* void receive_message(int bitsignal)
{
    static int bit = 0;
    static unsigned char c = 0;
    static char message[1024]; // Adjust size as needed
    static int message_index = 0;

    if (bitsignal == SIGUSR1)
        c |= (1 << bit);
    
    bit += 1;

    if (bit == 8)
    {
        if (c == '\n') // Null character to indicate end of message
        {
            message[message_index] = '\0';
            ft_printf("Received message: %s\n", message);
            message_index = 0; // Reset for next message
        }
        else
        {
            message[message_index++] = c;
        }
        bit = 0;
        c = 0;
    }
} */

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
