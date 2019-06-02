#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5;
int n,visit[maxN];
vector<int> adj_lst[maxN];
int find_nei(int x);
int main()
{
    int i,j,k,f;

    scanf("%d", &n);

    for(i=0;i<n;i++)
        visit[i]=-1;

    for(i=0;i<n-1;i++)
    {
        scanf("%d%d", &j, &k);
        j--,--k;

        adj_lst[j].push_back(k);
        adj_lst[k].push_back(j);
    }
    visit[0]=1;
    if(find_nei(0)==1){
        f=1;
        for(i=0;i<n;i++)
            if(visit[i]==-1)
                f=0;
        if(f==1){
            printf("1");
            for(i=1;i<n;i++)
                if(visit[i]==1)
                    printf(" %d",i+1);
            printf("\n");
        }
        else
            printf("-1\n");
    }
    else
        printf("-1\n");
    return 0;
}
int find_nei(int x){
    int i;
    for(i=0;i<adj_lst[x].size();i++){
        if(visit[adj_lst[x][i]]==-1){
            if(visit[x]==1)
                visit[adj_lst[x][i]]=0;
            else if(visit[x]==0)
                visit[adj_lst[x][i]]=1;
            find_nei(adj_lst[x][i]);
        }
        else{
            if(visit[adj_lst[x][i]]==visit[x])
                return 0;
        }
    }
    return 1;
}
