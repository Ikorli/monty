#ifndef MONTY_H
#define MONTY_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif /* !_GNU_SOURCE */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

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

/**
* struct bus_s - Global variables -args, lifo
* @arg: value
* @file: pointer to monty file
* @content: line content'
* @lifi: flag change stack <-> queue
*
* Description: carries values through the program
*/
typedef struct global_s
{
	char *arg;
	int lifo;
	int cont;
	stack_t *head;
	FILE *fd;
	char *buffer;
}  global_t;

extern global_t vglo;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* doubly linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* imported functions */
char *_strtoky(char *str, const char *delim);

/* get functions */
void (*get_opcodes(const char *opcode))(stack_t **stack, unsigned int line_number);

/* main function */
int main(int argc, char *argv[]);
void free_vglo(void);
void start_vglo(FILE *fd);
FILE *check_input(int argc, char *argv[]);



#endif
