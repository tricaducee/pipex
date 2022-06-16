/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:24:07 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 21:59:53 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "printfd/HEADER/ft_printfd.h"

typedef struct S_t_ptr
{
	int		**fd;
	char	**path;
	char	**command;
	char	**av;
	char	**envp;
	char	*heredoc;
}			t_ptr;

void	heredoc_str(t_ptr *tabs);
char	**ft_split(char *s, char c);
void	split_path(char *str, t_ptr *tabs);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
int		ft_strlen_c(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
int		**free_int_fd(int **fd);
char	**free_strs(char **strs);
void	free_and_null(char **str);
void	close_fds(int **fd);
void	close2(int fd1, int fd2);
void	fdin_out(int fdin, int fdout, t_ptr *tabs);
void	set_t_ptr(t_ptr *tabs);
int		ret_error(char *str);
void	exit_error(int error_number, char *str, t_ptr *tabs);
void	if_close_fd(int i, int **fd);
void	heredoc_fd(int ac, t_ptr *tabs);
void	no_heredoc_fd(int ac, t_ptr *tabs);
void	fd_gen(int ac, t_ptr *tabs);
void	pipes_tab_gen(int size, t_ptr *tabs);
void	exec_cmd(int *fdin, int *fdout, char *cmd, t_ptr *tabs);
void	exec_cmd1(int *fd, char *cmd, t_ptr *tabs);
void	multi_exec(int ac, t_ptr *tabs);

#endif