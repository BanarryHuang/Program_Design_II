#include <stdio.h>
int cmp( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}
int main(){

    int i,n,x,y,sum=0;
    int a[200010];

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",a+i);

    qsort(a,n,sizeof(a[0]),cmp);

    for(i=0;i<n;i++){
        if(sum<a[i]){
            sum++;
        }
        else if(sum>a[i]){
            sum--;
            break;
        }
    }

    printf("%d",sum);
    return 0;
}
