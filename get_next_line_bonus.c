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

static size_t	ft_strlen_stop_nl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static int	ft_strchr_buffer_nl(char *buffer_p, int i)
{
	size_t	j;
	char	*buffer_start_nl;

	buffer_start_nl = ft_strchr(buffer_p, '\n');
	if (buffer_start_nl || i < 1)
	{
		j = ft_strlen(buffer_start_nl);
		if (j > 1 && i > 0)
			ft_strlcpy(buffer_p, buffer_start_nl + 1, j);
		else
			ft_bzero(buffer_p, BUFFER_SIZE);
		return (1);
	}
	else
		return (0);
}

static int	ft_start_gnl(char *buffer_p, char **str, char **str_three, int *i)
{
	*i = 1;
	*str = 0;
	*str_three = 0;
	if (*buffer_p)
	{
		*str = malloc(ft_strlen_stop_nl(buffer_p) + 1);
		ft_strlcpy(*str, buffer_p, ft_strlen_stop_nl(buffer_p) + 1);
		if (ft_strchr_buffer_nl(buffer_p, *i))
			return (1);
	}
	return (0);
}

static int	ft_in_while(char *buffer_p, char **str, char **str_three, int i)
{	
	char	*str_two;

	if (i < BUFFER_SIZE)
		ft_bzero(buffer_p + i, BUFFER_SIZE - i);
	if (!*str)
	{
		*str = malloc(ft_strlen_stop_nl(buffer_p) + 1);
		ft_strlcpy(*str, buffer_p, ft_strlen_stop_nl(buffer_p) + 1);
		if (ft_strchr_buffer_nl(buffer_p, i))
			return (1);
	}
	else
	{
		str_two = malloc(ft_strlen_stop_nl(buffer_p) + 1);
		ft_strlcpy(str_two, buffer_p, ft_strlen_stop_nl(buffer_p) + 1);
		*str_three = ft_strjoin (*str, str_two);
		free(*str);
		free(str_two);
		*str = *str_three;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*str;
	char		*str_three;
	int			i;

	if (BUFFER_SIZE == 0 || read(fd, buffer[fd], 0) == -1)
		return (NULL);
	if (ft_start_gnl(buffer[fd], &str, &str_three, &i))
		return (str);
	while (i <= BUFFER_SIZE && i > 0)
	{
		i = read(fd, buffer[fd], BUFFER_SIZE);
		if (i > BUFFER_SIZE || i < 1)
			break ;
		if (ft_in_while(buffer[fd], &str, &str_three, i))
			return (str);
		if (ft_strchr(buffer[fd], '\n') || i < 1)
			break ;
	}
	if (ft_strchr_buffer_nl(buffer[fd], i) && i == 0)
		return (str);
	return (str_three);
}
/*
int	main()
{
	int			i = 0;
	int			fd1;
	int			fd2;
	int			fd3;
	int			fd4;
	int			fd5;

	char		*str1;
	char		*str2;
	char		*str3;
	char		*str4;
	char		*str5;

	const char	*filename1 = "test1.txt";
	const char	*filename2 = "test2.txt";
	const char	*filename3 = "test3.txt";
	const char	*filename4 = "test4.txt";
	const char	*filename5 = "test5.txt";

//	test 0   ///////////////////////////////////////

	fd1 = open(filename1, O_RDWR);
	fd2 = open(filename2, O_RDWR);
	fd3 = open(filename3, O_RDWR);
	fd4 = open(filename4, O_RDWR);
	fd5 = open(filename5, O_RDWR);

	if ((fd1 || fd2 || fd3 || fd4 || fd5) == -1)
	{
		write(1, "\nOpen error\n", 12);
		return (0);
	}
	while (i < 100)
	{
		str1 = get_next_line(fd1);
		str2 = get_next_line(fd2);
		str3 = get_next_line(fd3);
		str4 = get_next_line(fd4);
		str5 = get_next_line(fd5);

		printf("|%s", str1);
		printf("|%s", str2);
		printf("|%s", str3);
		printf("|%s", str4);
		printf("|%s", str5);

		free(str1);
		free(str2);
		free(str3);
		free(str4);
		free(str5);
		i++;
	}
		close(fd1);
		close(fd2);
		close(fd3);
		close(fd4);
		close(fd5);
//
	return (0);
}
*/
