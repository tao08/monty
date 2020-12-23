#include "monty.h"
/**
 * check_args - checks if the arguments passed to the funcs are valid
 * (if they are integers according to the tasks)
 * @tk: token passed
 * Return: 1 if valid 0 if not
 */
int check_args(char *tk)
{
	unsigned int reader = 0;

	if (tk == NULL)
		return (1);
	while (tk[reader] != '\0')
	{
		if (tk[reader] == '-')
		{
			if ((!(tk[1] >= '0' && tk[1] <= '9')) || tk[1] == '\0')
				return (0);

			reader = 1;
			while (tk[reader] >= '0' && tk[reader] <= '9')
			{
				reader++;
				if (tk[reader] == '\0')
					return (1);
			}
			return (0);
		}
		else
		{
			reader = 0;
			while (tk[reader] >= '0' && tk[reader] <= '9')
			{
				reader++;
				if (tk[reader] == '\0')
					return (1);
			}
			return (0);
		}
	}
	return (0);
}
