/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:28:41 by msenipek          #+#    #+#             */
/*   Updated: 2022/12/16 19:28:43 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_cd(char **input)
{
	char	*home;

	if (input[1] != NULL)
	{
		if (chdir(input[1]) != 0)
			perror("minishell ");
	}
	else
	{
		home = getenv("HOME");
		if (home && *home)
			if (chdir(home))
				perror("minishell ");
	}
	if (!is_parent())
		exit (errno);
}
