#include "monty.h"

monty_data data = {NULL, 0, NULL, NULL, NULL};

int main(int argc, char **argv) 
{
	FILE *file;
	char buf[1024];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);			
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buf, 1024, file))
	{
		data.line_count++;
		data.line = buf;
		execute();
	}

	fclose(file);
	/* free up the stack */
}
