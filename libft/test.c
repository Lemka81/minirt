#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd = open("../test_maps/42.fdf", O_RDONLY);
	for (int i = 0; i < 15; i++)
	{
		char *arr = get_next_line(fd);
		free(arr);
	}
}
