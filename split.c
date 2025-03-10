/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrisseli <rrisseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:11:45 by utente            #+#    #+#             */
/*   Updated: 2024/04/03 13:51:47 by rrisseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	j = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[j] == separator)
		++j;
	while ((str[j + len] != separator) && str[j + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[j] != separator) && str[j])
		next_str[i++] = str[j++];
	next_str[i] = '\0';
	return (next_str);
}

static void	exit_split(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

char	**ft_split_pushswap(char *str, char separator)
{
	int		nb_word;
	char	**strings_array;
	int		i;

	i = 0;
	nb_word = count_words(str, separator);
	if (!nb_word || nb_word == 1)
		exit_split();
	strings_array = malloc(sizeof(char *) * (size_t)(nb_word + 2));
	if (strings_array == NULL)
		return (NULL);
	while (nb_word-- >= 0)
	{
		if (i == 0)
		{
			strings_array[i] = malloc(sizeof(char));
			if (strings_array[i] == NULL)
				return (NULL);
			strings_array[i++][0] = '\0';
			continue ;
		}
		strings_array[i++] = get_next_word(str, separator);
	}
	strings_array[i] = NULL;
	return (strings_array);
}
