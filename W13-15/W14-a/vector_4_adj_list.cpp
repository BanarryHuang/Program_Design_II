#include <bits/stdc++.h>
using namespace std;

const int maxN = (int)1e5;

int n;
vector<int> adj_lst[maxN];

int main()
{
    int i,j,k;

    //

    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        scanf("%d%d", &j, &k);  // internal indexing of the vertices:
        j--,--k;                // from 0 to n-1

        adj_lst[j].push_back(k);
        adj_lst[k].push_back(j);
    }

    //

    ......


    return 0;
}
