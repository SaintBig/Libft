#include "libft.h"
#include <stdio.h>

static int count_words(char *s, char c)
{
	unsigned int	wrds;
	unsigned int	i;

	wrds = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			wrds++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (wrds);
}

/* char **ft_split(const char *s, char c)
{

} */

int main(void)
{
	char c = ' ';
	char str[] = "  Hello   wor ld goodbye";
	int wrds = count_words(str, c);

	printf("%d\n", wrds);
}