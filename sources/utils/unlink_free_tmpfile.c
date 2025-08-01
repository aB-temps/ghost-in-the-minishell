/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_free_tmpfile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:24:32 by abetemps          #+#    #+#             */
/*   Updated: 2025/08/02 16:21:52 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

void	unlink_free_tmpfile(char *tmpfile)
{
	if (tmpfile)
	{
		unlink(tmpfile);
		free(tmpfile);
	}
}
