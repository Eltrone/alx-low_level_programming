#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void display_magic(unsigned char *e_ident);
void validate_elf(unsigned char *e_ident);

/**
 * main - Entry point, displays the ELF header info
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	unsigned char e_ident[16];
	ssize_t bytes_read;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	bytes_read = read(fd, e_ident, 16);
	if (bytes_read != 16)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		close(fd);
		exit(98);
	}

	validate_elf(e_ident);

	printf("ELF Header:\n");
	display_magic(e_ident);

	/* TODO: Add more header information */

	close(fd);
	return (0);
}

/**
 * display_magic - Display the magic part of ELF header
 * @e_ident: The ELF header identifier bytes
 */
void display_magic(unsigned char *e_ident)
{
	printf("  Magic:   ");
	for (int i = 0; i < 16; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

/**
 * validate_elf - Validate the ELF file
 * @e_ident: The ELF header identifier bytes
 */
void validate_elf(unsigned char *e_ident)
{
	if (e_ident[0] != 0x7f || e_ident[1] != 'E' ||
	    e_ident[2] != 'L' || e_ident[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

