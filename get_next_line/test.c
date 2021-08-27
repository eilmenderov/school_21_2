#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd = open ("file", O_RDONLY);
	char *line;
	int i = 1;
	while (i && i != -1)
	{
		i = get_next_line(fd, &line);
		printf("i = %d %s\n", i, line);
		free (line);
	}
	return (0);
}
