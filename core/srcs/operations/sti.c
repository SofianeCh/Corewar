/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <hvromman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:51:14 by hvromman          #+#    #+#             */
/*   Updated: 2019/08/01 21:36:09 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		operation_sti(t_champ *champ, t_proces *proces, t_arg *args)
{
	int		second_arg;
	int		third_arg;

	champ = NULL;
	if (args[1].type & T_REG)
		second_arg = proces->reg[args[1].value];
	else
		second_arg = args[1].value;
	if (args[2].type & T_REG)
		third_arg = proces->reg[args[2].value];
	else
		third_arg = args[2].value;
	jump_to(0, 65);
	ft_printf("second_arg %.8x, third_arg %.8x", second_arg, third_arg);
	write_int(proces, calc_pc(proces->pc + (second_arg + third_arg)), proces->reg[args[0].value]);
	return (1);
}
