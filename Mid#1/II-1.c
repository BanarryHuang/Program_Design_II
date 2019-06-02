#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,i,j,k,l,pivot=0,lead=-1,temp,flag,T;
    int **array,a[25];

    //freopen("in.txt","r",stdin);

    scanf("%d%d",&y,&x);

    array=malloc(x*sizeof(*array));

    for(i=0;i<x;i++)
        array[i]=malloc(y*sizeof(**array));

    for(i=0;i<x;i++){
        for(j=0;j<y;j++)
            scanf("%d",&(array[i][j]));
    }

    while(pivot<y){

        flag=1;

        for(i=lead+1;i<x;i++){
            if(array[i][pivot]==1){
                lead++;
                flag=0;
                break;
            }
        }

        if(flag==1){
            pivot++;
            continue;
        }

        for(j=pivot;j<y;j++){
            temp=array[i][j];
            array[i][j]=array[lead][j];
            array[lead][j]=temp;
        }

        for(i=lead+1;i<x;i++){
            if(array[i][pivot]==1){
                for(j=pivot;j<y;j++)
                    array[i][j]=(array[i][j]+array[lead][j])%2;
            }
        }
        pivot++;
    }
    lead++;
    scanf("%d",&T);
    for(i=0;i<T;i++){

        for(j=0;j<y;j++)
            scanf("%d",a+j);

        for(j=0;j<lead;j++){
            for(k=0;k<y;k++)
                if(array[j][k]==1)
                    break;
            if(a[k]==1){
                for(l=k;l<y;l++)
                    a[l]=(a[l]+array[j][l])%2;
            }
        }
        flag=0;
        for(j=0;j<y;j++)
            if(a[j]!=0){
                flag=1;
                break;
            }
        if(flag==1)
            printf("No\n");
        else
            printf("Yes\n");

    }

    return 0;
}
