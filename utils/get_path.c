/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:54:24 by msenipek          #+#    #+#             */
/*   Updated: 2022/12/19 10:48:00 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_dir(char *cmd)
{
	DIR	*dir;

	if (!cmd)
		exit(EXIT_SUCCESS);
	dir = opendir(cmd);
	if (dir && readdir(dir))
	{
		closedir(dir);
		directory_err(cmd);
	}
}

char	*mimi_ret_free(char *mim, char *path)
{
	free(mim);
	return (path);
}

char	*get_path(char *cmd)
{
	char	*path;
	char	**paths;
	char	*new_cmd;

	check_dir(cmd);
	if (!access(cmd, F_OK))
		return (ft_strdup(cmd));
	paths = g_ms.paths;
	if (!paths)
		command_err(cmd);
	new_cmd = ft_strjoin("/", cmd);
	while (*paths)
	{
		path = ft_strjoin(*paths, new_cmd);
		if (!access(path, F_OK))
			return (mimi_ret_free(new_cmd, path));
		free(path);
		paths++;
	}
	if (ft_strchr(cmd, '/'))
		no_file_err(cmd);
	free(new_cmd);
	return (NULL);
}
