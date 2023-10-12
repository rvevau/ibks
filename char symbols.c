#include <stdio.h>

int main()
{

	char i = -128;

	printf("%c ", i);

	do {

		i++;
		printf("%c ", i);
		
	} while (i < 127);

	return 0;
}
