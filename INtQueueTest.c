#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
	IntQueue que;

	if (Initialize(&que, 64) == -1)
	{
		puts("gen Que is failed.");
		return 1;
	}
	while (1)
	{
		int m, x;

		printf("present number of data: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)enque (2)deque (3)peek (4)print (0)terminate: ");
		scanf("%d", &m);
		
		if (m == 0)
			break;
		switch (m) {
		case 1:
			printf("data: ");
			scanf("%d", &x);
			if (Enque(&que, x) == -1)
			{
				puts("\a erroe: enque is failed.");
			}
			break;
		case 2:
			if (Deque(&que, &x) == -1)
			{
				puts("\a error: deque is failed.");
			}
			else
				printf("deque data is %d. \n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
			{
				puts("\aerror: peek is failed.");
			}
			else
				printf("peek data is %d. \n", x);
			break;
		case 4:
			Print(&que);
			break;
		}
	}
	Terminate(&que);
	return 0;
}