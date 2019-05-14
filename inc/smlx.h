/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   smlx.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/14 15:42:45 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 22:12:06 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# ifndef _SMLX_H
# define _SMLX_H

# include "../libft/inc/libft.h"
# include "../libhook/inc/libhook.h"
# include "../payload/inc/payload.h"
# include "../minilibx_macos/mlx.h"

# define RGBA(r,g,b,a)				(a << 24) | (r << 16) | (g << 8) | (b)

typedef struct		s_window
{
	void			*id;
	void			*mlx_id;
	int				width;
	int				heigh;
	char			*title;
}					t_window;

typedef struct		s_image
{
	void			*id;
	t_window		*win;
	char			*data;
	int				bpp;
	int				size_l;
	int				endian;
	int				width;
	int				heigh;
}					t_image;

typedef struct		s_framework
{
	void			*id;
	t_node			*it;
	t_payload		*win;
	t_mouse			*mouse;
	t_keyboard		*keyboard;
}					t_framework;

void				image_clear(t_image *img);
void				image_pixel_put(t_image *img, int x, int y, int color);
void				image_fill(t_image *img, int color);

void				image_destroy(t_image *img);
t_image				*new_image(t_window *win, int width, int heigh);
void				image_attach(t_image *img, t_window *win);

void				window_destroy(void *win);
t_window			*new_window(void *mlx_id, int width, int heigh, char *title);
t_window			*window_found(t_framework *mlx, char *title);

void				framework_new_window(t_framework *mlx, int width, int heigh, char *title);
void				framework_destroy(t_framework *framework);
t_framework			*new_framework(int width, int heigh, char *title);

# endif