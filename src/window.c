/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/14 16:03:40 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 16:21:25 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/smlx.h"

void				window_destroy(void *content)
{
	t_window		*win;

	win = (t_window*)content;
	mlx_destroy_window(win->mlx_id, win->id);
	free(win);
	return ;
}

t_window			*new_window(void *mlx_id, int width, int heigh, char *title)
{
	t_window		*win;

	if (!(win = (t_window *)ft_memalloc(sizeof(t_window))))
		return (0);
	if (!(win->id = mlx_new_window(mlx_id, width, heigh, title)))
		return (0);
	win->mlx_id = mlx_id;
	win->width = width;
	win->heigh = heigh;
	win->title = title;
	return (win);
}