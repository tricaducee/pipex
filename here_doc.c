/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:29:10 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/13 01:36:04 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ret = str;
	while (*s1)
		*(str++) = *(s1++);
	while (*s2)
		*(str++) = *(s2++);
	*str = 0;
	return (ret);
}

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

char	*check_limiter(char *limiter)
{
	char	*line;
	char	*tmp;
	char	buf[2];

	buf[1] = 0;
	line = malloc(1 * sizeof(char));
	*line = '\0';
	while (1)
	{
		read(0, buf, 1);
		tmp = line;
		line = ft_strjoin(tmp, buf);
		free(tmp);
		if (*buf == '\n')
			break ;
	}
	if (nl_strcmp(line, limiter))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*heredoc_str(char *limiter)
{
	char	*ret;
	char	*line;
	char	*tmp;

	ret = malloc(1 * sizeof(char));
	ret[0] = '\0';
	write(1, "heredoc> ", 10);
	while (1)
	{
		line = check_limiter(limiter);
		if (!line)
			break ;
		tmp = ret;
		ret = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		write(1, "heredoc> ", 10);
	}
	return (ret);
}