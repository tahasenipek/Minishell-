/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:21:29 by msenipek          #+#    #+#             */
/*   Updated: 2022/12/14 18:21:31 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	contain_heredoc(t_process *process)
{
	int	i;

	i = 0;
	while (process->redirects[i])
	{
		if (is_operator(process->redirects[i]) == HERE_DOC)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
