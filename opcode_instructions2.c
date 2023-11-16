#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 *
 * @doubly: head of the linked list
 * @l_num: line number;
 * Return: no return
 */
void _queue(stack_t **doubly, unsigned int l_num)
{
	(void)doubly;
	(void)l_num;

	variables_global.lifo = 0;
}

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 *
 * @doubly: head of the linked list
 * @l_num: line number;
 * Return: no return
 */
void _stack(stack_t **doubly, unsigned int l_num)
{
	(void)doubly;
	(void)l_num;

	variables_global.lifo = 1;
}

/**
 * _add - adds the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @l_num: line number;
 * Return: no return
 */
void _add(stack_t **doubly, unsigned int l_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", l_num);
		free_variables_global();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, l_num);
}

/**
 * _nop - doesn't do anythinhg
 *
 * @doubly: head of the linked list
 * @l_num: line number;
 * Return: no return
 */
void _nop(stack_t **doubly, unsigned int l_num)
{
	(void)doubly;
	(void)l_num;
}

/**
 * _sub - subtracts the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @l_num: line number;
 * Return: no return
 */
void _sub(stack_t **doubly, unsigned int l_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", l_num);
		free_variables_global();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, l_num);
}
