/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/14 16:03:40 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/02 20:38:25 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/smlx.h"

static void			window_img_destroy(void *content)
{
	free(content);
	return ;
}

void				window_destroy(void *content)
{
	t_window		*win;

	win = (t_window*)content;
	payload_destroy(win->img);
	free(win);
	return ;
}

t_window			*new_window(t_image *bg, char *title, int (*event)(void*), void *param)
{
	t_window		*win;

	if (!(win = (t_window *)ft_memalloc(sizeof(t_window))))
		return (0);
	if (!(win->id = mlx_new_window(bg->mlx_id, bg->width, bg->heigh, title)))
		return (0);
	if (!(win->img = new_payload((void*)bg, &window_img_destroy)))
		return (0);
	win->it = new_iterator(win->img);
	win->width = bg->width;
	win->heigh = bg->heigh;
	win->mlx_id = bg->mlx_id;
	win->event = event;
	win->param = param;
	win->title = title;
	return (win);
}
