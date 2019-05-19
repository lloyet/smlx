/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/14 16:03:40 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/19 15:28:14 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/smlx.h"

void				window_destroy(void *content)
{
	t_window		*win;

	if (content)
	{
		win = (t_window*)content;
		mlx_destroy_window(win->mlx_id, win->id);
		free(win->info);
		free(win);
	}
	return ;
}

t_window			*window_found(t_framework *mlx, uint64_t info_id)
{
	t_node			*cur;

	cur = mlx->win->begin;
	while (cur)
	{
		if (((t_window*)cur->content)->info->id == info_id)
			return ((t_window*)cur->content);
		cur = cur->child;
	}
	return (0);
}

t_window			*new_window(void *mlx_id, t_info *info)
{
	t_window		*win;

	if (!(win = (t_window *)ft_memalloc(sizeof(t_window))))
		return (0);
	if (!(win->id = mlx_new_window(mlx_id, info->width, info->heigh, info->title)))
		return (0);
	win->mlx_id = mlx_id;
	win->info = info;
	return (win);
}