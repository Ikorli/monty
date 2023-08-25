#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

void push(int *stack, int *top, int value)
{
	if (*top == STACK_SIZE - 1)
	{
		printf("Stack overflow\n");
		exit(1);
	}

	stack[++(*top)] = value;
}

void pall(int *stack, int top)
{
	if (top == -1)
		return;

	for (int j = top; j >= 0; j--)
	{
		printf("%d\n", stack[j]);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: monty <file>\n");
		exit(1);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(1);
	}

	int stack[STACK_SIZE];
	int top = -1;

	char line[100];

	while (fgets(line, sizeof(line), file))
	{
		char opcode[10];
		int value;

		int i = 0;

		while (line[i] != ' ' && line[i] != '\n')
		{
			opcode[i] = line[i];
			i++;
		}
		opcode[i] = '\0';

		if (i == 0)
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			value = atoi(line + i + 1);
			push(stack, &top, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack, top);
		}
		else
		{
			printf("L%d: unknown instruction %s\n", i + 1, opcode);
			exit(1);
		}
	}

	fclose(file);
	return (0);
}
