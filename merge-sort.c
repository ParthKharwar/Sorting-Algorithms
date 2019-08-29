#include <stdio.h>

void merge(int x[], int lb, int ub, int m)
{
	int temp[100], i = lb, j = m + 1, k = 0;
	while(i <= m && j <= ub)
	{
		if(x[i] < x[j])
			temp[k++] = x[i++];
		else
			temp[k++] = x[j++];
	}
	while(i <= m)
        		temp[k++]=x[i++];
	while(j <= ub)
        		temp[k++]=x[j++];
	k = 0;
	for(i = lb; i <= ub; i++)
		x[i] = temp[k++];
}

void mergesort(int x[], int lb, int ub)
{
	int m;
	if(lb < ub)
	{
		m = (lb + ub) / 2;
		mergesort(x, lb, m);
		mergesort(x, m + 1, ub);
		merge(x, lb, ub, m);
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
	mergesort(a, 0, n - 1);
	printf("\nSorted Array: ");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
}
