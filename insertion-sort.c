#include <stdio.h>

void insertion(int x[], int n)
{
	int i, j, val;
	for(i = 0; i < n - 1; i++)
	{
		val = x[i + 1];
		for(j = i; j >= 0; j--)
		{
			if(x[j] > val)
				x[j + 1] = x[j];
			else
				break;
		}
		x[j + 1] = val;
	}
}

void main()
{
	int a[100], n, i;
	printf("Enter No. of Elements: ");
	scanf("%d", &n);
	printf("Enter Elements: ");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Array: ");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	insertion(a, n);
	printf("\nSorted Array: ");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
}
