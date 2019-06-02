#include <stdio.h>

int main(){

    int i,n,x,y,sum;
    char a[200010],b[200010];

    scanf("%d",&n);

    scanf("%s",a);
    b[0]=a[0];
    sum=0;
    for(i=1;i<n;i++){
        if(sum%2==0){
            if(a[i]!=b[sum])
                b[++sum]=a[i];
        }
        else
            b[++sum]=a[i];
    }
    sum++;
    if(sum%2==0)
        printf("%d\n",n-sum);
    else
        printf("%d\n",n-(sum-1));
    if(sum>0){
        if(sum%2==0){
            for(i=0;i<sum;i++)
                printf("%c",b[i]);
        }
        else{
            for(i=0;i<sum-1;i++)
                printf("%c",b[i]);
        }
    }
    return 0;
}
