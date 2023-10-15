/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:21:32 by nosilves          #+#    #+#             */
/*   Updated: 2023/10/15 21:51:05 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_pars(char *str)
{
	int		i;
	int		n;
	long	res;

	i = 0;
	n = 1;
	res = 0;
	if (str[i] == '-')
	{
		n = n * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
	{
		printf("please, only numbers");
		return (0);
	}
	res = res * n;
	if (res > INT_MAX || res < INT_MIN)
	{
		printf("number is not valid");
		return (0);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	res = res * sign;
	return (res);
}

int	check_dubs(int *mal, int i)
{
	int	num;

	num = mal[i];
	while (--i >= 0)
	{
		if (mal[i] == num)
			return (0);
	}
	return (1);
}

int	is_ordered(int *mal, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
		return (1);
	while(i < argc - 2)
	{
		if (mal[i] > mal[i + 1])
			return(0);
		i++;
	}
	return(1);
}

int	ft_control(int *mal, char **argv, int argc)
{
	int	i;

	i = 0;
	while (i + 1 < argc)
	{
		if (argv[i + 1][0] != '\0' && (valid_pars(argv[i + 1]) == 1))
		{
			mal[i] = ft_atoi(argv[i + 1]);
			if (check_dubs(mal, i) == 0)
			{
				printf("no duplicates please!!");
				return (0);
			}
			i++;
		}
		else
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	if (is_ordered(mal, argc))
	{
		printf("que vols que faci? si ja m'ho has donat ordenta lelo...");
		return(0);
	}
	printf("Tot ok, lela");
	return (1);
}
