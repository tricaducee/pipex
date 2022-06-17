/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:23:41 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 22:00:43 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_t_ptr(t_ptr *tabs)
{
	tabs->fd = NULL;
	tabs->path = NULL;
	tabs->command = NULL;
	tabs->heredoc = NULL;
}

void	exec_cmd(int *fdin, int *fdout, char *cmd, t_ptr *tabs)
{
	int		i;

	close2(fdin[1], fdout[0]);
	fdin_out(fdin[0], fdout[1], tabs);
	close2(fdin[0], fdout[1]);
	i = 0;
	tabs->command = ft_split(cmd, ' ');
	if (!tabs->command)
		exit_error(errno, "Malloc", tabs);
	while (tabs->envp[i] && !ft_strcmp("PATH=", tabs->envp[i]))
		i++;
	if (!ft_strchr(tabs->command[0], '/'))
		split_path(tabs->envp[i] + 5, tabs);
	else
		tabs->path = tabs->command;
	i = 0;
	while (tabs->path[i] && access(tabs->path[i], X_OK) == -1)
		i++;
	if (tabs->path[i])
	{
		if (execve(tabs->path[i], tabs->command, tabs->envp) == -1)
			exit_error(errno, tabs->command[0], tabs);
	}
	else
		exit_error(errno, "command not found", tabs);
}

void	exec_cmd1(int *fd, char *cmd, t_ptr *tabs)
{
	int		i;

	fdin_out(fd[0], fd[1], tabs);
	close2(fd[0], fd[1]);
	i = 0;
	tabs->command = ft_split(cmd, ' ');
	if (!tabs->command)
		exit_error(errno, "Malloc", tabs);
	while (tabs->envp[i] && !ft_strcmp("PATH=", tabs->envp[i]))
		i++;
	if (!ft_strchr(tabs->command[0], '/'))
		split_path(tabs->envp[i] + 5, tabs);
	else
		tabs->path = tabs->command;
	i = 0;
	while (tabs->path[i] && access(tabs->path[i], X_OK) == -1)
		i++;
	if (tabs->path[i])
	{
		if (execve(tabs->path[i], tabs->command, tabs->envp) == -1)
			exit_error(errno, tabs->command[0], tabs);
	}
	else
		exit_error(errno, "command not found", tabs);
}

void	multi_exec(int ac, t_ptr *tabs)
{
	int	pid;
	int	cmd_i;
	int	i;

	i = 0;
	if (ft_strcmp(tabs->av[1], "here_doc"))
		cmd_i = 3;
	else
		cmd_i = 2;
	while (i < ac - (cmd_i + 2))
	{
		pid = fork();
		if (pid == -1)
			exit_error(errno, "Fork didn't work", tabs);
		if (!pid)
			exec_cmd(tabs->fd[i], tabs->fd[i + 1], tabs->av[cmd_i + i], tabs);
		else
		{
			if_close_fd(i, tabs->fd);
			wait(&pid);
			if (++i == ac - (cmd_i + 2))
				exec_cmd(tabs->fd[i], tabs->fd[0], tabs->av[cmd_i + i], tabs);
		}
	}
}

int	main(int ac, char **av, char *envp[])
{
	t_ptr	tabs;
	int		herefunc;

	set_t_ptr(&tabs);
	herefunc = ft_strcmp("here_doc", av[1]);
	tabs.av = av;
	tabs.envp = envp;
	if (ac < 4 || (ac < 5 && herefunc))
		exit_error(errno, "More arguments are required", &tabs);
	fd_gen(ac, &tabs);
	if (ac == 4 || (ac == 5 && herefunc))
		exec_cmd1(tabs.fd[0], av[ac - 2], &tabs);
	else
		multi_exec(ac, &tabs);
	return (0);
}

/*
void	print_tab(char **strs)
{
	while (*strs)
	{
		ft_printf("%s\n", *strs);
		strs++;
	}
}
*/