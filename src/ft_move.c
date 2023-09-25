/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 02:38:51 by aguede            #+#    #+#             */
/*   Updated: 2023/09/23 18:57:51 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_check_collec_and_exit(t_game *game, char c)
{
	if (c == 'C')
	{
		game->collectibles_count--;
		ft_printf("le nombre de collectible est %d\n", game->collectibles_count);
	}
	if (c == 'C' && game->collectibles_count == 0)
		ft_printf("Time to get the fuck outttaaa Heree !!!\n");
	if (c == 'E' && game->collectibles_count != 0)
		ft_printf("first you need to get the collectibles carayouuuu\n");
	if (c == 'E' && game->collectibles_count == 0)
		game->exit_flag = TRUE;
}
