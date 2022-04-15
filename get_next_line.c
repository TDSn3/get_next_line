/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:27:53 by tda-silv          #+#    #+#             */
/*   Updated: 2022/04/13 12:55:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

size_t	ft_strlen_stop_nl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	t_list			*list;
	char			*str;
	char			*str_two;
	char			*str_three;
	int				i;

	i = 0;
	str = 0;
	str_two = 0;
	str_three = 0;
	if (BUFFER_SIZE == 0)
		return (NULL);
	if (*buffer && ft_strchr(buffer, '\n') && ft_strlen(ft_strchr(buffer, '\n')) > 1)
	{
		ft_strlcpy(buffer, ft_strchr(buffer, '\n') + 1, ft_strlen(ft_strchr(buffer, '\n')));
	}
	while ((i = read(fd, buffer, BUFFER_SIZE)) <= BUFFER_SIZE)
	{		
		if (!str)
		{
			str = malloc(ft_strlen_stop_nl(buffer) + 1);
			ft_strlcpy(str, buffer, ft_strlen_stop_nl(buffer) + 1);
			if (ft_strchr(buffer, '\n') || i < 1)
				return (str) ;
		}
		else
		{
			str_two = malloc(ft_strlen_stop_nl(buffer) + 1);
			ft_strlcpy(str_two, buffer, ft_strlen_stop_nl(buffer) + 1);
			str_three = ft_strjoin (str, str_two);
			free(str);
			free(str_two);
			str = str_three;
		}
		if (ft_strchr(buffer, '\n') || i < 1)
			break ;
	}
	return (str_three);
}

int	main()
{
	int			i = 0;
	int			fd;
	char		*str;
	const char	*filename1 = "test1.txt";
	const char	*filename2 = "test2.txt";
	const char	*filename3 = "test3.txt";
	const char	*filename4 = "test4.txt";

//	test 0   ///////////////////////////////////////

	fd = open(filename4, O_RDWR);
	if (fd == -1)
	{
		write(1, "\nOpen error\n", 12);
		return (0);
	}
	while (i < 10)
	{
		str = get_next_line(fd);
		printf("|%s", str);
		free(str);
		i++;
	}
		close(fd);
/*
//	test 1   ///////////////////////////////////////

	fd = open(filename1, O_RDWR);
	if (fd == -1)
	{
		write(1, "\nOpen error\n", 12);
		return (0);
	}

	for (int i = 0; i < 9999; i++)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf ("%s", str);
		free(str);
	}
	close(fd);
	printf ("\n█████████████████████████test 2 - empty file\n");

//	test 2   ///////////////////////////////////////

	fd = open(filename2, O_RDWR);
	if (fd == -1)
	{
		write(1, "\nOpen error\n", 12);
		return (0);
	}
	
	for (int i = 0; i < 9999; i++)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf ("%s", str);
		free(str);
	}
	close(fd);
	printf ("\n█████████████████████████test 3 - empty first line with new line\n");

//	test 3   ///////////////////////////////////////

	fd = open(filename3, O_RDWR);
	if (fd == -1)
	{
		write(1, "\nOpen error\n", 12);
		return (0);
	}
	
	for (int i = 0; i < 9999; i++)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf ("%s", str);
		free(str);
	}
	close(fd);
	printf ("\n█████████████████████████test 4 - one line\n");

//	test 4   ///////////////////////////////////////

	fd = open(filename4, O_RDWR);
	if (fd == -1)
	{
		write(1, "\nOpen error\n", 12);
		return (0);
	}
	
	for (int i = 0; i < 9999; i++)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf ("%s", str);
		free(str);
	}
	close(fd);
*/
//
	return (0);
}

