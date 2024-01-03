#include "monty.h"

void execute(void)
{
	int i;

	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{NULL, NULL}
	};

	data.opcode = strtok(data.line, " \n\t");
	data.arg = strtok(NULL, " \n\t");

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(data.opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(&data.stack, data.line_count);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s", data.line_count, data.opcode);
}
