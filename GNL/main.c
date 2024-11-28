#include "get_next_line.h"

int	main(int ac, char *av[])
{
	int		fd;
	char	*line;

	if (ac != 2)
	{
		printf("USO: %s", av[0]);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Erro ao abrir o arquivo!");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close (fd);
	return (0);
}