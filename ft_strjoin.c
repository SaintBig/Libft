#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char *str;
	unsigned int l1;
	unsigned int l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)ft_calloc(l1 + l2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	return(str);
}

int main(void)
{
	char s1[] = "xxxxxxabc";
	char s2[] = "defxxxxxxx";
	char *s3 = ft_strjoin(s1, s2);

	printf("%s\n", s3);
}