#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

/* Function prototypes */
void print_elf_header_info(const Elf64_Ehdr *header);
void print_error(const char *message, const char *file_name, int exit_code);

/**
 * print_elf_header_info - Prints information contained in the ELF header
 * @header: Pointer to the ELF header
 */
void print_elf_header_info(const Elf64_Ehdr *header)
{
    const char *class_str;
    const char *data_str;
    const char *osabi_str;
    const char *type_str;
    char entry_point[17];

    /* Magic */
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x%c", header->e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

    /* Class */
    switch (header->e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        class_str = "ELF32";
        break;
    case ELFCLASS64:
        class_str = "ELF64";
        break;
    default:
        class_str = "<unknown>";
        break;
    }
    printf("Class:                             %s\n", class_str);

    /* Data */
    switch (header->e_ident[EI_DATA])
    {
    case ELFDATA2LSB:
        data_str = "2's complement, little endian";
        break;
    case ELFDATA2MSB:
        data_str = "2's complement, big endian";
        break;
    default:
        data_str = "<unknown>";
        break;
    }
    printf("Data:                              %s\n", data_str);

    /* Version */
    printf("Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

    /* OS/ABI */
    switch (header->e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        osabi_str = "UNIX - System V";
        break;
    case ELFOSABI_HPUX:
        osabi_str = "HP-UX";
        break;
    case ELFOSABI_NETBSD:
        osabi_str = "NetBSD";
        break;
    case ELFOSABI_LINUX:
        osabi_str = "Linux";
        break;
    default:
        osabi_str = "<unknown>";
        break;
    }
    printf("OS/ABI:                            %s\n", osabi_str);
    printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    /* Type */
    switch (header->e_type)
    {
    case ET_NONE:
        type_str = "NONE (No file type)";
        break;
    case ET_REL:
        type_str = "REL (Relocatable file)";
        break;
    case ET_EXEC:
        type_str = "EXEC (Executable file)";
        break;
    case ET_DYN:
        type_str = "DYN (Shared object file)";
        break;
    case ET_CORE:
        type_str = "CORE (Core file)";
        break;
    default:
        type_str = "<unknown>";
        break;
    }
    printf("Type:                              %s\n", type_str);

    /* Entry point address */
    snprintf(entry_point, sizeof(entry_point), "%016lx", (unsigned long)header->e_entry);
    printf("Entry point address:               0x%s\n", entry_point);
}

/**
 * print_error - Prints an error message to stderr and exits with a given code
 * @message: Error message
 * @file_name: File name to be included in the error message
 * @exit_code: Exit code
 */
void print_error(const char *message, const char *file_name, int exit_code)
{
    dprintf(STDERR_FILENO, "Error: %s %s\n", message, file_name);
    exit(exit_code);
}

/**
 * main - Displays the ELF header information
 * @argc: Number of arguments
 * @argv: Array of arguments
 * 
 * Return: Always 0 on success
 */
int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header;
    ssize_t bytes_read;

    if (argc != 2)
    {
        print_error("Usage: elf_header elf_filename", "", 97);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        print_error("Can't read from file", argv[1], 98);
    }

    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        print_error("Error seeking in file", argv[1], 98);
    }

    bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header))
    {
        print_error("Error reading from file", argv[1], 98);
    }

    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
    {
        print_error("Not an ELF file", argv[1], 98);
    }

    print_elf_header_info(&header);

    if (close(fd) == -1)
    {
        print_error("Can't close fd", argv[1], 100);
    }

    return (0);
}

