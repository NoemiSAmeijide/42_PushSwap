/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:38:05 by nosilves          #+#    #+#             */
/*   Updated: 2023/10/15 21:55:01 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printst(t_stack *stz)
{
	t_fitxa	*stx;

	stx = stz->first;
	while (stx)
	{
		printf("%d ", stx->value);
		stx = stx->next;
	}
	printf("\nThe end\n");
}

void	ft_lstadd_back(t_fitxa **lst, t_fitxa *new)
{
	t_fitxa	*res;

	res = *lst;
	if (res == NULL)
		*lst = new;
	else
	{
		while (res->next != NULL)
			res = res->next;
		res->next = new;
	}
}

int createstack_sta(t_stack *sta, int *mal, int argc)
{
	int i;
	t_fitxa *new;

	i = 0;
	sta->len = 0;
	sta->first= NULL;
	while(i < argc - 1)
	{
		new = malloc(sizeof(t_fitxa));
		if (!new)
			return (0);
		new->next = NULL;
		new->value = mal[i];
		ft_lstadd_back(&sta->first, new);
		i++;
		sta->len++;
	}
	return(1);
}

int	main(int argc, char **argv)
{
	int	*mal;
	t_stack sta;
	t_stack stb;
	
	if (argc == 1)
	{
		printf("no data");
		return(1);
	}
	mal = malloc(sizeof(int) * argc);
	if (!mal)
		return (1);
	if (ft_control(mal, argv, argc) == 0){
		free(mal);
		return (1);
	}
	createstack_sta(&sta, mal, argc);
	stb.len = 0;
	stb.first = NULL;
	printst(&sta);
}
