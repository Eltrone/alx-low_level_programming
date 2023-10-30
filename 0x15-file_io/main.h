#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/types.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void do_close(int fd);
void display_magic(unsigned char *e_ident);
void validate_elf(unsigned char *e_ident);
int main(int argc, char *argv[]);

#endif /* MAIN_H */

