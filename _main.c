#include "main.h"
#include <stdio.h>
#include <stdlib.h>

CustomData custom_data = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter entry point.
 * @argc: Argument count.
 * @argv: Argument values.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack_head = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    custom_data.file = file;
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (read_line > 0)
    {
        content = NULL;
        read_line = getline(&content, &size, file);
        custom_data.content = content;
        line_number++;
        if (read_line > 0)
        {
            execute_instruction(content, &stack_head, line_number, file);
        }
        free(content);
    }
    free_stack(stack_head);
    fclose(file);
    return (0);
}
