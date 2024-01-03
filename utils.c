#include "monty.h"

int isINT(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 57 || s[i] < 47)
		{
			return (0);
		}
	}
	return (1);
}

stack_t *getTopOfStack(stack_t **stack)
{
	stack_t *current;

	if (!stack || !*stack)
	{
		return (NULL);
	}

	current = *stack;

	while (current->next)
	{
		current = current->next;
	}
	return (current);
}
