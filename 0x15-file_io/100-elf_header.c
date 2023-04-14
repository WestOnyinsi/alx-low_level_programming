#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_identifier);
void print_thizzzzmagic(unsigned char *e_identifier);
void print_thizzzzclass(unsigned char *e_identifier);
void print_thizzzzdata(unsigned char *e_identifier);
void print_thizzzzversion(unsigned char *e_identifier);
void print_thizzzzabi(unsigned char *e_identifier);
void print_thizzzzosabi(unsigned char *e_identifier);
void print_thizzzztype(unsigned int e_type, unsigned char *e_identifier);
void print_thizzzzentry(unsigned long int e_entry, unsigned char *e_identifier);
void close_elf(int elf);

/**
 * @e_identifier: A poi
 */
void check_elf(unsigned char *e_identifier)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_identifier[index] != 127 &&
		    e_identifier[index] != 'E' &&
		    e_identifier[index] != 'L' &&
		    e_identifier[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * @e_identifier: A po
 *
 */
void print_thizzzzmagic(unsigned char *e_identifier)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_identifier[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * @e_identifier: A 
 */
void print_thizzzzclass(unsigned char *e_identifier)
{
	printf("  Class:                             ");

	switch (e_identifier[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_identifier[EI_CLASS]);
	}
}

/**
 * @e_identifier: A pointer 
 */
void print_thizzzzdata(unsigned char *e_identifier)
{
	printf("  Data:                              ");

	switch (e_identifier[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_identifier[EI_CLASS]);
	}
}

/**
 * @e_identifier: A 
 */
void print_thizzzzversion(unsigned char *e_identifier)
{
	printf("  Version:                           %d",
	       e_identifier[EI_VERSION]);

	switch (e_identifier[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * @e_identifier: 
 */
void print_thizzzzosabi(unsigned char *e_identifier)
{
	printf("  OS/ABI:                            ");

	switch (e_identifier[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_identifier[EI_OSABI]);
	}
}

/**
 * @e_identifier: A poi
 */
void print_thizzzzabi(unsigned char *e_identifier)
{
	printf("  ABI Version:                       %d\n",
	       e_identifier[EI_ABIVERSION]);
}

/**
 * @e_type: ELF type.
 * @e_identifier:  pointer to an array containing the ELF class.
 */
void print_thizzzztype(unsigned int e_type, unsigned char *e_identifier)
{
	if (e_identifier[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * @e_entry: address 
 * @e_identifier: A po
 */
void print_thizzzzentry(unsigned long int e_entry, unsigned char *e_identifier)
{
	printf("  Entry point address:               ");

	if (e_identifier[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_identifier[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * @elf: T
 *
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
  * @argc: ogram.
 * @argv: An array 
  */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_identifier);
	printf("ELF Header:\n");
	print_thizzzzmagic(header->e_identifier);
	print_thizzzzclass(header->e_identifier);
	print_thizzzzdata(header->e_identifier);
	print_thizzzzversion(header->e_identifier);
	print_thizzzzosabi(header->e_identifier);
	print_thizzzzabi(header->e_identifier);
	print_thizzzztype(header->e_type, header->e_identifier);
	print_thizzzzentry(header->e_entry, header->e_identifier);

	free(header);
	close_elf(o);
	return (0);
}
