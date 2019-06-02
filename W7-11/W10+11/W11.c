#include <stdio.h>
#define n 1002
typedef struct dish{
    int happy;
    int weight;
}D;
int main(){

    int i,j,k,N,W,max=0;
    D d[501];
    int w[501][n];

    scanf("%d%d",&N,&W);

    for(i=0;i<N;i++)
        for(j=1;j<=W;j++)
            w[i][j]=0;

    for(i=0;i<N;i++){
        scanf("%d%d",&(d[i].happy),&(d[i].weight));
        if(i==0)
            w[0][d[i].weight]=d[0].happy;
        if(i>0){
            for(j=1;j<=W;j++)
                w[i][j]=w[i-1][j];
            for(j=d[i].weight;j<=W;j++)
                if((w[i-1][j-d[i].weight]+d[i].happy)>w[i][j])
                    w[i][j]=w[i-1][j-d[i].weight]+d[i].happy;
        }
    }

    for(j=1;j<=W;j++)
        if(max<w[N-1][j])
            max=w[N-1][j];

    printf("%d\n",max);

    return 0;
}
