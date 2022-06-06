#include "../pipex.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ret)
		return (0);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}