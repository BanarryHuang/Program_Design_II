#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e4;
int n,visit[maxN];
vector<int> adj_lst[maxN];
void find_nei(int x);
int main()
{
    int i,j,k,f,m,grade[maxN],max_index=-1,siz;
    double temp,max_num=0;

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++){
        scanf("%d",grade+i);
        visit[i]=-1;
    }

    for(i=0;i<m;i++)
    {
        scanf("%d%d", &j, &k);
        j--,--k;
        if(j!=k){
            adj_lst[j].push_back(k);
            adj_lst[k].push_back(j);
        }
    }
    for(i=0;i<n;i++){
        if(visit[i]==-1){
            visit[i]=i;
            find_nei(i);
        }
    }
    for(i=0;i<n;i++){
        if(visit[i]==i){
            siz=0;
            temp=0;
            for(j=i;j<n;j++){
                if(visit[j]==i){
                    temp+=grade[j];
                    siz++;
                }
            }
            if(temp/siz>max_num){
                max_num=temp/siz;
                max_index=i;
            }
        }
    }
    f=0;
    for(i=0;i<n;i++){
        if(visit[i]==max_index){
            if(f==0){
                printf("%d",i+1);
                f=1;
            }
            else
                printf(" %d",i+1);
        }
    }
    return 0;
}
void find_nei(int x){
    int i;
    for(i=0;i<adj_lst[x].size();i++){
        if(visit[adj_lst[x][i]]==-1){
            visit[adj_lst[x][i]]=visit[x];
            find_nei(adj_lst[x][i]);
        }
    }
}
