#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, i;
	printf("Enter 2 numbers: ");
	scanf("%d%d", &a, &b);
	do
	{
		printf("1.Add\n2.Subtract.\n3.Multiply.\n4.Divide\nEnter your choice: ");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("The sum is: %d\n", (a + b));
			exit(0);
		case 2:
			printf("The difference is: %d\n", (a - b));
			exit(0);
		case 3:
			printf("The product is: %d\n", (a * b));
			exit(0);
		case 4:
			printf("The quotient is: %d\n", (a / b));
			exit(0);
		}
	} while (i < 1 || i > 4);
	return 0;
}
