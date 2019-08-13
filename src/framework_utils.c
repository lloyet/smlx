/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   framework_utils.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/20 03:25:14 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 14:50:22 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/smlx.h"

extern void			smlx_del_window(t_smlx *mlx, t_window *win);
extern void			window_destroy(void *content);

static t_smlx		*smlx_instance;
	
static int			destroy_hook(t_window *win)
{
	if (win != smlx_instance->window->begin->content)
	{
		smlx_instance->cur = win;
		smlx_instance->it = smlx_find_window(smlx_instance, win);
	}
	else
		smlx_destroy(smlx_instance);
	smlx_del_window(smlx_instance, win);
	keyboard_reset(smlx_instance->keyboard);
	return (0);
}

static int			focus_hook(t_window *win)
{
	smlx_instance->cur = win;
	smlx_instance->it = smlx_find_window(smlx_instance, win);
	keyboard_reset(smlx_instance->keyboard);
	return (0);
}

static void			register_hook(t_smlx *mlx, t_window *win)
{
	mlx_hook(win->id, MOTIONNOTIFY, POINTERMOTIONMASK, &mouse_motion_hook, mlx->mouse);
	mlx_hook(win->id, KEYPRESS, KEYPRESSMASK, &key_press_hook, mlx->keyboard);
	mlx_hook(win->id, KEYRELEASE, KEYRELEASEMASK, &key_release_hook, mlx->keyboard);
	mlx_hook(win->id, BUTTONPRESS, BUTTONPRESSMASK, &mouse_press_hook, mlx->mouse);
	mlx_hook(win->id, BUTTONRELEASE, BUTTONRELEASEMASK, &mouse_release_hook, mlx->mouse);
	mlx_hook(win->id, DESTROYNOTIFY, STRUCTURENOTIFYMASK, &destroy_hook, win);
	mlx_hook(win->id, FOCUSIN, FOCUSCHANGEMASK, &focus_hook, win);
	return ;
}

int					smlx_init(t_smlx *mlx, t_window *win)
{
	if (!(mlx->window = new_payload((void*)win, &window_destroy)))
		return (0);
	mlx->it = new_iterator(mlx->window);
	mlx->cur = win;
	register_hook(mlx, win);
	smlx_instance = mlx;
	return (1);
}

void				smlx_open_window(t_smlx *mlx, t_window *win)
{
	register_hook(mlx, win);
	payload_add(mlx->window, mlx->it, (void*)win);
	payload_next(mlx->window, &mlx->it);
	mlx->cur = win;
	keyboard_reset(mlx->keyboard);
	return ;
}
