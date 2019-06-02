#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,num,i;
    int mod=1e9+7;
    scanf("%d",&T);

    while(T--){
        long long int ans=1;

        scanf("%d",&num);

        for(i=1;i<=num;i++)
            ans=(ans*i)%mod;

        printf("%lld\n",ans);
    }

    return 0;
}
