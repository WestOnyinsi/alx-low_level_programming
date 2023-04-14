#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *elf_identifier);
void print_thismagic(unsigned char *elf_identifier);
void print_thisclass(unsigned char *elf_identifier);
void print_thisdata(unsigned char *elf_identifier);
void print_thisversion(unsigned char *elf_identifier);
void print_thisabi(unsigned char *elf_identifier);
void print_thisosabi(unsigned char *elf_identifier);
void print_thistype(unsigned int e_type, unsigned char *elf_identifier);
void print_thisentry(unsigned long int e_entry, unsigned char *elf_identifier);
void close_elf(int elf);

/**
 * check_elf - dtyde54w4wssurfu9y0y87huilgh fvf56r856df 6767tg;hioh[9u0=]
 * @elf_identifier: gfy6f6f56f5if5f
 */
void check_elf(unsigned char *elf_identifier)
{
	int indexima;

	for (indexima = 0; indexima < 4; indexima++)
	{
		if (elf_identifier[indexima] != 127 &&
		    elf_identifier[indexima] != 'E' &&
		    elf_identifier[indexima] != 'L' &&
		    elf_identifier[indexima] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_thismagic - bleh bleh bleh
 * @elf_identifier: pointer for bleh bleh bleh
 */
void print_thismagic(unsigned char *elf_identifier)
{
	int indexima;

	printf("  Magic:   ");

	for (indexima = 0; indexima < EI_NIDENT; indexima++)
	{
		printf("%02x", elf_identifier[indexima]);

		if (indexima == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * @elf_identifier: huhuhhu djbeehuhihioehoifeofj jcihciheicheohci edhuiuhuiehic ehuihcheihcieiojojoj
 */
void print_thisclass(unsigned char *elf_identifier)
{
	printf("  Class:                             ");

	switch (elf_identifier[EI_CLASS])
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
		printf("<unknown: %x>\n", elf_identifier[EI_CLASS]);
	}
}

/**
 * print_thisdata - hdgihigirehgihe89ge gegh89eh8geg9y893y78ty73
 * @elf_identifier: fwhvihev87ehrv78gt66 f56d54 sd34 s46 s3 s34   e6r 6t87g guygh g8  6 6 
 */
void print_thisdata(unsigned char *elf_identifier)
{
	printf("  Data:                              ");

	switch (elf_identifier[EI_DATA])
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
		printf("<unknown: %x>\n", elf_identifier[EI_CLASS]);
	}
}

/**
 * print_thisversion - vkjenriierfy8er678e6r8vrhvr
 * @elf_identifier: A pointer to an array containing the ELF version.
 */
void print_thisversion(unsigned char *elf_identifier)
{
	printf("  Version:                           %d",
	       elf_identifier[EI_VERSION]);

	switch (elf_identifier[EI_VERSION])
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
 * print_thisosabi - fefge87fe8f87f uh8v89
 * @elf_identifier: njcjknvuebv vbbeuibviuuevu vebigvuigeugv
 */
void print_thisosabi(unsigned char *elf_identifier)
{
	printf("  OS/ABI:                            ");

	switch (elf_identifier[EI_OSABI])
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
		printf("<unknown: %x>\n", elf_identifier[EI_OSABI]);
	}
}

/**
 * print_thisabi - ehhciehicec cnncncmnvmbbnvzvxvodopjnhuigcbjuec chuegciiejojobopkopykln;knoj rjiojirjiojorjofjorpcokr
 * @elf_identifier: dojeiowyriwtrerbcvnbbvmncskjfk hffgskkgjkfljhgjjkldhfeuyuiyuyeeiyruehecneijddm eifeofhehf
 */
void print_thisabi(unsigned char *elf_identifier)
{
	printf("  ABI Version:                       %d\n",
	       elf_identifier[EI_ABIVERSION]);
}

/**
 * print_thistype - uriihhjchicecn ceiwhfrtjgojotbjmkljjide uwdgyfdrdxcdrsafgvgu guyglut;i'pp]]i uitgugg
 * @e_type: ELF type.
 * @elf_identifier: ieroterhinjnic ieorwiojototjyio jrijigiorjiojrjgojoiklmlumui']p 
 */
void print_thistype(unsigned int e_type, unsigned char *elf_identifier)
{
	if (elf_identifier[EI_DATA] == ELFDATA2MSB)
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
 * print_thisentry - jnjff ejfihihfiojojo fjeiofjjof
 * @e_entry: ihciwhfiuwyijjclsdm rjojgmverjoigjoegj iroiorejlkm 
 * @elf_identifier: kopkyhopkpkyhpr[]r\trt gerjijwywfvdhcvcvvbdhsv hiehihgkgkrnhjjh rehihioehvijrfieiojgi
 */
void print_thisentry(unsigned long int e_entry, unsigned char *elf_identifier)
{
	printf("  Entry point address:               ");

	if (elf_identifier[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (elf_identifier[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf -jherihgeirogerjf ierijvijvoifojvknvkfn vhirfeyueuiuy87976 4y8ty97tihgih497589908678 458t89hghif8994u
 * @elf: 8476895hfgierhiguherg ghudfhve9u90rutengkni 84989tu459gu4g09ufcrjiohyf783
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Cant close fd %d\n", elf);
		exit(98);
	}
}

/**
 * @argc: uhuiuhiuh fy87585 589789rihfihc89hd8
 * @argv: hjhfiy87589f8uic8954ut8h cu8797 99u8 g789f67 f9 6 f6 
 *
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

	check_elf(header->elf_identifier);
	printf("ELF Header:\n");
	print_thismagic(header->elf_identifier);
	print_thisclass(header->elf_identifier);
	print_thisdata(header->elf_identifier);
	print_thisversion(header->elf_identifier);
	print_thisosabi(header->elf_identifier);
	print_thisabi(header->elf_identifier);
	print_thistype(header->e_type, header->elf_identifier);
	print_thisentry(header->e_entry, header->elf_identifier);

	free(header);
	close_elf(o);
	return (0);
}
