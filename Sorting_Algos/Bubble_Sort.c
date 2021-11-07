#include<stdio.h>
void bubble_sort(int a[], int n)
{
	int i, j, temp;
	for(i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}	
}

void main()
{
	int i, a[10], n;
	printf("Enter Array Size: ");
	scanf("%d", &n);
	printf("enter array Elements");
	
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}

	bubble_sort(a, n);

	printf("After Sorting Elements are: \n");

	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
}







