#include <stdio.h>
#include <stdlib.h>
#define N 502

int main(){

    int x,y,i,j,k,a,b,s,d,T;
    int r[N][N],P[N][N];

    scanf("%d%d",&x,&y);

    for(i=0;i<N;i++)
    for(j=0;j<N;j++){
        r[i][j]=0;
        P[i][j]=0;
    }
    for(i=1;i<=x;i++)
    for(j=1;j<=y;j++){
        scanf("%d",&(r[i][j]));
    }
    for(i=1;i<y;i++)
        P[0][i]=r[0][i];
    for(i=1;i<x;i++)
        P[i][0]=r[i][0];
    for(i=2;i<x;i++)
        for(j=2;j<y;j++){
            P[i][j]=P[i-1][j]+P[i][j-1]+r[i][j];
        }
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&a,&b,&s,&d);
        printf("%d\n",P[b][d]-P[a][d]-P[b][s]+P[a][s]);
    }
    return 0;
}
