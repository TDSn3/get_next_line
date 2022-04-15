/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:11:03 by tda-silv          #+#    #+#             */
/*   Updated: 2022/04/07 17:11:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	char			*str;
	long long int	i;

	i = 0;
	if (!BUFFER_SIZE)
		return (NULL);
	while (i < BUFFER_SIZE && read(fd, &buffer[i], 1) > 0 )
	{
		if (buffer[i++] == '\n')
			break ;
	}
	if (!i)
		return (NULL);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = 0;
	i--;
	while (i >= 0)
	{
		str[i] = buffer[i];
		i--;
	}
	return (str);
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

	fd = open(filename1, O_RDWR);
	if (fd == -1)
	{
		write(1, "\nOpen error\n", 12);
		return (0);
	}
	while (i < 5)
	{
		str = get_next_line(fd);
		printf("%s", str);
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
	return (0);
}
