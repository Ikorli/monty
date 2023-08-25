#include "monty.h"

global_t vglo = {NULL, 0};
/**
 * add_dnodeint_end - Adds a node at the end of a doubly linked list
 *
 * @head: Pointer to the first position of the linked list
 * @n: Data to store in the new node
 * Return: Pointer to the newly added node
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
stack_t *temp, *aux;

if (head == NULL)
return (NULL);

temp = malloc(sizeof(stack_t));
if (temp == NULL)
{
dprintf(2, "Error: malloc failed\n");
free_vglo();
exit(EXIT_FAILURE);
}

temp->n = n;
temp->next = NULL;

if (*head == NULL)
{
temp->prev = NULL;
*head = temp;
return (*head);
}

aux = *head;
while (aux->next != NULL)
aux = aux->next;

aux->next = temp;
temp->prev = aux;

return (temp);
}

/**
 * add_dnodeint - Adds a node at the beginning of a doubly linked list
 *
 * @head: Pointer to the first position of the linked list
 * @n: Data to store in the new node
 * Return: Pointer to the newly added node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
stack_t *temp;

if (head == NULL)
return (NULL);

temp = malloc(sizeof(stack_t));
if (temp == NULL)
{
dprintf(2, "Error: malloc failed\n");
free_vglo();
exit(EXIT_FAILURE);
}

temp->n = n;
temp->prev = NULL;

if (*head == NULL)
{
temp->next = NULL;
*head = temp;
return (*head);
}

temp->next = *head;
(*head)->prev = temp;
*head = temp;

return (temp);
}

/**
 * free_dlistint - Frees a doubly linked list
 *
 * @head: Pointer to the head of the list
 * Return: No return value
 */
void free_dlistint(stack_t *head)
{
stack_t *tmp;

while (head != NULL)
{
tmp = head;
head = head->next;
free(tmp);
}
}
