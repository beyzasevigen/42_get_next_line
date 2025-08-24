/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsevigen <bsevigen@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:53:29 by bsevigen          #+#    #+#             */
/*   Updated: 2025/08/23 20:25:57 by bsevigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	int		i;
	int		j;
	char	*temp_str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	temp_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (temp_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		temp_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		temp_str[i + j] = s2[j];
		j++;
	}
	temp_str[i + j] = '\0';
	return (temp_str);
}