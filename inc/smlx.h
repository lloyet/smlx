/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   smlx.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/14 15:42:45 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/13 22:04:24 by lloyet      ###    #+. /#+    ###.fr     */
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
# define RED						0x00FF0000
# define GREEN						0x0000FF00
# define BLUE						0x000000FF
# define ALPHA						0xFF000000

typedef struct		s_window
{
	void			*id;
	void			*mlx_id;
	t_node			*it;
	t_payload		*img;
	int				width;
	int				heigh;
	char			*title;
	int				(*event)(void*);
	void			*param;
}					t_window;

typedef struct		s_image
{
	void			*id;
	void			*mlx_id;
	char			*data;
	int				bpp;
	int				size_l;
	int				endian;
	int				width;
	int				heigh;
	int				dock_x;
	int				dock_y;
}					t_image;

typedef struct		s_smlx
{
	void			*id;
	t_window		*cur;
	t_node			*it;
	t_payload		*window;
	t_mouse			*mouse;
	t_keyboard		*keyboard;
}					t_smlx;

void				image_clear(t_image *img);
void				image_pixel_put(t_image *img, int x, int y, int color);
void				image_circle(t_image *img, int x, int y, int radius, int color);
void				image_fill(t_image *img, int color);

void				image_destroy(void *content);
t_image				*new_image(void *mlx_id, int width, int heigh);
void				image_dock(t_image *img, int x, int y);

t_window			*new_window(t_image *bg, char *title, int (*event)(void*), void *param);

void				window_add_image(t_window *win, t_image *img);
void				window_del_image(t_window *win, t_image *img);
void				window_refresh(t_window *win);
void				window_loop_event(t_window *win);

void				smlx_destroy(t_smlx *smlx);
t_smlx				*new_smlx(void);
t_node				*smlx_find_window(t_smlx *mlx, t_window *win);

int					smlx_init(t_smlx *mlx, t_window *win);
void				smlx_open_window(t_smlx *mlx, t_window *win);
void				smlx_close_window(t_smlx *mlx, t_window *win);

# endif
