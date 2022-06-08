/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:24:07 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/08 19:53:43 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "printf/HEADER/ft_printf.h"

char	**ft_split(char *s, char c);
char	**split_path(char *str, char *cmd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
//int		ft_strlen(char *str);
int		ft_strlen_c(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
int		**free_tabs(int **tabs);
int		ret_error(char *str);
int		exit_error(char *str);

#endif