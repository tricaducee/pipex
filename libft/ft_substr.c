#include "../pipex.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	unsigned int	f_len;

	if (!s)
		return (0);
	f_len = ft_strlen(s);
	if (start >= f_len)
		return (ft_strdup(""));
	if (len > f_len - start)
		len = f_len - start;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}