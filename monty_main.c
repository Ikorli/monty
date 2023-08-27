#include "monty.h"
#define _GNU_SOURCE
global_t vglo = {0};

/**
 * main - Entry point
 *
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
void (*f)(stack_t **stack, unsigned int line_number);
FILE *fd;
size_t size = 256;
ssize_t nlines = 0;
char *line = NULL;

fd = check_input(argc, argv);
start_vglo(fd);
    
while ((nlines = getline(&line, &size, fd)) != -1)
{
vglo.buffer = line;
f = get_opcodes(vglo.buffer);

if (f)
{
vglo.arg = _strtoky(NULL, " \t\n");
f(&vglo.head, vglo.cont);
}

vglo.cont++;
}

free(line);
free_vglo();

    return (0);
}

/**
 * free_vglo - Frees the global variables
 *
 * Return: No return
 */
void free_vglo(void)
{
free_dlistint(vglo.head);
free(vglo.buffer);
fclose(vglo.fd);
}

/**
 * start_vglo - Initializes the global variables
 *
 * @fd: File descriptor
 * Return: No return
 */
void start_vglo(FILE *fd)
{
vglo.lifo = 1;
vglo.cont = 1;
vglo.arg = NULL;
vglo.head = NULL;
vglo.fd = fd;
vglo.buffer = NULL;
}

/**
 * check_input - Checks if the file exists and can be opened
 *
 * @argc: Argument count
 * @argv: Argument vector
 * Return: File struct
 */
FILE *check_input(int argc, char *argv[])
{
    FILE *fd;

    if (argc == 1 || argc > 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fd = fopen(argv[1], "r");

    if (fd == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return (fd);
}
