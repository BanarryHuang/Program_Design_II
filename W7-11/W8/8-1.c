#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long int cmp( const void *a , const void *b );
long long int gcd(long long int m, long long int n) {
    while(n != 0) {
        long long int r = m % n;
        m = n;
        n = r;
    }
    return m;
}
int main(){
    long long int n,T=8,count=0,g=0;
    long long int num[10],diff[10],guess[10],min=0;
    int i,j,flag;
    char string[50];
    scanf("%lld",&n);

    if(n>8){
        while(T--){
            flag=1;
            guess[g]=(rand()+n*(T/8))%n;
            while(flag){
                for(i=0;i<g;i++){
                    if(guess[i]==guess[g]||guess[g]==0){
                        guess[g]=(rand()+n*(T/8))%n;
                        break;
                    }
                }
                if(i==g)
                    flag=0;
            }
            printf("? %d\n",guess[g]);
            fflush(stdout);
            scanf("%lld",num+count);
            g++;
            count++;
        }
        qsort(num,8,sizeof(num[0]),cmp);
        for(i=0;i<7;i++){
            diff[i]=num[i+1]-num[i];
        }
        qsort(diff,7,sizeof(diff[0]),cmp);
        for(i=0;i<7;i++){
            min=gcd(diff[i],min);
            flag=1;
            for(j=2;j*j<min;j++){
                if(min%j==0){
                    flag=0;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(min<0)
            min*=-1;
        printf("! %d\n",min);
        fflush(stdout);
        fgets(string,50,stdin);
    }
    else{
        for(i=1;i<=n;i++){
            printf("? %d\n",i);
            fflush(stdout);
            scanf("%lld",num+count);
            count++;
        }
        qsort(num,n,sizeof(num[0]),cmp);
        for(i=0;i<n-1;i++){
            diff[i]=num[i+1]-num[i];
        }
        qsort(diff,n-1,sizeof(diff[0]),cmp);
        for(i=0;i<n-1;i++){
            min=gcd(diff[i],min);
            flag=1;
            for(j=2;j*j<min;j++){
                if(min%j==0){
                    flag=0;
                    break;
                }
            }
            if(flag)
                break;
        }
        printf("! %d\n",min);
        fflush(stdout);
        fgets(string,50,stdin);
    }
    return 0;
}
long long int cmp( const void *a , const void *b )
{
    return *(long long int *)a - *(long long int *)b;
}
