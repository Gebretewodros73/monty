#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include<ctype.h>


/* Data structures */

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
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

void push_file(stack_t **stack, unsigned int line_number);
void pall_file(stack_t **stack, unsigned int line_number);
void add_node(stack_t **head, int n);
void add_queue(stack_t **head, int n);
void free_stack(stack_t *head);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void add_file(stack_t **head, unsigned int counter);
void queue_file(stack_t **head, unsigned int counter);
void pint_file(stack_t **head, unsigned int counter);
void stack_file(stack_t **head, unsigned int counter);
void pop_file(stack_t **head, unsigned int counter);
void nop_file(stack_t **head, unsigned int counter);
void mul_file(stack_t **head, unsigned int counter);
void sub_file(stack_t **head, unsigned int counter);
void div_file(stack_t **head, unsigned int counter);


#endif /* MONTY_H */
