#include "get_next_line.h"

char *get_next_line(int fd)
{
	int				fpointer;
	unsigned char	buffer[600];
	int				bread;

	fpointer = open(fd, O_RDONLY);
	if (fpointer == -1)
	{
		printf("\nError to open the file!!\n");
		exit(1);
	}
	else
		printf("\nFile opened with sucess!\n");
	bread = read(fpointer, buffer, sizeof(buffer));
	if (bread == -1)
	{
		printf("\nError to open the file!!\n");
		close(fpointer);
		exit(1);
	}
	buffer[bread] = '\0';
	close(fpointer);
	printf("\n%d bytes read!\n \nFile conten:\n\n%s\n", bread, buffer);
	return (ft_strdup((char *)buffer));
}


int	main(int ac, char *av[])
{
	int		c = 1;
	char	*file;	

	while (c < ac)
	{
		printf("str: %s", av[c]);
		c++;
	}
	file = get_next_line("/root/GNL/archive.txt");
	printf("\n%s\n", file);
	free(file);
	return (0);
}
