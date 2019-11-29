#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	next_word(char *s, char c, int i)
{
	while (s[i])
	{
		if (s[i] == c)
			return i;
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		nb_word;
	int		i;
	int		j;

	if (!s || !(s = (char const *)ft_strtrim_char((char *)s, c)))
		return NULL;
	nb_word = ft_str_countword((char *)s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * nb_word + 1)))
		return (NULL);
	ret[nb_word] = NULL;
	i = 0;
	while (i <= nb_word)
	{
		j = next_word((char *)s, c, i);
		if (!(ret[i] = ft_strsub(s, i, j-i)))
			ret[i] = ft_strdup("");
		i++;
	}
	return (ret);
}
