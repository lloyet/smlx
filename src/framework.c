/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   framework.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:37:34 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/02 20:57:20 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/smlx.h"

void				smlx_destroy(t_smlx *mlx)
{
	mouse_destroy(mlx->mouse);
	keyboard_destroy(mlx->keyboard);
	payload_destroy(mlx->window);
	free(mlx);
	exit(1);
	return ;
}

t_smlx				*new_smlx(void)
{
	t_smlx		*mlx;

	if (!(mlx = (t_smlx *)ft_memalloc(sizeof(t_smlx))))
		return (0);
	if (!(mlx->id = mlx_init()))
		return (0);
	if (!(mlx->keyboard = new_keyboard()))
		return (0);
	if (!(mlx->mouse = new_mouse(mlx->keyboard)))
		return (0);
	return (mlx);
}

void				smlx_del_window(t_smlx *mlx, t_window *win)
{
	if (win != mlx->window->begin->content)
	{
		if (win != mlx->cur)
			mlx->it = smlx_find_window(mlx, win);
		payload_remove(mlx->window, &mlx->it);
		mlx->cur = (t_window*)mlx->it->content;
	}
	keyboard_reset(mlx->keyboard);
	return ;
}

void				smlx_close_window(t_smlx *mlx, t_window *win)
{
	mlx_destroy_window(win->mlx_id, win->id);
	smlx_del_window(mlx, win);
	return ;
}

t_node				*smlx_find_window(t_smlx *mlx, t_window *win)
{
	t_node			*cur;

	cur = mlx->window->begin;
	while (cur)
	{
		if (cur->content == win)
			return (cur);
		cur = cur->child;
	}
	return (0);
}
