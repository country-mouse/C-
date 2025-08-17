#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[],int n, int key)
{
	int s = 0;
	int e = n-1;
	while (1)
	{
		int m = (s + e) / 2;
		printf("   |");
		for (int j = 0; j <= e; j++)
		{
			if (j == s)
			{
				printf(" <=");
			}
			else if (j == e)
			{
				printf(" =>");
			}
			else if (j == m)
			{
				printf("  +");
			}
			else
			{
				printf("   ");
			}
			
		}
		printf("\n");
		printf("  %d|  ", m);
		for (int k = 0; k < n; k++)
		{
			printf("%d  ", a[k]);
		}
		printf("\n");
		if (a[m] > key)
		{
			e = m-1;
		}
		else if(a[m] < key)
		{
			s = m+1;
		}
		else if (a[m]==key)
		{
			return m;
		}
		else if (s > e)
		{
			return -1;
		}
	}
}

int main(void)
{
	int nx, ky;

	puts("binary search");
	printf("number of elements: ");
	scanf("%d", &nx);
	int* x = calloc(nx, sizeof(int));
	printf("오름차 순으로 입력하세요.\n");
	printf("x[0]: ");
	scanf("%d", &x[0]);
	for (int i = 1; i < nx; i++)
	{
		do {
			printf("x[%d]: ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("search value: ");
	scanf("%d", &ky);
	printf("   |");
	for (int i = 0; i < nx; i++)
	{
		printf(" %d", i);
	}
	printf("\n---+---------------------------\n");
	int idx = bin_search(x, nx, ky);
	if (idx == -1)
	{
		puts("search is failed");
	}
	else
	{
		printf("%d is located at x[%d].", ky, idx);
	}
	free(x);

	return 0;
}