#include<stdio.h>
#include<string.h>
int main()
{
	int a[10][10] = { 0 }, i = 0, j = 0,k=0,max=0,min=0,x,y,z;
	for (i = 0; i < 10; i++)
	{ 
		for (j = 0;  j< 10; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i=0; i < 10; i++)
	{
		for (j=0; j < 10; j++)
		{
			if (a[i][j] > max)
				max = a[i][j];
			y = j;
		}
		for (k=0; k < 10; k++)
		{
			if (a[k][j] < max)
				z=k;
		}
		if(z==i)
		printf("%d %d\n", i, j);
	}
}
