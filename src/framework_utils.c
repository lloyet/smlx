/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   framework_utils.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/20 03:25:14 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/30 03:23:39 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/smlx.h"

extern void			framework_del_window(t_framework *mlx, t_window *win);
extern void			window_destroy(void *content);

static t_framework	*mlx_instance;
	
static int			destroy_hook(t_window *win)
{
	if (win != mlx_instance->window->begin->content)
	{
		mlx_instance->cur = win;
		mlx_instance->it = framework_find_window(mlx_instance, win);
		framework_del_window(mlx_instance, win);
	}
	else
		framework_del_window(mlx_instance, win);
	keyboard_reset(mlx_instance->keyboard);
	return (0);
}

static int			focus_hook(t_window *win)
{
	mlx_instance->cur = win;
	mlx_instance->it = framework_find_window(mlx_instance, win);
	keyboard_reset(mlx_instance->keyboard);
	return (0);
}

static void			register_hook(t_framework *mlx, t_window *win)
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

int					framework_init(t_framework *mlx, t_window *win)
{
	if (!(mlx->window = new_payload((void*)win, &window_destroy)))
		return (0);
	mlx->it = new_iterator(mlx->window);
	mlx->cur = win;
	register_hook(mlx, win);
	mlx_instance = mlx;
	return (1);
}

void				framework_open_window(t_framework *mlx, t_window *win)
{
	register_hook(mlx, win);
	payload_add(mlx->window, mlx->it, (void*)win);
	payload_next(mlx->window, &mlx->it);
	mlx->cur = win;
	keyboard_reset(mlx->keyboard);
	return ;
}
