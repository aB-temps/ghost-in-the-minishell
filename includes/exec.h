/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:03:10 by enchevri          #+#    #+#             */
/*   Updated: 2025/08/02 17:50:43 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

/*-------------------------------- INCLUDES --------------------------------*/
# include "input.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/*--------------------------------- ENUM ---------------------------------*/

/*-------------------------------- STRUCTS --------------------------------*/
typedef struct s_fd
{
	int		fd1[2];
	int		fd2[2];
}			t_fd;

typedef struct s_exec
{
	int		fd_infile;
	int		fd_outfile;
	pid_t	*pid_child;
	int		cmd_count;
	char	*cmd_path;
	char	**args;
	t_fd	*fd;
}			t_exec;

/*------------------------------- FUNCTIONS -------------------------------*/
char		*get_path(char **env);
char		*find_full_command_path(char **cmd, char **env, int *error);
int			execute_command(t_token *current_token, t_exec *exec, int i,
				t_input *input);
int			launch_all_commands(t_input *input, t_exec *exec,
				t_token *token_array);
// int			create_files_no_cmd(int cur_index, t_token *token_array);
void		start_exec(t_input *input);
int			count_cmd(t_input *input);
void		wait_childs(t_exec *exec, t_input *input);
int			close_all(t_exec *exec);
void		prepare_pipe(t_exec *exec, int i);
char		*get_cmd_by_index(t_input *input, t_token *tokens_array, int index);
int			is_builtin(t_token current_token, t_input *input, t_exec *exec,
				int i);
int			create_all_files(t_exec *exec, t_input *input, int i);
int			check_builtin(char *cmd);
void		apply_redirections_builtin(t_input *input, int *old_stdout,
				int *old_stdin);
void		check_cmd(t_input *input, t_token *tokens_array, int i);
void		error_occured(t_exec *exec, char *error_msg);
int			execute_all_commands(t_input *input, t_exec *exec);
void		handle_sigint(t_input *input);
void		check_sig(t_exec *exec, t_token *tokens_array, t_input *input,
				int i);
int			check_if_dir(t_input *input, char *path);
void		close_hd_fd(t_input *input);
int			handle_redir_in(t_exec *exec, t_token current_token);
int			handle_redir_out(t_exec *exec, t_token current_token);

#endif
