#include "monty.h"
/**
 * main - entry point of Monty interpreter
 * @argc: number of arguments passed to the interpreter
 * @argv: arguments passed to the interpreter
 * Return: 0 if success otherwise exit failure
 */
int main(int argc, char *argv[])
{
	char *file_name;

	file_name = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(file_name);
	exit(EXIT_SUCCESS);
}
