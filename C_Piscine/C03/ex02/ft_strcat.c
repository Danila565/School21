/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:41:40 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/08 19:46:31 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (dest[size] != '\0')
		++size;
	while (src[i] != '\0')
	{
		dest[size + i] = src[i];
		++i;
	}
	dest[size + i] = '\0';
	return (dest);
}
