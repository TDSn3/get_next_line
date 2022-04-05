/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:27:53 by tda-silv          #+#    #+#             */
/*   Updated: 2022/04/02 16:27:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	char					buffer[BUFFER_SIZE];
	char					*str;
	long long int			i;
	static long long int	s_i;
	long long int			copy_s_i;

	i = 0;
	if (BUFFER_SIZE == 0 || s_i > BUFFER_SIZE)
		return (NULL);
	while (s_i < BUFFER_SIZE)
	{ 
		read(fd, &buffer[s_i], 1);
		if (!i &&(!buffer[s_i]|| s_i > BUFFER_SIZE))
			return (NULL);
		if (!buffer[s_i])
			break;
		i++;
		if (buffer[s_i] == '\n')
			break ;
		s_i++;
	}
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = 0;
	i--;
	copy_s_i = s_i;
	if(!buffer[s_i])
		copy_s_i--;
	while (i >= 0 && copy_s_i >= 0)
	{
		str[i] = buffer[copy_s_i];
		i--, copy_s_i--;
	}
	s_i++;
	return (str);
}

//#include <stdio.h>

int	main()
{
	int			fd;
	char		*str;
	const char	*filename1 = "test1.txt";
	const char	*filename2 = "test2.txt";
	const char	*filename3 = "test3.txt";
	const char	*filename4 = "test4.txt";

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
		printf ("\n%s\n█■───\n", str);
		if (!str)
			break ;
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
		printf ("\n%s\n█■───\n", str);
		if (!str)
			break ;
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
		printf ("\n%s\n█■───\n", str);
		if (!str)
			break ;
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
		printf ("\n%s\n█■───\n", str);
		if (!str)
			break ;
		free(str);
	}
	close(fd);

	return (0);
}
