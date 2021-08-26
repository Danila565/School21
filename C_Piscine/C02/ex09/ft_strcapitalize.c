/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:41:47 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/07 19:19:32 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_lowcase(char a)
{
	if (a >= 'a' && a <= 'z')
		return (1);
	else
		return (0);
}

int	is_upcase(char a)
{
	if (a >= 'A' && a <= 'Z')
		return (1);
	else
		return (0);
}

int	is_word(char a)
{
	if (is_upcase(a) || is_lowcase(a)
		|| (a >= '0' && a <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_word(str[i]))
		{
			if (is_lowcase(str[i]) && flag)
				str[i] -= 32;
			else
				if (is_upcase(str[i]) && !flag)
					str[i] += 32;
			flag = 0;
		}
		else
			flag = 1;
		++i;
	}
	return (str);
}
