#include <stdio.h>
#include <stdlib.h>

int n;
int input[10000];

int compare(const void *a, const void *b);

int main()
{
    int i,j,k;

    //
    // read the input array
    //
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &input[i]);

    //
    // use built-in quick sort to sort the array
    //
    qsort(input, n, sizeof(int), compare);

    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
