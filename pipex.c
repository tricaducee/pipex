#include "pipex.h"

int	**free_tabs(int **tabs)
{
	int	i;

	i = 0;
	while (tabs[i])
	{
		free(tabs[i]);
		tabs[i++] = NULL;
	}
	free(tabs);
	return (NULL);
}

int	**fds_tab_gen(int size)
{
	int	**ret;
	int	i;

	i = 0;
	ret = malloc((size + 1) *sizeof(int *));
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
	while(*strs)
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

void	exec_cmd(char *cmd, char **envp)
{
	int		i;
	char	**command;
	char	**path;

	i = 0;
	command = ft_split(cmd, ' ');
	while (envp[i] && !ft_strcmp("PATH=", envp[i]))
		i++;
	path = split_path(envp[i] + 5, *command);
	i = 0;
	while (path[i] && access(path[i], X_OK))
		i++;
	execve(path[i], command, envp);	
}

int	main(int ac, char **av, char *envp[])
{
	int	fd[2];
	int	pid;

	if (ac < 3)
	{
		ft_printf("#rERROR#0 : [#/rPas assez d'argments#0]");
		return(1);
	}
	pipe(fd);
	pid = fork();
	if (pid ==  -1)
	{
		ft_printf("#rERROR#0 : [#/rFork n'as pas fonctionne#0]");
		return(1);
	}
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exec_cmd(av[1], envp);
	}
	else
	{
		wait(&pid);
		pid = fork();
		if (!pid)
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			exec_cmd(av[2], envp);
		}
	}
}
