/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:23:41 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/11 20:17:37 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**pipes_tab_gen(int size)
{
	int	**ret;
	int	i;

	i = 0;
	ret = malloc((size + 1) * sizeof(int *));
	if (!ret)
		return (NULL);
	while (i < size)
	{
		ret[i] = malloc(2 * sizeof(int));
		if (!ret[i])
			return (free_tabs(ret));
		i++;
	}
	ret[i] = NULL;
	i = 1;
	while (ret[i])
	{
		if (pipe(ret[i]) == -1)
			return (free_tabs(ret));
		i++;
	}
	return (ret);
}

void	print_tab(char **strs)
{
	while (*strs)
	{
		ft_printf("%s\n", *strs);
		strs++;
	}
}

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

int	main(int ac, char **av, char *envp[])
{
	char	*heredoc;
	int		**fd;
	int		pid;
	int		i;
	int		cmd_i;

	i = 0;
	if (ac < 5)
		return (ret_error("More arguments are required"));
	if (ft_strcmp("here_doc", av[1]))
	{
		cmd_i = 3;
		heredoc = heredoc_str(av[2]);
		//ft_printf("heredoc = %s\n", heredoc);
		fd = pipes_tab_gen(ac - 3);
		if (!fd)
			return (ret_error("Pipe gen didn't work"));
		pipe(fd[0]);
		write(fd[0][1], heredoc, ft_strlen(heredoc));
		close(fd[0][1]);
		free(heredoc);
	}
	else
	{
		cmd_i = 2;
		fd = pipes_tab_gen(ac - 2);
		if (!fd)
			return (ret_error("Pipe gen didn't work"));
		fd[0][0] = open(av[1], O_RDONLY);
		if (fd[0][0] == -1)
			return (ret_error("File 1 not open"));
	}
	fd[0][1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[0][1] == -1)
		return (ret_error("File 2 not open"));
	i = 0;
	while (i < ac - (cmd_i + 2))
	{
		pid = fork();
		if (pid == -1)
			return (ret_error("Fork didn't work"));
		if (!pid)
		{
			exec_cmd(fd[i], fd[i + 1], av[cmd_i + i], envp);
		}
		else
		{
			if (i)
			{
				close(fd[i][0]);
				close(fd[i][1]);
			}
			else
				close(fd[i][0]);
			wait(&pid);
			if (++i == ac - (cmd_i + 2))
				exec_cmd(fd[i], fd[0], av[cmd_i + i], envp);
		}
	}
//	close(fd[0][0]);
//	close(fd[0][1]);
	return (0);
}
