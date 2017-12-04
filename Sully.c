#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int x = 5;
	x--;
	char * buffer = 0;
	long length;
	FILE * f = fopen (__FILE__, "r");
	
	char *xAsA;
	xAsA = (char*)malloc(sizeof(x)/4 + 1);
	sprintf(xAsA, "%d", x);
	
	printf("begin\n");
	char src[8];
	char src2[10];
	strcpy(src, "Sully_");
	char * fileName = strcat(src, xAsA);
	strcpy(src2, fileName);
	char * withExt = strcat(src2, ".c");
	FILE * childF = fopen (withExt, "w");

	if (f)
	{
		fseek (f, 0, SEEK_END);
		length = ftell (f);
		fseek (f, 0, SEEK_SET);
		buffer = malloc (length);
		if (buffer) {
			fread (buffer, 1, length, f);
			fputs(buffer, childF);
			printf("printing:\n%s", buffer);
		}
		fclose (childF);
		fclose (f);
	}
	char systemCall[100];
	sprintf(systemCall, "clang -o %s %s && ./%s", fileName, withExt, fileName);
	system(systemCall);
}
