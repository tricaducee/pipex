/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:24:07 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/18 13:09:39 by hrolle           ###   ########.fr       */
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
# include "../printfd/HEADER/ft_printfd.h"

typedef struct S_t_ptr
{
	int		**fd;
	char	**path;
	char	**command;
	char	**av;
	char	**envp;
	char	*heredoc;
	int		on_exit;
	int		cmd_i;
}			t_ptr;

/* ------------------------MAIN------------------------ */

int		nl_strcmp(char *s1, char *s2);
char	*check_limiter(t_ptr *tabs);
void	heredoc_str(t_ptr *tabs);
void	pipes_tab_gen(int size, t_ptr *tabs);
int		compt_path(char *s);
char	*path_and_cmd(char *path, char *cmd);
void	heredoc_fd(int ac, t_ptr *tabs);
void	no_heredoc_fd(int ac, t_ptr *tabs);
void	fd_gen(int ac, t_ptr *tabs);
void	split_path(char *str, t_ptr *tabs);
void	set_t_ptr(t_ptr *tabs);
void	exec_cmd(int *fdin, int *fdout, char *cmd, t_ptr *tabs);
void	exec_cmd1(int *fd, char *cmd, t_ptr *tabs);
void	multi_exec(int ac, t_ptr *tabs);
void	fdin_out(int fdin, int fdout, t_ptr *tabs);
void	close2(int fd1, int fd2);

/* -----------------------SECURE----------------------- */

void	**free_tabs(void **tabs);
void	free_and_null(char **str);
void	close_fds(int **fd);
void	if_close_fd(int i, t_ptr *tabs);
void	exit_error(int error_number, char *str, t_ptr *tabs);

/* -----------------------LIBFT------------------------ */

char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen_c(char *str, char c);

#endif