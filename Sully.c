#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

int main() {
	int x = 5;
	x--;
	char * buffer = 0;
	long length;
	FILE * f = fopen (__FILE__, "r");
	char * fileName = strcat("Sully_", itoa(x));
	FILE * childF = fopen (fileName, "w");

	if (f)
	{
		fseek (f, 0, SEEK_END);
		length = ftell (f);
		fseek (f, 0, SEEK_SET);
		buffer = malloc (length);
		if (buffer) {
			if (strcmp(buffer,"int x = 5") == 0)
				buffer = "int x = 4";
			else if (strcmp(buffer,"int x = 4") == 0)
				buffer = "int x = 3";
			else if (strcmp(buffer,"int x = 3") == 0)
				buffer = "int x = 2";
			else if (strcmp(buffer, "int x = 2") == 0)
				buffer = "int x = 1";
			else if (strcmp(buffer, "int x = 1") == 0)
				buffer = "int x = 0";
			else if (strcmp(buffer, "int x = 0") == 0)
				exit(0);
			fread (buffer, 1, length, f);
			fputs(buffer, childF);
		}
		fclose (childF);
		fclose (f);
	}
}
