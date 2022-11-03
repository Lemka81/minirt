/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <cojacque@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:34:32 by cojacque          #+#    #+#             */
/*   Updated: 2022/11/03 21:47:12 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

# define KEY_ESC 53             //перенести в хедэр

int	ft_esc_close(int key, t_store *st)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_image(st->vp.mlx, st->vp.mlx_image);
	    mlx_destroy_window(st->vp.mlx, st->vp.mlx_win);
	    free(st->vp.mlx);
		exit(0);
	}
	return (0);
}

int	ft_close_red_cross(t_store *st)
{
	mlx_destroy_image(st->vp.mlx, st->vp.mlx_image);
	mlx_destroy_window(st->vp.mlx, st->vp.mlx_win);
	free(st->vp.mlx);
	exit(0);
}

void	ft_hooks(t_store *st)
{
	mlx_hook(st->vp.mlx_win, 2, 0L, ft_esc_close, st);
	mlx_hook(st->vp.mlx_win, 17, 0L, ft_close_red_cross, st);
}
