#include <stdio.h>
#include <stdlib.h>
#define begin(m,a,i,n) m##a##i##n
#define start begin(m,a,i,n)
#define anotherDefine asDefine
// this is a comment

int start() {
	char * buffer = 0;
	long length;
	FILE * f = fopen (__FILE__, "r");
	FILE * graceKidf = fopen ("Grace_kid.c", "w");

	if (f)
	{
		fseek (f, 0, SEEK_END);
		length = ftell (f);
		fseek (f, 0, SEEK_SET);
		buffer = malloc (length);
		if (buffer) {
			fread (buffer, 1, length, f);
			fputs(buffer, graceKidf);
		}
		fclose (graceKidf);
		fclose (f);
	}
}
