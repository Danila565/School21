/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:43:48 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/21 15:07:26 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *c);

void	ft_putstr_fd(char *s, int fd)
{
	size_t	n;

	n = ft_strlen(s);
	write(fd, s, n);
}
