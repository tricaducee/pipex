/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:29:10 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/18 09:15:27 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/pipex.h"

int	nl_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if ((!s1[i] || s1[i] == '\n') && !s2[i])
		return (1);
	return (0);
}

char	*check_limiter(t_ptr *tabs)
{
	char	*line;
	char	*tmp;
	char	buf[2];

	buf[1] = 0;
	line = malloc(1 * sizeof(char));
	if (!line)
		exit_error(errno, "Malloc failure", tabs);
	*line = '\0';
	while (1)
	{
		read(0, buf, 1);
		tmp = line;
		line = ft_strjoin(tmp, buf);
		free(tmp);
		if (!line)
			exit_error(errno, "Malloc failure", tabs);
		if (*buf == '\n')
			break ;
	}
	if (nl_strcmp(line, tabs->av[2]))
		free_and_null(&line);
	return (line);
}

void	heredoc_str(t_ptr *tabs)
{
	char	*line;
	char	*tmp;

	tabs->heredoc = malloc(1 * sizeof(char));
	if (!tabs->heredoc)
		exit_error(errno, "Malloc failure", tabs);
	tabs->heredoc[0] = '\0';
	write(1, "heredoc> ", 10);
	while (1)
	{
		line = check_limiter(tabs);
		if (!line)
			break ;
		tmp = tabs->heredoc;
		tabs->heredoc = ft_strjoin(tmp, line);
		if (!tabs->heredoc)
			exit_error(errno, "Malloc failure", tabs);
		free(tmp);
		free(line);
		write(1, "heredoc> ", 10);
	}
}
