#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key)
{
	int i = 0;
	for(int i = 0; i<n; i++)
	{
		printf("   | ");
		for (int j = 0; j < i; j++)
		{
			printf("  ");
		}
		printf("*\n");
		printf("  %d| ", i);
		for (int k = 0; k < n; k++)
		{
			printf("%d ", a[k]);
		}
		printf("\n");
		if (a[i] == key)
		{
			return i;
		}
	}
	return -1;
}
int main(void)
{
	int nx, ky;
	puts("linear search");
	printf("number of elemests: ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++)
	{
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	printf("search value: ");
	scanf("%d", &ky);
	printf("   |");
	for (int i = 0; i < nx; i++)
	{
		printf(" %d", i);
	}
	printf("\n---+---------------------------\n");
	int idx = search(x, nx, ky);
	if (idx == -1)
	{
		puts("search is failed");
	}
	else
	{
		printf("\n%d is located at x[%d].\n", ky, idx);
	}
	free(x);

	return 0;
}