#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @doubly: head of the linked list
 * @l_num: line number
 * Return: no return
 */
void _push(stack_t **doubly, unsigned int l_num)
{
	int n, j;

	if (!variables_global.arg)
	{
		fprintf(stdout, "L%u: ", l_num);
		fprintf(stderr, "usage: push integer\n");
		free_variables_global();
		exit(EXIT_FAILURE);
	}
	for (j = 0; variables_global.arg[j] != '\0'; j++)
	{
		if (!isdigit(variables_global.arg[j]) && variables_global.arg[j] != '-')
		{
			fprintf(stdout, "L%u: ", l_num);
			fprintf(stdout, "usage: push integer\n");
			free_variables_global();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(variables_global.arg);

	if (variables_global.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * _pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @l_num: line numbers
 * Return: no return
 */
void _pall(stack_t **doubly, unsigned int l_num)
{
	stack_t *aux;
	(void)l_num;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @l_num: line number
 * Return: no return
 */
void _pint(stack_t **doubly, unsigned int l_num)
{
	(void)l_num;

	if (*doubly == NULL)
	{
		fprintf(stdout, "L%u: ", l_num);
		fprintf(stderr, "can't pint, stack empty\n");
		free_variables_global();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @doubly: head of the linked list
 * @l_num: line number
 * Return: no return
 */
void _pop(stack_t **doubly, unsigned int l_num)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		fprintf(stdout, "L%u: can't pop an empty stack\n", l_num);
		free_variables_global();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * _swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @l_num: line number
 * Return: no return
 */
void _swap(stack_t **doubly, unsigned int l_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stdout, "L%u: can't swap, stack too short\n", l_num);
		free_variables_global();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
