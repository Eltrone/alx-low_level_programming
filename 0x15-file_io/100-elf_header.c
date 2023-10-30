#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <stdint.h>

/**
 * get_e_type - returns the string description of e_type
 * @e_type: the e_type value
 * Return: string description
 */
const char *get_e_type(uint16_t e_type)
{
	switch (e_type)
	{
	case ET_NONE: return "NONE (No file type)";
	case ET_REL: return "REL (Relocatable file)";
	case ET_EXEC: return "EXEC (Executable file)";
	case ET_DYN: return "DYN (Shared object file)";
	case ET_CORE: return "CORE (Core file)";
	default: return "<unknown>";
	}
}

/**
 * get_ei_osabi - returns the string description of EI_OSABI
 * @ei_osabi: the EI_OSABI value
 * Return: string description
 */
const char *get_ei_osabi(unsigned char ei_osabi)
{
	switch (ei_osabi)
	{
	case ELFOSABI_SYSV: return "UNIX - System V";
	case ELFOSABI_HPUX: return "UNIX - HP-UX";
	case ELFOSABI_NETBSD: return "UNIX - NetBSD";
	case ELFOSABI_LINUX: return "UNIX - Linux";
	case ELFOSABI_SOLARIS: return "UNIX - Solaris";
	default: return "<unknown>";
	}
}

/**
 * print_magic - prints the magic numbers
 * @header: the ELF header
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

/**
 * print_header_64 - prints the ELF header for 64-bit files
 * @header: the ELF header
 */
void print_header_64(Elf64_Ehdr header)
{
	printf("ELF Header:\n");
	print_magic(header.e_ident);
	printf("  Class:                             ELF64\n");
	printf("  Data:                              2's complement, little endian\n");
	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", get_ei_osabi(header.e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", get_e_type(header.e_type));
	printf("  Entry point address:               0x%lx\n", header.e_entry);
}

/**
 * print_header_32 - prints the ELF header for 32-bit files
 * @header: the ELF header
 */
void print_header_32(Elf32_Ehdr header)
{
	printf("ELF Header:\n");
	print_magic(header.e_ident);
	printf("  Class:                             ELF32\n");
	printf("  Data:                              2's complement, little endian\n");
	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", get_ei_osabi(header.e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", get_e_type(header.e_type));
	printf("  Entry point address:               0x%x\n", header.e_entry);
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
	unsigned char e_ident[EI_NIDENT];

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

	if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
	{
		perror("Error");
		close(fd);
		exit(98);
	}

	if (e_ident[EI_MAG0] != ELFMAG0 ||
	    e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 ||
	    e_ident[EI_MAG3] != ELFMAG3)
	{
		write(2, "Not an ELF file\n", 16);
		close(fd);
		exit(98);
	}

	if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		Elf64_Ehdr header_64;
		lseek(fd, 0, SEEK_SET);
		if (read(fd, &header_64, sizeof(header_64)) != sizeof(header_64))
		{
			perror("Error");
			close(fd);
			exit(98);
		}
		print_header_64(header_64);
	}
	else if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr header_32;
		lseek(fd, 0, SEEK_SET);
		if (read(fd, &header_32, sizeof(header_32)) != sizeof(header_32))
		{
			perror("Error");
			close(fd);
			exit(98);
		}
		print_header_32(header_32);
	}
	else
	{
		write(2, "Unsupported ELF file class\n", 26);
		close(fd);
		exit(98);
	}

	close(fd);
	return (0);
}

