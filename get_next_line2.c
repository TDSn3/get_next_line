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

int	chrn(t_list *list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (list)
	{
		while (list->content[j] && list->content[j++] != '\n')
			i++;
		if (list->content[j -1] && list->content[j - 1] == '\n')
		{
			i++;
			break ;
		}
		j = 0;
		list = list->next;
	}
	return (i);
}

char	*test(long long int i, t_list *list)
{
	int 	j;
	int		k;
	int		l;
	char	*str;
	
	j = 0;
	k = 0;
	l = chrn(list);
	str = malloc(l + 1);
	str[l] = 0;
	while (list)
	{
		while (j < BUFFER_SIZE + 1 && list->content[j] && k < l)
		{
			str[k] = list->content[j];
			j++;
			k++;
		}
		j = 0;
		list = list->next;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	t_list			*list;
	char			*str;
	char			*str_to_free;
	char 			*copy_before_n;
	long long int	i;
	
	i = 0;
	list = 0;
	copy_before_n = 0;
	if (*buffer && ft_strlen(ft_strchr(buffer, '\n')) > 1)
	{
		copy_before_n = malloc (ft_strlen(ft_strchr(buffer, '\n')));
		if (!copy_before_n)
			return (NULL);
		ft_strlcpy(copy_before_n, ft_strchr(buffer, '\n'), ft_strlen(ft_strchr(buffer, '\n')));
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	while (!ft_strchr(buffer, '\n'))
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		if ((i += read(fd, buffer, BUFFER_SIZE)) < BUFFER_SIZE + i)
		{
			ft_lstadd_back(&list, ft_lstnew(ft_strdup(buffer)));
			break ;
		}
		printf("|i = %lld|", i);
		if (list == 0)
			list = ft_lstnew(ft_strdup(buffer));
		else
			ft_lstadd_back(&list, ft_lstnew(ft_strdup(buffer)));
	}
	if (copy_before_n)
	{
		str = ft_strjoin(copy_before_n, (str_to_free = test(i, list)));
		free(copy_before_n);
		free(str_to_free);
	}
	else
		str = test(i, list);
	ft_lstclear(&list);
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
	while (i < 4)
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
//
	return (0);
}

