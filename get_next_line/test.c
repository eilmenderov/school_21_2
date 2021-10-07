#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd = open ("file", O_RDONLY);
	char *line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		printf("|%s|\n", line);
		if (!line)
			break ;
		if (line)
			free (line);
		line = NULL;
	}
	return (0);
}


// gcc -Wall -Wextra -Werror test.c get_next_line.c get_next_line_utils.c && ./a.out | cat -e && rm a.out