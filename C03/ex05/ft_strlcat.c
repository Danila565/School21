/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 19:59:37 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/08 20:30:29 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dst_size;
	unsigned int	i;
	unsigned int	src_size;

	src_size = 0;
	dst_size = 0;
	i = 0;
	while (src[src_size] != '\0')
		++src_size;
	while (dest[dst_size] != '\0')
		++dst_size;
	while ((i < size - 1) && (src[i] != '\0'))
	{
		dest[dst_size + i] = src[i];
		++i;
	}
	dest[dst_size + i] = '\0';
	return (dst_size + src_size);
}
