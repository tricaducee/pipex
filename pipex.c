/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:23:41 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/10 07:36:52 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**fds_tab_gen(int size)
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
/*
int	main(int ac, char **av, char *envp[])
{
	int		i;
	int		**pipes_fds;
	char	**command;
	char	**path;

	i = 0;
	command = ft_split(av[1], ' ');
	pipes_fds = fds_tab_gen(ac - 3);
	if (!pipes_fds)
	{
		ft_printf("#rERROR#0 : [#/rgenerating pipes#0]");
		//return (0);
	}
	while (envp[i])
	{
		if (ft_strcmp("PATH=", envp[i]))
			break ;
		i++;
	}
	path = split_path(envp[i] + 5, *command);
	i = 0;
	while (path[i] && execve(path[i], command, envp))
		i++;
	if (!path[i])
	{
		ft_printf("#rERROR#0 : [#/rLa commande n'existe pas#0]");
		return (0);
	}
	
	print_tab(path);
	return (0);
}
*/

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
	int	fd[2];
	int	file[2];
	int	pid;

	if (ac < 5)
		return (ret_error("More arguments are required"));
	file[0] = open(av[1], O_RDONLY);
	if (file[0] == -1)
		return (ret_error("File 1 not open"));
	file[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file[1] == -1)
		return (ret_error("File 2 not open"));
	if (pipe(fd) == -1)
		return (ret_error("Pipe didn't work"));
	pid = fork();
	if (pid == -1)
		return (ret_error("Fork didn't work"));
	if (!pid)
		exec_cmd(file, fd, av[2], envp);
	else
		exec_cmd(fd, file, av[ac - 2], envp);
//	close(file[0]);
//	close(file[1]);
	return (0);
}
