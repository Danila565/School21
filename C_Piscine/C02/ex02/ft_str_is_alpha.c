/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:37:17 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/07 17:03:53 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_letter(char a)
{
	if (a < 'A' || a > 'z' || (a > 'Z' && a < 'a'))
		return (0);
	else
		return (1);
}

int	ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_letter(str[i]))
			return (0);
		++i;
	}
	return (1);
}
