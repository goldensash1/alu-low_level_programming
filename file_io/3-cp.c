#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_error_and_exit - Prints an error message and exits.
 * @exit_code: Exit code to use.
 * @msg: Error message format string.
 * @arg: Argument for format string.
 */
void print_error_and_exit(int exit_code, const char *msg, char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(exit_code);
}

/**
 * close_fd - Closes a file descriptor or exits with error.
 * @fd: File descriptor to close.
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the content of one file to another.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	if (ac != 3)
		print_error_and_exit(97, "Usage: cp file_from file_to\n", NULL);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		print_error_and_exit(98, "Error: Can't read from file %s\n", av[1]);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		print_error_and_exit(99, "Error: Can't write to %s\n", av[2]);
	}

	bytes_read = read(fd_from, buffer, 1024);
	while (bytes_read > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			print_error_and_exit(99, "Error: Can't write to %s\n", av[2]);
		}

		bytes_read = read(fd_from, buffer, 1024);
	}

	if (bytes_read == -1)
	{
		close_fd(fd_from);
		close_fd(fd_to);
		print_error_and_exit(98, "Error: Can't read from file %s\n", av[1]);
	}

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
