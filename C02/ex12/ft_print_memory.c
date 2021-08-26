/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:55:43 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/17 15:52:44 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
char hexadecimal(int a)
{	
	if (a >= 0 && a <= 9)
		return (a + '0');
	else
		return ((a % 10) + 'a');
}
void int_to_char(unsigned long a)
{
	char tmp[16];
	int i = 0;
	while (i < 16)
	{
		tmp[15-i] = hexadecimal(a % 16);
		a /= 16;
		++i;
	}
	write(1, tmp, 16);
}

int	is_print(char a)
{
	if (a >= 32 && a <= 126)
		return (1);
	else
		return (0);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char *str = addr;
	int i;
	unsigned long ad;
	int rem;
	char tab[2];
	char txt[16];
	
	rem = 0;
	i = 1;
	while (size != 0)
	{
		if(i % 16 == 1)
		{
			ad = (unsigned long) str + i;
			int_to_char(ad);
			write(1, ": ", 2);				
		}
		tab[0] = hexadecimal(str[i] / 16);
		tab[1] = hexadecimal(str[i] % 16);
		write(1, tab, 2);
		if (i % 2 == 0)
			write(1, " ", 1);
		if (is_print(str[i]))
			txt[i % 16] = str[i];
		else
			txt[i % 16] = '.';
		if(i % 16 == 0)
		{
			write(1, txt, 16);
			write(1, "\n", 1);
		}
		--size;
		++i;
			
	}
	if (i % 16 != 0)
	{	
		rem = (i % 16) - 1;
		while(i % 16 != 0)
		{
			write(1, " ", 1);
			++i;
		}
		write(1, " ", 1);
		write(1, txt, rem);
	}
	return addr;
}

