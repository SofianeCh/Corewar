/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:51:10 by hvromman          #+#    #+#             */
/*   Updated: 2019/07/18 13:51:11 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		operation_st(t_champ *champ, t_proces *proces, t_arg *args) // idem copie 1 ou 4 bytes ?
{
	champ = NULL;
	if (args[0].value > REG_NUMBER || args[0].value < 1)
		return (-1);
	if (args[1].type & T_REG)
	{
		if (args[1].value > REG_NUMBER || args[1].value < 1)
			return (-1);
		else
			proces->reg[args[1].value - 1] = proces->reg[args[0].value - 1];
	}
	else
		g_all.arena[calc_pc(proces->pc + args[1].value % IDX_MOD)] = proces->reg[args[0].value - 1];
	return (0);
}
