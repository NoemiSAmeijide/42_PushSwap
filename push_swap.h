/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:39:14 by nosilves          #+#    #+#             */
/*   Updated: 2023/10/15 20:48:35 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_fitxa
{
	int				value;
	int				game_num;
	struct s_fitxa	*next;
}					t_fitxa;

typedef struct s_stack
{
	int			len;
	t_fitxa 	*first;
}					t_stack;

int	ft_control(int *mal, char **argv, int argc);
int	check_dubs(int *mal, int i);
int	ft_atoi(char *str);
int	valid_pars(char *str);

#endif
