#include <stdio.h>
#include <stdlib.h>
#define N 100010
long long int B[N];
long long int cmp( const void *a , const void *b )
{
    return *(long long int *)a - *(long long int *)b;
}
int binary_search(int left, int right, long long int t)
{
    if( B[left] > t )
        return 0;

    if( B[right] <= t )
        return right+1;

    int mid;

    while( left < right - 1 )
    {
        mid = ( left + right ) / 2;

        if( B[mid] <= t )
            left = mid;
        else
            right = mid;
    }

    return left+1;
}
int main()
{
    long long int A[N],x,L,R;
    int n,m,e,f,g,h,i,j;

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
        scanf("%lld",A+i);
    for(i=0;i<m;i++)
        scanf("%lld",B+i);

    qsort(B,m,sizeof(B[0]),cmp);

    scanf("%lld%lld",&L,&R);

    for(i=0;i<n;i++){
        x=A[i];printf("%d ",x);
        e=binary_search(0,m-1,x+R);
        f=binary_search(0,m-1,x-R-1);
        g=binary_search(0,m-1,x+L-1);
        h=binary_search(0,m-1,x-L);
        printf("%d\n",(e-f-g+h));
    }

    return 0;
}
