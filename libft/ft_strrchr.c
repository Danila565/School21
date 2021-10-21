/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:38:21 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/07 00:38:21 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int a)
{
	char	c;
	char	*p;
	char	*res;

	p = (char *) s;
	res = (void *)(0);
	if (!p)
		return ((void *)(0));
	c = (char) a;
	while (*p != '\0')
	{
		if (c == *p)
			res = p;
		++p;
	}
	if (c == *p)
		res = p;
	return (res);
}
