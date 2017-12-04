#include <stdio.h>
#include <stdlib.h>

/*
  this is a comment
*/

void	printBuffer(char *buffer) {
	printf("%s", buffer);
}

int main() {
	char * buffer = 0;
	long length;
	FILE * f = fopen (__FILE__, "r");

	if (f)
	{
		fseek (f, 0, SEEK_END);
		length = ftell (f);
		fseek (f, 0, SEEK_SET);
		buffer = malloc (length);
		if (buffer)
			fread (buffer, 1, length, f);
		printBuffer(buffer);
		/*
		 this is also a comment
		*/
		fclose (f);
	}
}
