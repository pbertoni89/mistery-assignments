#include <stdio.h>

main() { 

	char c1 = 'a';
	const char c2=c1+10;
	printf("%s\n", &c2); // HIDE
	printf("%c\n", c2);  // HIDE
}

