/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:30:19 by inskim            #+#    #+#             */
/*   Updated: 2023/02/06 11:39:55 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

static	int	whitespace(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

static	int	sign(char c, int *min)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			(*min)++;
		return (1);
	}
	return (0);
}

int	ft_atoi(char *nptr, int *overflow)
{
	int			min;
	long long	tmp;

	if (nptr == 0)
		return (0);
	while (whitespace(*nptr))
		nptr++;
	min = 0;
	if (sign(*nptr, &min))
		nptr++;
	if (ft_strlen(nptr) > 10)
		*overflow = 1;
	tmp = 0;
	while ('0' <= *nptr && *nptr <= '9')
		tmp = tmp * 10 + *nptr++ - '0';
	if ((!min && tmp > INT_MAX) || (min && - tmp < INT_MIN))
		*overflow = 1;
	if (min % 2)
		return (-tmp);
	return (tmp);
}

int	set_arg(int arg[], int argc, char *argv[])
{
	int	overflow;
	int	i;

	if (argc < 4 || argc > 5)
		return (0);
	if (argc == 4)
		arg[4] = -1;
	overflow = 0;
	while (argc-- > 0)
	{
		i = -1;
		while ((*argv)[++i])
			if ((*argv)[i] < '0' || (*argv)[i] > '9')
				return (0);
		*arg = ft_atoi(*argv++, &overflow);
		if (*arg++ < 0 || overflow)
			return (0);
	}
	return (1);
}
