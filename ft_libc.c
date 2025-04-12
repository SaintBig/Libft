#include <stdlib.h>

int	ft_isalpha (char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (c);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

int	ft_isalnum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return (c);
	return (0);
}

int	ft_isascii(char c)
{
	if (c >= 0 && c <= 127)
		return (c);
	return (0);
}

int	ft_isprint(char c)
{
	if (c >= 32 && c <= 126)
		return (c);
	return (0);
}

static int	ft_isspace(char c)
{
	if ((c >=9 && c <= 13) || c == 32)
		return (c);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *) b;
	while (len > 0)
	{
		*(tmp_ptr++) = (unsigned char) c;
		len--;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *) s;
	while (n > 0)
	{
		*(tmp_ptr++) = 0;
		n--;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (src == (void *)0 && dst == (void *)0)
		return (dst);
	tmp_src = (unsigned char *) src;
	tmp_dst = (unsigned char *) dst;
	while (n > 0)
	{
		*(tmp_dst++) = *(tmp_src++);
		n--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	tmp_src = (unsigned char *) src;
	tmp_dst = (unsigned char *) dst;
	i = 0;
	if (tmp_dst > tmp_src)
		while (len-- > 0)
			tmp_dst[len] = tmp_src[len];
	else
		while (i++ < len)
			tmp_dst[i] = tmp_src[i];
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < dstsize)
		ft_memcpy(dst, src, src_len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		dst_len = dstsize;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	if (src_len < dstsize - dst_len)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
		dst[dstsize - 1] = 0;
	}
	return (dst_len + src_len);
}

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	char			a;
	unsigned int	i;

	a = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return((char *) &s[i]);
		i++;
	}
	if (s[i] == a)
		return((char *) &s[i]);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char			a;
	char			*ptr;
	unsigned int	i;

	a = (char) c;
	ptr = NULL;
	i = 0;
	while(s[i])
	{
		if (s[i] == a)
			ptr = (char *) &s[i];
		i++;
	}
	if (s[i] == a)
		ptr = (char *) &s[i];
	return (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	a;

	ptr = (unsigned char *) s;
	a = (unsigned char) c;
	while (n-- > 0)
	{
		if (*ptr == a)
		{
			return ((void *)ptr);
		}
		ptr++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	needlelen;
	
	if (!needle)
		return ((char *)haystack);
	needlelen = ft_strlen(needle);
	while (*haystack && len-- > 0)
	{
		if (*haystack == *needle)
			if (!ft_strncmp(haystack, needle, needlelen))
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

int	ft_atoi(const char *str)
{
	int	tot;
	int	p;
	int	i;

	tot = 0;
	p = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		p = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		tot = (tot * 10) + str[i] - '0';
		i++;
	}
	return (tot * p);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t i; 

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
		ptr[i++] = 0;
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}