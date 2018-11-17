/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:05:06 by kehuang           #+#    #+#             */
/*   Updated: 2018/04/11 13:07:40 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strnlen(char const *str, char c)
{
	int		len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	return (len);
}