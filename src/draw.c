/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 17:33:22 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 16:00:44 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/smlx.h"

void				image_clear(t_image *img)
{
	ft_bzero(img->data, img->width * img->heigh * img->bpp);
	return ;
}

void				image_pixel_put(t_image *img, int x, int y, int color)
{
	*(int *)(img->data + ((x + y * img->width) * img->bpp)) = color;
	return ;
}

void				image_circle(t_image *img, int x0, int y0, int radius, int color)
{
	int				f;
	int				ddf_x;
	int				ddf_y;
	int				x;
	int				y;

	while (radius > 0)
	{
		f = 1 - radius;
		ddf_x = 0;
		ddf_y = -2 * radius;
		x = 0;
		y = radius;
		image_pixel_put(img, x0, y0 + radius, color);
		image_pixel_put(img, x0, y0 - radius, color);
		image_pixel_put(img, x0 + radius, y0, color);
		image_pixel_put(img, x0 - radius, y0, color);
		while(x < y) 
		{
			if(f >= 0) 
			{
				y--;
				ddf_y += 2;
				f += ddf_y;
			}
			x++;
			ddf_x += 2;
			f += ddf_x + 1;
			image_pixel_put(img, x0 + x, y0 + y, color);
			image_pixel_put(img, x0 - x, y0 + y, color);
			image_pixel_put(img, x0 + x, y0 - y, color);
			image_pixel_put(img, x0 - x, y0 - y, color);
			image_pixel_put(img, x0 + y, y0 + x, color);
			image_pixel_put(img, x0 - y, y0 + x, color);
			image_pixel_put(img, x0 + y, y0 - x, color);
			image_pixel_put(img, x0 - y, y0 - x, color);
		}
		radius--;
	}
	return ;
}

void				image_fill(t_image *img, int color)
{
	int				n;

	n = (img->width - 1) + ((img->heigh - 1) * img->width);
	while (n)
		*(int *)(img->data + (n-- * img->bpp)) = color;
	return ;
}
