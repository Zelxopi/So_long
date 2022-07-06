/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:55:35 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/22 12:04:28 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//find string's length
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return(0);
	while (*s++)
		len++;
	return (len);
}
