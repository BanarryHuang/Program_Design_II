#include <stdio.h>
int cmp( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}
int main(){

    int T,i,j,n,x,y,flag;
    long long int sum;
    int a[302];

    scanf("%d",&T);

    while(T--){

        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",a+i);

        qsort(a,n,sizeof(a[0]),cmp);

        if(n==1){
            flag=1;
            j=0;
            sum=a[0]*a[0];
            for(i=2;i*i<sum;i++){
                if((long long int)sum%i==0){
                    if(a[j]!=i){
                        flag=0;
                        printf("-1\n");
                        break;
                    }
                    else
                        j++;
                }
            }
            if(flag==1)
                printf("%d\n",sum);
        }

        else{
            flag=1;
            sum=a[0]*a[n-1];
            j=0;
            for(i=2;i*i<sum;i++){
                if((long long int)sum%i==0){
                    if(a[j]!=i){
                        flag=0;
                        printf("-1\n");
                        break;
                    }
                    else
                        j++;
                }
            }
            if(flag==1){
            if(n%2==0){
                for(i=1;i<n/2+1;i++){
                    if((long long int)a[i]*a[n-i-1]!=sum){
                        flag=0;
                        break;
                    }
                }
                if(flag==0)
                    printf("-1\n");
                else
                    printf("%d\n",sum);
            }
            else{
                for(i=1;i<n/2;i++){
                    if((long long int)a[i]*a[n-i-1]!=sum){
                        flag=0;
                        break;
                    }
                }
                if((long long int)a[n/2]*a[n/2]!=sum)
                    flag=0;
                if(flag==0)
                    printf("-1\n");
                else
                    printf("%d\n",sum);
            }
            }
        }
        for(i=0;i<n;i++)
            a[i]=0;
    }

    return 0;
}
