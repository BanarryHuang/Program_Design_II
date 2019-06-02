#include <stdio.h>
#include <string.h>
#define d 200010
#define max_int 3*1e18
typedef long long int LL;
LL N,M,w[d];
int test(LL x){
    int i,flag=1,t=0;
    LL sum=0;
    for(i=0;i<N;i++){
        if(w[i]>x){
            flag=0;
            break;
        }
        sum+=w[i];
        if(sum>x){
            sum=w[i];
            t++;
        }
        if(t>M){
            flag=0;
            break;
        }
    }
    t++;
    if(t>M)
            flag=0;
    return flag;
}
LL binary_search(LL left,LL right )
{
    if( test(left) == 1 )
        return left;

    if( test(right) == 0 )
        return -1;

    LL mid;

    while( left < right - 1 )
    {
        mid = ( left + right ) / 2;

        if( test(mid) == 0 )
            left = mid;
        else
            right = mid;
    }

    return right;
}

int main(){
    int i;
    scanf("%lld%lld",&N,&M);

    for(i=0;i<N;i++)
        scanf("%lld",w+i);

    printf("%lld\n",binary_search(1,max_int));

    return 0;
}
