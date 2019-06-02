#include <stdio.h>
#include <string.h>
#define N 100010
int main(){
    int i,n,sum,apSum=0,temp;
    int a[N],b[N];

    scanf("%d %d",&n,&sum);

    for(i=0;i<n;i++){
        scanf("%d",a+i);
        if(a[i]>=sum){
            apSum=a[i];
            b[i]=i+1;
        }
        else{
            apSum+=a[i];
            if(apSum<sum)
                b[i]=-1;
            else if(b[i-1]!=-1){
                temp=b[i-1]-1;
                while(apSum>=sum){
                    apSum-=a[temp];
                    temp++;
                }
                apSum+=a[--temp];
                b[i]=temp+1;
            }
            else{
                temp=0;
                while(apSum>=sum){
                    apSum-=a[temp];
                    temp++;
                }
                apSum+=a[--temp];
                b[i]=temp+1;
            }
        }
    }
    printf("%d",b[0]);
    for(i=1;i<n;i++)
        printf(" %d",b[i]);
    printf("\n");

    return 0;
}
