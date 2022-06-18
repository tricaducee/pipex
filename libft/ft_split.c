/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:24:31 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/18 04:25:28 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/pipex.h"

int	compt_w(char *s, char c)
{
	int	j;

	j = 0;
	while (*s)
	{
		if (*s != c && (!*(s + 1) || *(s + 1) == c))
			j++;
		s++;
	}
	return (j);
}

char	**ft_split(char *s, char c)
{
	char	**strs;
	int		j;
	int		k;

	k = 0;
	if (!s)
		return (0);
	strs = malloc((compt_w(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		j = 0;
		while (s[j] != c && s[j])
			j++;
		strs[k++] = ft_substr(s, 0, j);
		s += j;
	}
	strs[k] = NULL;
	return (strs);
}
