#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,i,j,k,l,z,pivot=0,lead=-1,temp,f,flag,T;
    int t_array[1010][300],array[1010][1200],a[300],b[300];

    //freopen("in.txt","r",stdin);

    scanf("%d%d",&y,&x);

    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            scanf("%d",&(t_array[i][j]));

    scanf("%d",&z);

    for(i=0;i<z;i++)
        scanf("%d",b+i);

    for(i=0;i<x;i++){
        for(j=0;j<z;j++){
            array[i][j]=t_array[i][b[j]-1];
        }
        for(j=z;j<z+x;j++){
            if(i==j-z)
                array[i][j]=1;
            else
                array[i][j]=0;
        }
    }

    while(pivot<z+x){

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

        for(j=pivot;j<z+x;j++){
            temp=array[i][j];
            array[i][j]=array[lead][j];
            array[lead][j]=temp;
        }

        for(i=lead+1;i<x;i++){
            if(array[i][pivot]==1){
                for(j=pivot;j<z+x;j++)
                    array[i][j]=(array[i][j]+array[lead][j])%2;
            }
        }
        pivot++;
    }
    lead++;

    for(j=0;j<z;j++)
        a[j]=1;
    for(j=z;j<z+x;j++)
        a[j]=0;

    for(j=0;j<lead;j++){
        for(k=0;k<z;k++)
            if(array[j][k]==1)
                break;
        if(a[k]==1){
            for(l=k;l<z+x;l++)
                a[l]=(a[l]+array[j][l])%2;
        }
    }
    flag=1;
    for(j=0;j<z;j++)
        if(a[j]!=0){
            flag=0;
            break;
        }

    if(flag==0)
        printf("Farewell, Dom.\n");
    else{
        f=0;
        for(j=z;j<z+x;j++){
            if(a[j]==1){
                if(f==0){
                    printf("%d",j-z+1);
                    f++;
                }
                else
                    printf(" %d",j-z+1);
            }
        }
    }

    return 0;
}
