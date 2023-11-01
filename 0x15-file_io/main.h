#ifndef MAIN_H
#define MAIN_H

/* Include necessary header files */
#include <elf.h>
#include <stdint.h>

#include <unistd.h>
#include <sys/types.h>

/* Function prototypes */
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void do_close(int fd);
void display_magic(unsigned char *e_ident);
void validate_elf(unsigned char *e_ident);
int main(int argc, char *argv[]);
void print_magic(Elf64_Ehdr header);
void print_header(Elf64_Ehdr header);
const char *get_e_type(uint16_t e_type);
const char *get_ei_osabi(unsigned char ei_osabi);
void print_header_32(Elf32_Ehdr header);

#endif /* MAIN_H */

