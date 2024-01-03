#include "monty.h"

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *top;

	if (!data.arg || !isINT(data.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", data.line_count);
		/* free stack data */
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		/* free stack data */
		exit(EXIT_FAILURE);
	}

	node->n = atoi(data.arg);
	node->next = NULL;
	node->prev = NULL;
	
	top = getTopOfStack(stack);

	if (!top)
	{
		*stack = node;
	}
	else
	{
		node->prev = top;
		top->next = node;
	}
}

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top = getTopOfStack(stack);

	while (top)
	{
		printf("%d\n", top->n);
		top = top->prev;
	}
}
