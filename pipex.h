#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char	**ft_split(char *s, char c);
char	**split_path(char *str, char *cmd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
int		ft_strlen_c(char *str, char c);
int		ft_strcmp(char *s1, char *s2);

#endif