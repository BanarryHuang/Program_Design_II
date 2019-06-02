#include <stdio.h>
#include <string.h>
#define n 100003
int main(){

    long long int i,N,e=0,w=0;
    long long int X,day=0,E[n],W[n];
    char d[n];

    scanf("%lld",&N);

    scanf("%s",d);

    for(i=0;i<strlen(d);i++){
        if(d[i]=='E')
            E[e++]=i+1;
        if(d[i]=='W')
            W[w++]=i+1;
    }

    scanf("%lld",&X);

    if(X==0){
        printf("0\n");
        return 0;
    }

    if(X>0){
        if(X%2==0)
            X=X/2;
        else
            X=X/2+1;
        if(e==0){
            printf("-1\n");
        }
        else{
            day=(X/e-1)*N;
            if(X%e>0)
                day=day+N+E[X%e-1];
            else
                day=day+E[e-1];
            printf("%lld\n",day);
        }
    }
    else{
        X*=-1;
        if(X%2==0)
            X=X/2;
        else
            X=X/2+1;
        if(w==0){
            printf("-1\n");
        }
        else{
            day=(X/w-1)*N;
            if(X%w>0)
                day=day+N+W[X%w-1];
            else
                day=day+W[w-1];
            printf("%lld\n",day);
        }
    }

    return 0;
}
