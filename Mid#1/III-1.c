#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int x=0;
void Print(int *a, int *b, int k)
{
	int i;
	for (i = k - 1; i >= 0; i--)
	{
		if(b[k] == b[i] + 1 && a[i] < a[k])
		{
			Print(a, b, i);
			break;
		}
	}
	printf("%d",a[k]);
    x++;
}
void FindMDS(int *a, int len)
{
	int i, j, maxi = 0;
	int B[len];
	for(i = 0 ; i < len; i++)
		B[i] = 0;

	for(i = 0; i < len; i++)
	{
		B[i] = 1;
		for(j = 0; j < i; j++)
		{
			if(a[j] < a[i] && B[j] + 1 > B[i])
			{
				B[i] = B[j] + 1;
				if(B[i] > B[maxi])
					maxi = i;
			}
		}
	}
	Print(a, B, maxi);
}
int main()
{
    int i,j,b[100];
    char a[50];
    while(scanf("%s",a)!=EOF){
        for(i=0;i<strlen(a);i++)
            b[i]=a[i]-'0';
        FindMDS(b, i);
        printf("\n");
        for(i=0;i<100;i++)
            b[i]=0;
    }
}
