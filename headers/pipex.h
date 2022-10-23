/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:41:43 by fsanches          #+#    #+#             */
/*   Updated: 2022/07/25 23:45:00 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

enum e_errors
{
	NO_ERROR,
	ARG_ERROR,
	PERMISSION_ERROR,
	INF_PERMISSION,
	FILE_ERROR,
	CMD_NOT_FOUND,
	CMD_NULL
};

typedef struct s_cmd
{
	char	**cmd_1;
	char	**cmd_2;
	char	*path_1;
	char	*path_2;
	pid_t	pid_1;
	pid_t	pid_2;
}	t_cmd;

typedef struct s_pipe
{
	int		fd[2];
	int		child_status;
	t_cmd	cmds;
	char	*infile;
	char	*outfile;
	int		fd_outfile;
	int		fd_infile;
	char	*temp;
	char	**envp;
	char	**cmd_paths;
	int		has_error;
}	t_pipe;

void	create_pipe(t_pipe pipe, char **argv, char **env);
void	get_commands(t_pipe *p_data, char **argv, int cmd);
void	ft_pipex(t_pipe *p_data, char **argv, char **envp);
void	free_matrix(char **matrix);
void	get_cmd_paths(t_pipe *p_data, char **envp);
int		check_access(t_pipe *p_data, char *path, int cmd);
void	handle_errors(int error, char *str);
void	handle_cmd_error(t_pipe *p_data, int cmd);
void	handle_cmd_null(t_pipe *p_data, int cmd, int is_init);

#endif