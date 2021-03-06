/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:01:42 by kehuang           #+#    #+#             */
/*   Updated: 2018/08/06 15:26:46 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "rt_ts.h"
# include <SDL.h>
# define WIN_W 980
# define WIN_H 720

typedef struct	s_env
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	SDL_Event		evt;
	t_rtv1			core;
	unsigned char	aa;
	char			on;
}				t_env;

int				init_env(t_env *e);
void			ft_raytracer(t_env *e);
void			projection(t_env *e);
#endif
