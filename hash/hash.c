#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h" // compile with ll.c

#define PRIME 3

unsigned hashcode(char str[]) {
	unsigned code = 0;

	for (int i = 0; i < strlen(str); i++) {
		code = (PRIME * code) + (str[i] - '0');
	}
	return code;
}

int main(int argc, char *argv[])
{
	char text[] = "Hello World";
	printf("%s: %u\n", text, hashcode(text));
	char text1[] = "World Hello";
	printf("%s: %u\n", text1, hashcode(text1));
	char text2[] = "Goodbye Space";
	printf("%s: %u\n", text2, hashcode(text2));
	char excerpt[] = "One of the most used data structures across programming languages is a hash table, aka hash map. A hash map is similar to a conventional array, except it uses “keys” as indices rather than meaningless sequential numbering of the values. With the data organized in this way, we get quick search speeds for keys in the structure. If you’ve worked with JavaScript Object Literals ({}), Set, or Map, then you have used structures based on hash tables. But how do they work internally? How can we save key value pairs and later retrieve them?";
	printf("excerpt: %u\n", hashcode(excerpt));
	return EXIT_SUCCESS;
}
