#include "main.h"
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @ac: The number of arguments.
 * @av: An array of pointers to the arguments.
 *
 * Return: 0 on success, or an exit code on failure.
 */
int main(int ac, char **av)
{
	int fd_f, fd_t, c_f = 0, c_t = 0;
	ssize_t r, w;
	char buf[BUF_SIZE];

	if (ac != 3)
	return (dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", av[0]), 97);

	fd_f = open(av[1], O_RDONLY);
	if (fd_f == -1)
	return (dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]),
			98);

	fd_t = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_t == -1)
	return (dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), 99);

	while ((r = read(fd_f, buf, BUF_SIZE)) > 0)
	{
		w = write(fd_t, buf, r);
		if (w != r)
			return (dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), 99);
	}

	if (r == -1)
		return (dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]),
				98);

	c_f = close(fd_f), c_t = close(fd_t);

	if (c_f == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_f);

	if (c_t == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_t);

	return ((c_f == -1 || c_t == -1) ? 100 : 0);
}
