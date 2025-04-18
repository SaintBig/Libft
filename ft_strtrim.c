#include "libft.h"
#include <stdio.h>

static int	set_cmp(const char c,const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (*set);
		set++;
	}
	return (0);
}

static char	*make_trim(const char *s, size_t start, size_t len)
{
	char	*new;

	if (len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	new = (char *)ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, &s[start], len);
	return (new);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (set_cmp(s1[i], set))
		i++;
	while (set_cmp(s1[j], set))
		j--;
	return (make_trim(s1, i, j - (i - 1)));
}
