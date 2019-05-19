/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   info.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/19 14:27:28 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/19 14:55:36 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/smlx.h"

static uint64_t		id = 0;

t_info				*new_info(int width, int heigh, char *title)
{
	t_info			*i;

	if (!(i = (t_info*)ft_memalloc(sizeof(t_info))))
		return (0);
	i->width = width;
	i->heigh = heigh;
	i->title = title;
	i->id = id++;
	return (i);
}