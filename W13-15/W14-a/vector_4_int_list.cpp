#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> lst;

    int i,j,k;

    // read the input integers

    scanf("%d", &k);
    for(i=0;i<k;i++)
    {
        scanf("%d", &j);
        lst.push_back(j);
    }

    // print all the integers in the list

    // method 1: using array index
    for(i=0;i<lst.size();i++)
        printf("%d ", lst[i]);
    printf("\n");


    // method 2: using iterators

    vector<int>::iterator it = lst.begin();
    // or,
    auto it2 = lst.begin();

    while( it != lst.end() )
        printf("%d ", *it++);
    printf("\n");

    //

    return 0;
}
