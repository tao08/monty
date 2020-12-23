#include "monty.h"
/**
 * free_stack - frees the stack
 * @stack: double pointer to the beggining of th stack (DLL)
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *aux_stack;

	if (*stack == NULL)
		return;
	while (*stack != NULL)
	{
		aux_stack = (*stack)->next;
		free(*stack);
		if (aux_stack == NULL)
			return;
		aux_stack->prev = NULL;
		*stack = aux_stack;
	}
	free(stack);
}
