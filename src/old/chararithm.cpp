#include <stdio.h>

main() { 

	const char c1 = 'a';
	auto c2=c1 + 10;     // auto will resolve to int
	printf("%s\n", &c2); // HIDE
	printf("%c\n", c2);  // HIDE
}

