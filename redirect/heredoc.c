/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:20:11 by msenipek          #+#    #+#             */
/*   Updated: 2022/12/19 10:20:46 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_heredoc(int sig)
{
	(void)sig;
	g_ms.ignore = TRUE;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

void	heredoc(int *fd, char *endline)
{
	char		*input;

	if (pipe(fd) < 0)
		return (perror("minishell"));
	while (1)
	{
		signal(SIGINT, &close_heredoc);
		input = readline("heredoc>> ");
		if (!input || ft_strcmp(input, endline) || g_ms.ignore)
		{
			free(input);
			break ;
		}
		write(fd[1], input, ft_strlen(input));
		write(fd[1], "\n", 1);
		free(input);
	}
	close(fd[1]);
}
