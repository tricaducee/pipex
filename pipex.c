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
		printf("%s\n", *strs);
		strs++;
	}
}

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
		printf("Error generating ");
		return (0);
	}
	while (envp[i])
	{
		if (ft_strcmp("PATH=", envp[i]))
			break ;
		i++;
	}
	path = split_path(envp[i] + 5, *command);
	//print_tab(path);
	return (0);
}