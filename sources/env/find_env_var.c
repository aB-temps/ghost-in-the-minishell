/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:15:29 by abetemps          #+#    #+#             */
/*   Updated: 2025/08/02 16:22:14 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "debug.h"

t_list	*find_env_var(char *key, t_list *env)
{
	while (env)
	{
		if (!ft_strcmp(key, ((t_env_var *)env->content)->key))
			return (env);
		env = env->next;
	}
	return ((void *)0);
}
