#include "main.h"

/**
 * free_stack - Frees a doubly linked list.
 * @stack_head: Head pointer to the stack.
 *
 * Return: Nothing.
 */
void free_stack(stack_t *stack_head)
{
	stack_t *temp;

	temp = stack_head;
	while (stack_head)
	{
		temp = stack_head->next;
		free(stack_head);
		stack_head = temp;
	}
}

/**
 * set_stack_mode - Sets the stack mode.
 * @stack_head: Head of the stack.
 * @line_number: Line number.
 *
 * Return: Nothing.
 */
void set_stack_mode(stack_t **stack_head, unsigned int line_number)
{
	(void)*stack_head;
	(void)line_number;
	CustomData.lifo = 0;
}
