#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e6;
int n,visit[maxN];
vector<int> adj_lst[maxN];
deque <int> S;
void find_nei(int x);
int main()
{
    int i,j,k,f,m;

    scanf("%d%d", &n, &m);

    for(i=0;i<n;i++)
        visit[i]=-1;

    for(i=0;i<m;i++)
    {
        scanf("%d%d", &j, &k);
        j--,--k;

        adj_lst[j].push_back(k);
        adj_lst[k].push_back(j);
    }
    S.push_back(1);
    visit[1]=0;
    while(1){
        if(S.empty()!=true){
            find_nei(S.front());
            S.pop_front();
        }
        else
            break;
    }
    printf("%d",visit[0]);
    for(i=1;i<n;i++)
        printf(" %d",visit[i]);
    return 0;
}
void find_nei(int x){
    int i;
    for(i=0;i<adj_lst[x].size();i++){
        if(visit[adj_lst[x][i]]==-1){
            S.push_back(adj_lst[x][i]);
            visit[adj_lst[x][i]]=visit[x]+1;
        }
    }
}
