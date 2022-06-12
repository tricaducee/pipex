/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:24:07 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/13 01:33:58 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "printf/HEADER/ft_printf.h"

char	*heredoc_str(char *limiter);
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
void	if_close_fd(int i, int **fd);
int		**heredoc_fd(int ac, char **av);
int		**no_heredoc_fd(int ac, char **av);
int		**fd_gen(int ac, char **av);
int		**pipes_tab_gen(int size);
void	exec_cmd(int *fdin, int *fdout, char *cmd, char **envp);
int		multi_exec(int ac, char **av, char **envp, int **fd);

#endif