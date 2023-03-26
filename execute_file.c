#include "monty.h"
/**
 * queue_file - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void queue_file(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}
/*add */

#include "monty.h"
/**
 * add_file - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void add_file(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
/*pint*/
#include "monty.h"
/**
 * pint_file - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pint_file(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/*stack*/
#include "monty.h"
/**
 * stack_file - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void stack_file(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}