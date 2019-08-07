/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofchami <sofchami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 02:28:56 by sofchami          #+#    #+#             */
/*   Updated: 2019/08/07 02:33:51 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		print_proces_info(int i)
{
	int k;
	int n;
	int l;
	int opcode;

	n = -1;
	l = 0;
	jump_to(X, i);
	ft_printf("%1$/40c All proces %1$/40c\n", '-');
	i++;
	while (++n < g_all.nb_champ)
	{
		k = -1;
		while (++k < g_all.champ[n].nb_proces)
		{
			jump_to(X, i + k + l+ (n ? g_all.champ[n - 1].nb_proces : 0));
			opcode = g_all.champ[n].proces[k].opcode;
			ft_printf("player_nb %2d  |  proces_id %2d  |  pc %4d  |  opcode " CHAR_HEX_PRINT "  |  Name OP %5s  |  cycle_left %4d\n", g_all.champ[n].player_nb, g_all.champ[n].proces[k].id_proces, g_all.champ[n].proces[k].pc, opcode, g_op_tab[opcode].name, g_all.champ[n].proces[k].cycle_left);
		}
		n ? l += k : 0;
	}
	return (0);
}

int		print_player_info(int i)
{
	int k;

	k = -1;
	while (++k < g_all.nb_champ)
	{
		jump_to(X, i);
		ft_printf("PLAYER %d : %s", g_all.champ[k].player_nb, g_all.champ[k].player_name);
		i++;
		jump_to(X + 5, i);
		ft_printf("Last live : %1$/20c %d", ' ', g_all.champ[k].lives_period);
		i++;
	}
	i++;
	return (i);
}

int		print_init_info(int i)
{
	int lives;

	lives = 0;
	while (++i < g_all.nb_champ)
		lives += g_all.champ[i].lives_period;
	jump_to(X, 0);
	ft_printf("%1$/40c Info %1$/40c\n", '-');
	i = 0;
	while (++i < 5)
	{
		jump_to(X, i);
		i == 1 ? ft_printf("Cycles = %4d", g_all.cycle) : 0;
		i == 2 ? ft_printf("Nbr de proces = %4d", g_all.nb_proces_tot) : 0;
		i == 3 ? ft_printf("Lives period = %4d", lives) : 0;
	}
	i = print_player_info(i);
	i++;
	return (i);
}

int		print_vm_info()
{
	int i;

	i = print_init_info(-1);
	print_proces_info(i);
	if (g_all.max_proces <= g_all.nb_proces_tot)
		g_all.max_proces = g_all.nb_proces_tot;
	else
	{
		int tmp;
		tmp = g_all.nb_proces_tot + i;
		while (tmp < g_all.max_proces + i)
		{
			jump_to(X, tmp);
			ft_printf("%1$/80c", ' ');
			tmp++;
		}
	}
	return (0);
}
