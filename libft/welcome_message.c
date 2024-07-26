/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:14:38 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/06/13 17:14:56 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	welcome_message(void)
{
	ft_printf("\033[1;32m____________________________");
	ft_printf("___________________________________________\n\n");
	ft_printf("\033[1;31m __   __  ___   __    _  ___   _______");
	ft_printf("  _______  ___      ___   _ \n");
	ft_printf("\033[1;31m|  |_|  ||   | |  |  | ||   | |       ");
	ft_printf("||   _   ||   |    |   | | |\n");
	ft_printf("\033[1;31m|       ||   | |   |_| ");
	ft_printf("||   | |_     _||  |_|  ||   |    |   |_| |\n");
	ft_printf("\033[1;31m|       ||   | |       ||   |   |   ");
	ft_printf("|  |       ||   |    |      _|\n");
	ft_printf("\033[1;31m|       ||   | |  _    ||   |   |  ");
	ft_printf(" |  |       ||   |___ |     |_ \n");
	ft_printf("\033[1;32m| ||_|| ||   | | | |   ||   |   |   ");
	ft_printf("|  |   _   ||       ||    _  |\n");
	ft_printf("\033[1;32m|_|   |_||___| |_|  |__||___|   |___");
	ft_printf("|  |__| |__||_______||___| |_|\n\n\033[0m");
	ft_printf("\033[1;31mAuthor: \033[32mddias-fe                   ");
	ft_printf("               \033[1;31mServer PID: \033[32m%d\n", getpid());
	ft_printf("________________________________________________");
	ft_printf("_______________________\n\n");
	ft_printf("                                 SERVER\n\n\033[0m");
}
