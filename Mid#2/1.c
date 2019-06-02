#include <stdio.h>
#define n 1002
typedef struct dish{
    int happy;
    int weight;
}D;
int main(){
    int i,j,k,N,W,max=0,sel,dishes=0;
    D d[501];
    int w[501][n][2];
    int di[501];

    scanf("%d%d",&N,&W);

    for(i=0;i<N;i++)
        for(j=1;j<=W;j++){
            w[i][j][0]=0;
            w[i][j][1]=0;
        }

    for(i=0;i<N;i++){
        scanf("%d%d",&(d[i].happy),&(d[i].weight));
        if(i==0){
            w[0][d[i].weight][0]=d[0].happy;
            w[0][d[i].weight][1]=1;
        }
        if(i>0){
            for(j=1;j<=W;j++)
                w[i][j][0]=w[i-1][j][0];
            for(j=d[i].weight;j<=W;j++){
                if((w[i-1][j-d[i].weight][0]+d[i].happy)>w[i][j][0]){
                    w[i][j][0]=w[i-1][j-d[i].weight][0]+d[i].happy;
                    w[i][j][1]=1;
                }
            }
        }
    }
    /*for(i=0;i<N;i++){
        for(j=1;j<=W;j++)
            printf("%d ",w[i][j][1]);
        printf("\n");
    }*/
    for(j=1;j<=W;j++)
        if(max<w[N-1][j][0]){
            max=w[N-1][j][0];
            sel=j;
        }

    printf("%d\n",max);
    i=N-1;
    while(sel!=0){
        if(w[i][sel][1]==1){
            di[dishes++]=i;
            sel-=d[i].weight;
        }
        i--;
    }
    printf("%d",di[dishes-1]+1);
    for(i=dishes-2;i>-1;i--)
        printf(" %d",di[i]+1);
    printf("\n");
    return 0;
}
