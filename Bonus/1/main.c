#include <stdio.h>
#include <stdlib.h>
#define N 1000000
int main()
{
    int k,i,n=1;
    scanf("%d",&k);
    k++;
    if(k>N-2){
        for(i=1999;i>2;i--){
            if(k%i==0){
                n=i;
                k/=i;
                break;
            }
        }
        if((k+1)>N||n<2)
            printf("-1\n");
        else{
            n++;
            printf("%d\n",n);
            for(i=0;i<n-2;i++)
                printf("0 ");
            printf("-1 %d\n",++k);
        }
    }
    else{
        printf("2\n");
        printf("-1 %d\n",k+2);
    }
    return 0;
}
