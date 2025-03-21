/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:50:03 by yudemir           #+#    #+#             */
/*   Updated: 2025/03/21 20:30:07 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;

	sign = 1;
	fraction = 1.0;
	result = 0.0;
	if (*str++ == '-')
		sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			fraction *= 0.1;
			result += (*str - '0') * fraction;
			str++;
		}
	}
	return (sign * result);
}

int	test(char *arg1, char *arg2)
{
	int	i;

	i = 0;
	while ((arg1[i] >= '0' && arg1[i] <= '9') || arg1[i] == '.'
		|| arg1[i] == '-')
		i++;
	if (!(arg1[i] == '\0'))
		return (1);
	i = 0;
	while ((arg2[i] >= '0' && arg2[i] <= '9') || arg2[i] == '.'
		|| arg2[i] == '-')
	{
		i++;
	}
	if (!(arg2[i] == '\0'))
		return (1);
	return (0);
}
