/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:54:34 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/09 18:59:14 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (dest[size] != '\0')
		++size;
	while (i < nb)
	{
		if (src[i] != '\0')
			dest[size + i] = src[i];
		else
			dest[size + i] = '\0';
		++i;
	}
	dest[size + i] = '\0';
	return (dest);
}
