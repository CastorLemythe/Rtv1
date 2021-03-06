/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 10:41:05 by kehuang           #+#    #+#             */
/*   Updated: 2018/08/21 18:51:16 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_int.h"

static int	get_vec(t_rtv1 *core, t_cur *fcur, char *cfile)
{
	t_vec3	*ptr;

	if (core->mask & KEY_CAM)
	{
		if (core->mask & (KEY_POS << 16))
			ptr = &core->cam.ray.pos;
		else
			ptr = &core->cam.rotate;
	}
	else if (core->mask & KEY_LIGHT)
		take_light_pos(core, &ptr);
	else
		take_obj_vec(core, &ptr);
	if (ft_atod_sep(fcur, &ptr->x, cfile, 1) == -1)
		return (-1);
	if (ft_atod_sep(fcur, &ptr->y, cfile, 1) == -1)
		return (-1);
	if (ft_atod_sep(fcur, &ptr->z, cfile, 0) == -1)
		return (-1);
	return (0);
}

static int	handle_arr(t_rtv1 *core, t_cur *fcur, int size, char *cfile)
{
	if (cfile[fcur->i] != '[')
		return (-1);
	fcur->i++;
	fcur->x++;
	ft_zjump(fcur, cfile);
	if (size == 4)
	{
		if (get_clr(core, fcur, cfile) == -1)
			return (-1);
	}
	else if (get_vec(core, fcur, cfile) == -1)
		return (-1);
	ft_zjump(fcur, cfile);
	if (cfile[fcur->i] != ']')
		return (-1);
	fcur->i++;
	fcur->x++;
	return (0);
}

static int	get_data(t_rtv1 *core, t_cur *fcur, char *cfile, unsigned char key)
{
	if (key & KEY_POS || key & KEY_ROT || key & KEY_NORMAL)
	{
		if (handle_arr(core, fcur, 3, cfile) == -1)
			return (-1);
	}
	else if (key & KEY_COLOR)
	{
		if (handle_arr(core, fcur, 4, cfile) == -1)
			return (-1);
	}
	else if (handle_double(core, fcur, cfile) == -1)
		return (-1);
	return (0);
}

int			json_val(t_rtv1 *core, t_cur *fcur, char *cfile)
{
	unsigned char	key;

	if (core->mask & MASK_OBJ)
	{
		if (cfile[fcur->i] != '{')
			return (-1);
		fcur->i++;
		fcur->x++;
		core->mask = core->mask ^ MASK_OBJ;
	}
	else
	{
		key = ((core->mask >> 16) & 0xff);
		if (get_data(core, fcur, cfile, key) == -1)
			return (-1);
		core->mask = core->mask & 0xff00ffff;
		if (check_sep_val(core, fcur, cfile) == -1)
			core->mask = core->mask | MASK_STOP;
	}
	return (0);
}
