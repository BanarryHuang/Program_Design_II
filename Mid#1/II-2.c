#include <stdio.h>
#include <string.h>
int n,m;
char map[50][50];
int src[2],des[2];
int reachable[50][50];
int fromm[50][50][2];
int path[50*50][2], length_of_path=0;
int dirs[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }} ;
void explore( int cur_pos[2] );
void construct_path( int dest[2] );
int main(){
    int i,j,count=0;
    char temp[100];
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",temp);
        for(j=0;j<m;j++){
            map[i][j]=temp[j];
            reachable[i][j]=0;
            fromm[i][j][0]=-1;
            fromm[i][j][1]=-1;
        }
    }
    scanf("%d %d",&(src[0]),&(src[1]));

    src[0]--;
    src[1]--;
    explore(src);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(reachable[i][j]==1&&map[i][j]=='*')
                count++;
        }
    printf("%d\n",count);
    return 0;
}
void explore( int cur_pos[2] ){
    int i,j,t1,t2;
    int new_pos[2];
    if((map[cur_pos[0]][cur_pos[1]]=='.'||map[cur_pos[0]][cur_pos[1]]=='*')&&reachable[cur_pos[0]][cur_pos[1]]==0){
        reachable[cur_pos[0]][cur_pos[1]]=1;
        for(i=0;i<4;i++){
            t1=cur_pos[0]+dirs[i][0];
            t2=cur_pos[1]+dirs[i][1];
            if((map[t1][t2]=='.'||map[t1][t2]=='*')&&t1<n&&t2<m&&t1>-1&&t2>-1&&reachable[t1][t2]==0){
                fromm[t1][t2][0]=cur_pos[0];
                fromm[t1][t2][1]=cur_pos[1];
                new_pos[0]=t1;
                new_pos[1]=t2;
                explore(new_pos);
            }
        }
    }
}
/*void construct_path( int dest[2] )
{
    int cur_pos[2],x,y;

    cur_pos[0] = dest[0];
    cur_pos[1] = dest[1];

    while( cur_pos[0] != src[0] || cur_pos[1] != src[1] )
    {
        path[length_of_path][0]=cur_pos[0];
        path[length_of_path++][1]=cur_pos[1];
        x=cur_pos[0];
        y=cur_pos[1];
        cur_pos[0] = fromm[x][y][0];
        cur_pos[1] = fromm[x][y][1];
    }
    path[length_of_path][0]=cur_pos[0];
    path[length_of_path++][1]=cur_pos[1];
}*/
