/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:38:20 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 15:59:13 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/smlx.h"

void				image_destroy(t_image *img)
{
	mlx_destroy_image(img->win->mlx_id, img->id);
	free(img);
	return ;
}

t_image				*new_image(t_window *win, int width, int heigh)
{
	t_image			*img;

	if (!(img = (t_image *)ft_memalloc(sizeof(t_image))))
		return (0);
	if (!(img->id = mlx_new_image(win->mlx_id, width, heigh)))
		return (0);
	img->win = win;
	img->width = width;
	img->heigh = heigh;
	img->data = mlx_get_data_addr(img->id, &img->bpp,
		&img->size_l, &img->endian);
	img->bpp /= 8;
	return (img);
}

void				image_attach(t_image *img, t_window *win)
{
	img->win = win;
	return ;
}
