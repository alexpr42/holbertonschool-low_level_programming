#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or an exit code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, r, w, c_f, c_t;
	char buf[BUF_SIZE];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]),
			exit(97);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
			exit(98);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]),
			exit(99);

	while ((r = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (r == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
			exit(98);

	c_f = close(fd_from);
	c_t = close(fd_to);

	return ((r == -1 || w != r || (c_f == -1 && (dprintf(STDERR_FILENO,
		"Error: Can't close fd %d\n", fd_from), 0)) || (c_t == -1 &&
		(dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), 0))) |
		(c_f | c_t));
}
