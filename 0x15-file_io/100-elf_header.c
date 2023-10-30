#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_magic - prints the magic numbers
 * @header: the ELF header
 */
void print_magic(Elf64_Ehdr header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header.e_ident[i]);
	printf("\n");
}

/**
 * print_header - prints the ELF header
 * @header: the ELF header
 */
void print_header(Elf64_Ehdr header)
{
	printf("ELF Header:\n");
	print_magic(header);
	printf("  Class:                             ");
	printf(header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32\n" : "ELF64\n");
	printf("  Data:                              ");
	printf(header.e_ident[EI_DATA] == ELFDATA2LSB ?
	       "2's complement, little endian\n" : "2's complement, big endian\n");
	printf("  Version:                           ");
	printf("%d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	printf(header.e_ident[EI_OSABI] == ELFOSABI_SYSV ?
	       "UNIX - System V\n" : "<unknown>\n");
	printf("  ABI Version:                       %d\n",
	       header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	printf(header.e_type == ET_EXEC ?
	       "EXEC (Executable file)\n" : "<unknown>\n");
	printf("  Entry point address:               0x%lx\n",
	       header.e_entry);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		write(2, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		perror("Error");
		close(fd);
		exit(98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 ||
	    header.e_ident[EI_MAG3] != ELFMAG3)
	{
		write(2, "Not an ELF file\n", 16);
		close(fd);
		exit(98);
	}

	print_header(header);

	close(fd);
	return (0);
}

