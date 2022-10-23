/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:43:34 by fsanches          #+#    #+#             */
/*   Updated: 2022/07/25 23:43:40 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	check_access(t_pipe *p_data, char *path, int cmd)
{
	if (access(path, X_OK) == 0)
	{
		if (cmd == 1)
			p_data->cmds.path_1 = ft_strdup(path);
		else
		{
			p_data->cmds.path_2 = ft_strdup(path);
			free_matrix(p_data->cmd_paths);
		}
		free(path);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
