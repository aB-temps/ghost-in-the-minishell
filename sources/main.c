/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 06:53:15 by enchevri          #+#    #+#             */
/*   Updated: 2025/08/02 17:20:11 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "signals.h"
#include "style.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	rl_event_hook = set_loop;
	welcome();
	if (isatty(STDIN_FILENO) != 1)
	{
		ft_putstr_fd("minishell: interactive mode only\n", STDERR_FILENO);
		exit(2);
	}
	get_input(env);
	return (0);
}
