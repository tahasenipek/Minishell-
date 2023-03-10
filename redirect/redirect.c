/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:19:59 by msenipek          #+#    #+#             */
/*   Updated: 2022/12/16 19:25:37 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_all_inputs(t_process *process)
{
	int		i;
	char	**redirects;

	i = 0;
	redirects = process->redirects;
	while (redirects[i])
	{
		if (is_operator(redirects[i]) == RED_INPUT)
			input(redirects[i + 1]);
		else if (is_operator(redirects[i]) == HERE_DOC)
			dup2(process->heredoc_fd[0], 0);
		i += 2;
	}
}

void	set_all_outputs(t_process *process)
{
	int		i;
	char	**redirects;

	i = 0;
	redirects = process->redirects;
	while (redirects[i])
	{
		if (is_operator(redirects[i]) == RED_OUTPUT)
			output(redirects[i + 1], REPLACE);
		else if (is_operator(redirects[i]) == RED_APPEND)
			output(redirects[i + 1], APPEND);
		i += 2;
	}
}

void	fill_all_heredoc(void)
{
	int			i;
	char		**redirects;
	t_process	*process;

	process = g_ms.process;
	while (process)
	{
		i = 0;
		redirects = process->redirects;
		while (redirects[i] && !(g_ms.ignore))
		{
			if (is_operator(redirects[i]) == HERE_DOC)
				heredoc(process->heredoc_fd, redirects[i + 1]);
			i += 2;
		}
		process = process->next;
	}
}
