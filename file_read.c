#include "monty.h"
/**
 * read_file - reads the file passed to the monty interpreter
 * @file_name: pointer to the file passed to the monty interpreter
 * Return: void
 */
void read_file(char *file_name)
{
	stack_t *stack = NULL;
	int line_number = 0;
	char **tokens, *buffer = NULL;
	size_t size = 0;

	FILE *file_data;
	void (*s)(stack_t **stack, unsigned int line_number);


	file_data = fopen(file_name, "r");
	if (file_data == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);

	}
	while (-1 != getline(&buffer, &size, file_data))
	{
		line_number++;
		tokens = tokenize(buffer);
		if (tokens == NULL)
			continue;
		else
			s = op_functions(tokens, line_number);
		if (s != NULL)
		{
			s(&stack, line_number);
		}
		else
		{
			handler_errors(line_number, 2);
			fclose(file_data);
			free(buffer);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file_data);
	free(buffer);
	free_stack(&stack);
}

/**
 * sub_func - substracts the top element of the stack from the second top elem
 * add_func - adds to the top two elements of the stack
 * @stack: double pointer to a double linked list as stack
 * @line_number: number of lines inside the opcode file
 * Return: void
 */
void sub_func(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		handler_errors(line_number, 6);
	}
	aux_stack = *stack;
	if (aux_stack->next == NULL)
		handler_errors(line_number, 6);
	aux_stack->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free(aux_stack);
	(*stack)->prev = NULL;
}
