/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:44 by msenipek          #+#    #+#             */
/*   Updated: 2022/12/14 18:23:46 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_replace(char *str, char from, char from2, char to)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] == from || str[i] == from2)
			new_str[i] = to;
		else
			new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
