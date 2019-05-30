/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/22 22:38:44 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 21:14:36 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/smlx.h"

void				window_add_image(t_window *win, t_image *img)
{
	payload_add(win->img, win->it, (void*)img);
	payload_next(win->img, &win->it);
	return ;
}

void				window_del_image(t_window *win, t_image *img)
{
	t_node			*cur;

	cur = win->img->begin;
	while (cur)
	{
		if (((t_image*)cur->content)->id == img->id)
		{
			payload_remove(win->img, &cur);
			break ;
		}
		cur = cur->child;
	}
	return ;
}

void				window_refresh(t_window *win)
{
	t_image			*img;
	t_node			*cur;

	cur = win->img->begin;
	while (cur)
	{
		img = cur->content;
		mlx_put_image_to_window(win->mlx_id, win->id, img->id, img->dock_x, img->dock_y);
		cur = cur->child;
	}
	return ;
}