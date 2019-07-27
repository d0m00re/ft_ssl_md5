#include <stdio.h>

int main()
{
	int count = 0;
	int tab[] = {5, 10, 15, 20};
	printf("test while :\n");

	while (count < 4)
	{
		printf("%d\n", tab[count++]);
	}
	count = 0;
	printf("\n\n");
	while (++count < 8)
        {
                printf("%d\n", count);
        }
}
