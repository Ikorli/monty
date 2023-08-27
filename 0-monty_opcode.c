#include "monty.h"
#include <stdio.h>

global_t vglo = {0};
/**
 * push - pushes an element to the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_number)
{
int n, j;

if (!vglo.arg)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
free_vglo();
exit(EXIT_FAILURE);
}

for (j = 0; vglo.arg[j] != '\0'; j++)
{
if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
free_vglo();
exit(EXIT_FAILURE);
}
}

n = atoi(vglo.arg);

if (vglo.lifo == 1)
add_dnodeint(stack, n);
else
add_dnodeint_end(stack, n);
}

/**
 * pall - prints all values on the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *aux;
(void)line_number;

aux = *stack;

while (aux)
{
printf("%d\n", aux->n);
aux = aux->next;
}
}

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * Return: no return
 */
void pint(stack_t **stack, unsigned int line_number)
{
(void)line_number;

if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
free_vglo();
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * Return: no return
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *aux;

if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
free_vglo();
exit(EXIT_FAILURE);
}
aux = *stack;
*stack = (*stack)->next;
free(aux);
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * Return: no return
 */
void swap(stack_t **stack, unsigned int line_number)
{
int m = 0;
stack_t *aux = NULL;

aux = *stack;
for (; aux != NULL; aux = aux->next, m++);
if (m < 2)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
free_vglo();
exit(EXIT_FAILURE);
}

aux = *stack;
*stack = (*stack)->next;
aux->next = (*stack)->next;
aux->prev = *stack;
(*stack)->next = aux;
(*stack)->prev = NULL;
}
