/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoffma <rohoffma@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:24:24 by rohoffma          #+#    #+#             */
/*   Updated: 2024/06/23 12:40:33 by rohoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t sz)
{
	size_t	size;

	size = 0;
	while ((size < sz - 1) && *(src + size) && sz > 0)
	{
		*(dst + size) = *(src + size);
		size++;
	}
	if (size > 0 || *src == '\0' || sz == 1)
		*(dst + size) = '\0';
	while (*(src + size))
		size++;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	unsigned int	len_s;
	unsigned int	effective_len;

	len_s = ft_strlen(s);
	effective_len = len_s - start;
	if (effective_len > len)
		effective_len = len;
	if (start >= len_s)
		effective_len = 0;
	sub_s = malloc((effective_len + 1) * sizeof(*s));
	if (sub_s == NULL)
		return (NULL);
	if (effective_len == 0)
	{
		*sub_s = '\0';
		return (sub_s);
	}
	ft_strlcpy(sub_s, &s[start], effective_len + 1);
	return (sub_s);
}

size_t	ft_strlcat(char *dst, const char *src, size_t sz)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	i = 0;
	if (sz <= dst_len)
		return (sz + src_len);
	while (i < sz - dst_len - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char		c_char;
	char				*ptr;

	c_char = (unsigned char)c;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c_char)
			return (ptr);
		ptr++;
	}
	if (c_char == '\0' && !*ptr)
		return (ptr);
	return (NULL);
}
