/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:35:52 by fsanches          #+#    #+#             */
/*   Updated: 2022/04/13 17:04:50 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strlcpy()

// strlcpy() copies string up to dstsize - 1 character from string src to dst.

// Return value is the length of src.

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	if (!dst || !src)
		return (0);
	i = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}	
	return (count);
}
