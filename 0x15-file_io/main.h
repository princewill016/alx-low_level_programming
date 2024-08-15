#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <sys/types.h>

/* Function prototypes */
void print_elf_header_info(const Elf64_Ehdr *header);
void print_error(const char *message, const char *file_name, int exit_code);

#endif /* MAIN_H */

