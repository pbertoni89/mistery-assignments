#include <stdlib.h>


typedef struct n {
	int i;
	struct n *a, *b;
} n;


int main()
{
	struct n nn;
	nn.a = (n*) calloc(1, sizeof(n));
	nn.a->i = 29;
	free(nn.a);
}
