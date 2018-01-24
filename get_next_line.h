/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:29:43 by tcallens          #+#    #+#             */
/*   Updated: 2018/01/19 06:42:51 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_next_line_h
# define get_next_line_h

# include "libft/libft.h"

# define BUFF_SIZE 9


int	get_next_line(const int	fd, char **line);

#endif
