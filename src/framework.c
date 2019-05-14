/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   framework.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:37:34 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 22:42:56 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/smlx.h"

static int			destroy_hook(void)
{
	exit(1);
	return (0);
}

static void			register_hook(t_framework *mlx, t_window *win)
{
	mlx_hook(win->id, MOTIONNOTIFY, POINTERMOTIONMASK, mouse_motion_hook, mlx->mouse);
	mlx_hook(win->id, KEYPRESS, KEYPRESSMASK, key_press_hook, mlx->keyboard);
	mlx_hook(win->id, KEYRELEASE, KEYRELEASEMASK, key_release_hook, mlx->keyboard);
	mlx_hook(win->id, BUTTONPRESS, BUTTONPRESSMASK, mouse_press_hook, mlx->mouse);
	mlx_hook(win->id, BUTTONRELEASE, BUTTONRELEASEMASK, mouse_release_hook, mlx->mouse);
	return ;
}

void				framework_destroy(t_framework *mlx)
{
	mouse_destroy(mlx->mouse);
	keyboard_destroy(mlx->keyboard);
	payload_destroy(mlx->win);
	free(mlx);
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
	if (!(mlx->keyboard = new_keyboard()))
		return (0);
	if (!(mlx->mouse = new_mouse(mlx->keyboard)))
		return (0);
	if (!(win = new_window(mlx->id, width, heigh, title)))
		return (0);
	if (!(mlx->win = new_payload((void*)win, &window_destroy)))
		return (0);
	mlx->it = new_iterator(mlx->win);
	register_hook(mlx, win);
	mlx_hook(win->id, DESTROYNOTIFY, STRUCTURENOTIFYMASK, destroy_hook, 0);
	return (mlx);
}

void				framework_new_window(t_framework *mlx, int width, int heigh, char *title)
{
	t_window		*win;

	if (!(win = new_window(mlx->id, width, heigh, title)))
		return ;
	register_hook(mlx, win);
	payload_add(mlx->win, mlx->it, (void*)win);
	return ;
}


