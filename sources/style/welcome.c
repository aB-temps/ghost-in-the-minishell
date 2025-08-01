/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:56:26 by abetemps          #+#    #+#             */
/*   Updated: 2025/07/26 18:56:35 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style.h"

void	welcome(void)
{
	const char	*banner = "\n\
 /$$      /$$ /$$           /$$           /$$                 /$$ /$$\n\
| $$$    /$$$|__/          |__/          | $$                | $$| $$\n\
| $$$$  /$$$$ /$$ /$$$$$$$  /$$  /$$$$$$$| $$$$$$$   /$$$$$$ | $$| $$\n\
| $$ $$/$$ $$| $$| $$__  $$| $$ /$$_____/| $$__  $$ /$$__  $$| $$| $$\n\
| $$  $$$| $$| $$| $$  \\ $$| $$|  $$$$$$ | $$  \\ $$| $$$$$$$$| $$| $$\n\
| $$\\  $ | $$| $$| $$  | $$| $$ \\____  $$| $$  | $$| $$_____/| $$| $$\n\
| $$ \\/  | $$| $$| $$  | $$| $$ /$$$$$$$/| $$  | $$|  $$$$$$$| $$| $$\n\
|__/     |__/|__/|__/  |__/|__/|_______/ |__/  |__/ \\_______/|__/|__/\n\n";

	printf("%s%s%s\n", FG_BLUE, banner, R_ALL);
}
