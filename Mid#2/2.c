#include <stdio.h>
#define n 20002

int main(){

    int i,j,k,N,M;
    int m[51];
    int w[51][n][2];
    int sum[51];

    scanf("%d",&N);

    for(i=0;i<=N;i++)
        for(j=0;j<=M;j++){
            w[i][j][0]=0;
            w[i][j][1]=0;
        }

    for(i=1;i<=N;i++){
        scanf("%d",m+i);
        sum[i]=0;
    }

    scanf("%d",&M);

    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++)
            w[i][j][0]=w[i-1][j][0];
        w[i][m[i]][0]=1;
        w[i][m[i]][1]=1;
        for(j=m[i];j<=M;j++){
            if(w[i][j-m[i]][0]!=0){
                if(w[i-1][j][0]>(w[i][j-m[i]][0]+1)||w[i][j][0]==0){
                    w[i][j][0]=w[i][j-m[i]][0]+1;
                    w[i][j][1]=1;
                }
            }
        }
    }
    /*for(i=1;i<=N;i++){
        for(j=1;j<=M;j++)
            printf("%d ",w[i][j]);
        printf("\n");
    }*/
    if(w[N][M][0]!=0)
        printf("%d\n",w[N][M][0]);
    else
        printf("-1\n");
    if(w[N][M][0]!=0){
        for(i=N;i>0;i--){
            while(w[i][M][1]==1){
                sum[i]++;
                M-=m[i];
            }
        }
    }
    printf("%d",sum[1]);
    for(i=2;i<=N;i++)
        printf(" %d",sum[i]);
    printf("\n");
    return 0;
}
