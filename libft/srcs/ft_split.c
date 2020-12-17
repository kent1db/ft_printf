/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:37:13 by qurobert          #+#    #+#             */
/*   Updated: 2020/11/26 11:25:04 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_all(char **strs, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	ft_m_size(char const *str, char sep)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
		{
			c++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (c);
}

static char	*ft_malloc_write(char const *str, char sep, char **strs, int index)
{
	int		i;
	char	*tab;

	i = 0;
	while (str[i] != '\0' && str[i] != sep)
		i++;
	if (!(tab = malloc(sizeof(char) * i + 1)))
	{
		ft_free_all(strs, index);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0' && str[i] != sep)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((!(tab = (char **)malloc(sizeof(char *) * (ft_m_size(s, c)) + 1))))
		return (NULL);
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			if (!(tab[i] = ft_malloc_write(s, c, tab, i)))
				return (NULL);
		while (*s && *s != c)
			s++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
