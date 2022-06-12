/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:23:41 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/13 01:36:22 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(int *fdin, int *fdout, char *cmd, char **envp)
{
	int		i;
	char	**command;
	char	**path;

	close(fdin[1]);
	close(fdout[0]);
	dup2(fdin[0], STDIN_FILENO);
	dup2(fdout[1], STDOUT_FILENO);
	close(fdin[0]);
	close(fdout[1]);
	i = 0;
	command = ft_split(cmd, ' ');
	while (envp[i] && !ft_strcmp("PATH=", envp[i]))
		i++;
	path = split_path(envp[i] + 5, *command);
	i = 0;
	while (path[i] && execve(path[i], command, envp))
		i++;
}

int	multi_exec(int ac, char **av, char **envp, int **fd)
{
	int	pid;
	int	cmd_i;
	int	i;

	i = 0;
	if (ft_strcmp(av[1], "here_doc"))
		cmd_i = 3;
	else
		cmd_i = 2;
	while (i < ac - (cmd_i + 2))
	{
		pid = fork();
		if (pid == -1)
			return (ret_error("Fork didn't work"));
		if (!pid)
			exec_cmd(fd[i], fd[i + 1], av[cmd_i + i], envp);
		else
		{
			if_close_fd(i, fd);
			wait(&pid);
			if (++i == ac - (cmd_i + 2))
				exec_cmd(fd[i], fd[0], av[cmd_i + i], envp);
		}
	}
	return (1);
}

int	main(int ac, char **av, char *envp[])
{
	int		**fd;

	if (ac < 4)
		return (ret_error("More arguments are required"));
	fd = fd_gen(ac, av);
	if (!fd)
		return (ret_error("fd_gen fail"));
	if (ac == 4)
		exec_cmd(fd[0], fd[0], av[ac - 2], envp);
	else
		multi_exec(ac, av, envp, fd);
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