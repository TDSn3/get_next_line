/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:18:51 by tda-silv          #+#    #+#             */
/*   Updated: 2022/04/11 16:18:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 9999
#endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	int				fd;
    struct s_data   *next;
}	t_data;

char	*get_next_line(int fd);

#endif