/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 02:25:58 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/21 15:28:23 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_bzero(void *s, size_t size);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb == 0 || size == 0)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}
