#include <stdio.h>

int partition(int x[], int lb, int ub)
{
	int val = x[lb], down = lb, up = ub, t;
	while(down < up)
	{
		while(down <= up && x[down] <= val)
			down++;
		while(x[up] > val)
			up--;
		if(down < up)
		{
			t = x[down];
			x[down] = x[up];
			x[up] = t;
		}
	}
	x[lb] = x[up];
	x[up] = val;
	return up;
}

void quicksort(int x[], int lb, int ub)
{
	int p;
	if(lb < ub)
	{
		p = partition(x, lb, ub);
		quicksort(x, lb, p - 1);
		quicksort(x, p + 1, ub);
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
	quicksort(a, 0, n - 1);
	printf("\n");
	printf("Sorted Array: ");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
