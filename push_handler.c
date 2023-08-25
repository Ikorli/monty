#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push_to_stack - Adds a node to the stack.
 * @stack_head: Double pointer to the stack.
 * @line_number: Line number.
 *
 * Return: Nothing.
 */
void push_to_stack(stack_t **stack_head, unsigned int line_number)
{
	int value, is_negative = 0, is_invalid = 0;

	if (CustomData.argument)
	{
		if (CustomData.argument[0] == '-')
			is_negative++;

		for (; CustomData.argument[is_negative] != '\0'; is_negative++)
		{
			if (CustomData.argument[is_negative] > '9' || CustomData.argument[is_negative] < '0')
				is_invalid = 1;
		}

		if (is_invalid)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(CustomData.file);
			free(CustomData.content);
			free_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(CustomData.file);
		free(CustomData.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	value = atoi(CustomData.argument);

	if (CustomData.lifo == 0)
		push_to_stack(stack_head, value);
	else
		addqueue(stack_head, value);
}
