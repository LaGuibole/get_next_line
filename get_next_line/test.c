/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:03:23 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/17 15:24:34 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd_count = 1;
	int		fd[fd_count];
	char	*strs[fd_count];

	for (int i = 0; i < fd_count; i++)
	{
		fd[i] = open("lines_around_10.txt", O_RDONLY);
		strs[i] = get_next_line(fd[i]);
	}
	while (strs[0])
	{
		for (int i = 0; i < fd_count; i++)
		{
			printf("%s", strs[i]);
			free(strs[i]);
			strs[i] = get_next_line(fd[i]);
		}
	}
	for (int i = 0; i < fd_count; i++)
	{
		free(strs[i]);
		close(fd[i]);
	}
	return (0);
}

// int main()
// {
// 	int fd = open("lines_around_10.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// }


