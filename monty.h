#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* declaring the global variables for the project */
/**
 * struct vars - the global variables for the project
 * @args: an array to store the arguments
 * @linenum: 
 * @file: the 
 * 
 * Description: This is a structure of the global variables
 */
typedef struct vars
{
	char *args;

} var_t;

extern var_t var_s;

#include <stdio.h>
#include <stdlib.h>

FILE *read_file(int argc, char *argv[]);
void push_int(stack_t **head, unsigned int linenum);
stack_t *add_node(stack_t **head, int n);

#endif /* MONTY_H */
