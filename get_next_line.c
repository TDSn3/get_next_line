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

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

#define BUFFER_SIZE 0

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	char			*str;
	size_t			i;
	static size_t	s_i;
	size_t			copy_s_i;

	i = 0;
//	printf("\ns_i = %zu", s_i);
	while (s_i < BUFFER_SIZE)
	{ 
		read(fd, &buffer[s_i], 1);
//		printf("\nread[%zu] (i = %zu)", s_i, i);
		if (buffer[s_i] == '\n')
			break ;
		else if (buffer[s_i] == 0)
			return (NULL);
		i++, s_i++;
	}
	str = malloc(i + 2);
//	printf("\n\nmalloc(%zu)\n", i + 1);
	if (!str)
		return (NULL);
	str[i + 1] = 0;
	str[i] = '\n';
//	printf("\nstr[%zu] = 0;", i + 1);
//	printf("\nstr[%zu] = n;", i);
	copy_s_i = s_i;
//	printf("\ni = %zu", i);
	if (i == 1)
	{
		str[i - 1] = buffer[s_i - 1];
//		printf("\nstr[%zu] = %c", i - 1, str[i - 1]);
	}
	else if (i > 1 && copy_s_i > 1)
	{
		i--, copy_s_i--;
//		printf("\ni = %zu | copy_s_i = %zu\n", i, copy_s_i);
		while (i > 0)
		{
			str[i] = buffer[copy_s_i];
//			printf("\nstr[%zu] = %c", i, str[i]);
			i--, copy_s_i--;
//			printf("\ni = %zu", i);
		}
		str[i] = buffer[copy_s_i];
//		printf("\nstr[%zu] = %c", i, str[i]);
	}
	s_i++;
	return (str);
	
}

//#include <stdio.h>

int	main()
{
	int fd;
	const char *filename = "fichier.txt";

	fd = open(filename, O_RDWR);
	if (fd == -1)
	{
		write(1, "\nOpen error\n", 12);
		return (0);
	}
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	printf ("\n%s\n_____\n", get_next_line(fd));
	
	close(fd);
	return (0);
}