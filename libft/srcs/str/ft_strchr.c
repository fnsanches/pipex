/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:38:27 by fsanches          #+#    #+#             */
/*   Updated: 2022/07/01 01:18:43 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strchr()

// strchr() returns a pointer to the first occurrence of the character c in
// the string s.

// Return value is a pointer to matched character or NULL if not found.

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
