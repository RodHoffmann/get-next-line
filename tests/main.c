/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoffma <rohoffma@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:45:16 by rohoffma          #+#    #+#             */
/*   Updated: 2024/06/22 17:41:57 by rohoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	times;
	int	fd;
	char	*line;

	times = 10;
	fd = open("test_file1.txt", O_RDONLY);
	while (times-- > 0)
	{
		line = get_next_line(fd);
		printf("Return value of function on tests: %s\n", line);
	}
	close(fd);
}
