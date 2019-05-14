/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   framework.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:37:34 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 17:14:18 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/smlx.h"

void				framework_destroy(t_framework *mlx)
{
	
	payload_destroy(mlx->win);
	free(mlx);
	return ;
}

void				framework_add(t_framework *mlx, t_window *win)
{
	payload_add(mlx->win, mlx->win_it, (void*)win);
	return ;
}

void				framework_remove(t_framework *mlx)
{
	payload_remove(mlx->win, &mlx->win_it);
	return ;
}

t_framework			*new_framework(int width, int heigh, char *title)
{
	t_framework		*mlx;
	t_window		*win;

	if (!(mlx = (t_framework *)ft_memalloc(sizeof(t_framework))))
		return (0);
	if (!(mlx->id = mlx_init()))
		return (0);
	if (!(win = new_window(mlx->id, width, heigh, title)))
		return (0);
	if (!(mlx->win = new_payload((void*)win, &window_destroy)))
		return (0);
	mlx->win_it = new_iterator(mlx->win);
	return (mlx);
}
