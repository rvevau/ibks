#include <stdio.h>

void DecToBin(unsigned int decimal)
{

	if (decimal >= 2)
	{
		DecToBin(decimal / 2);
	}
	printf("%d", decimal % 2);

}


int main()
{

	unsigned int decimal;

	scanf_s("%d", &decimal);

	DecToBin(decimal);

	return 0;

}
