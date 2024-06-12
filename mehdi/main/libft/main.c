#include <fcntl.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (fprintf(stderr, "erreur file"), 1);
	char *str = line_no_nl(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = line_no_nl(fd);
	}
	free(str);
	return (0);
}
