#include <stdio.h>

int main(){

    int i,n,x,y,sum=0;
    char a[200010];

    scanf("%d%d%d",&n,&x,&y);

    scanf("%s",a);

    if(a[n-y-1]!='1')
            sum++;

    for(i=n-x;i<n;i++){
        if(i!=n-y-1&&a[i]=='1')
            sum++;
    }

    printf("%d",sum);
    return 0;
}
