#include "monty.h"

/**
 * _div - divides the second element by the top element of the stack
 * @doubly: head of the linked list
 * @l_num: line number;
 * Return: no return
 */
void _div(stack_t **doubly, unsigned int l_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stdout, "L%u: can't div, stack too short\n", l_num);
		free_variables_global();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		fprintf(stdout, "L%u: division by zero\n", l_num);
		free_variables_global();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	_pop(doubly, l_num);
}

/**
 * _mul - multiplies the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @l_num: line number;
 * Return: no return
 */
void _mul(stack_t **doubly, unsigned int l_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stdout, "L%u: can't mul, stack too short\n", l_num);
		free_variables_global();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n *= (*doubly)->n;
	_pop(doubly, l_num);
}

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @doubly: head of the linked list
 * @l_num: line number;
 * Return: no return
 */
void _mod(stack_t **doubly, unsigned int l_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stdout, "L%u: can't mod, stack too short\n", l_num);
		free_variables_global();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		fprintf(stdout, "L%u: division by zero\n", l_num);
		free_variables_global();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	_pop(doubly, l_num);
}
/**
 * _pchar - print the char value of the first element
 *
 * @doubly: head of the linked list
 * @l_num: line number;
 * Return: no return
 */
void _pchar(stack_t **doubly, unsigned int l_num)
{
	if (doubly == NULL || *doubly == NULL)
	{
		fprintf(stdout, "L%u: can't pchar, stack empty\n", l_num);
		free_variables_global();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		fprintf(stdout, "L%u: can't pchar, value out of range\n", l_num);
		free_variables_global();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

/**
 * _pstr - prints the string of the stack
 *
 * @doubly: head of the linked list
 * @l_num: line number;
 * Return: no return
 */
void _pstr(stack_t **doubly, unsigned int l_num)
{
	stack_t *aux;
	(void)l_num;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
