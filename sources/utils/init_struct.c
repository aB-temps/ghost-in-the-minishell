/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:48:31 by abetemps          #+#    #+#             */
/*   Updated: 2025/08/02 17:46:28 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "input.h"
#include "parsing.h"
#include "utils.h"
#include <linux/limits.h>

static void	init_empty_env(t_input *input)
{
	char	*cwd;

	cwd = (void *)0;
	cwd = getcwd(cwd, PATH_MAX);
	if (!cwd)
		exit_parsing(input, EXIT_FAILURE);
	input->env->array = ft_calloc(3, sizeof(char *));
	if (!input->env->array)
		exit_parsing(input, EXIT_FAILURE);
	input->env->array[0] = ft_strjoin("PWD=", cwd);
	if (!input->env->array[0])
		exit_parsing(input, EXIT_FAILURE);
	input->env->array[1] = ft_strdup("SHLVL=1");
	if (!input->env->array[1])
		exit_parsing(input, EXIT_FAILURE);
	input->env->array[2] = (void *)0;
	update_env_list(input, NULL);
}

void	init_env(char **env, t_input *input)
{
	input->env = ft_calloc(1, sizeof(t_env));
	if (!input->env)
		exit_parsing(input, EXIT_FAILURE);
	if (!env[0])
		init_empty_env(input);
	else
	{
		input->env->list = env_array_to_list(env);
		if (!input->env->list)
			exit_parsing(input, EXIT_FAILURE);
		input->env->array = ft_tabdup(env);
		if (!input->env->array)
			exit_parsing(input, EXIT_FAILURE);
	}
}

void	init_token(t_token *token)
{
	token->type = -1;
	token->link_to_next = false;
	token->raw_content = (void *)0;
	token->formatted_content = (void *)0;
}
