#include <iostream>
#include <algorithm>
using namespace std;

int n;
int input[10000];

int main()
{
    int i,j,k;

    //
    //  read the input array
    //
    cin >> n;
    for(i=0;i<n;i++)
        cin >> input[i];

    //
    //  use built-in sort algorithm to sort the array
    //
    sort(input, input+n);

    return 0;
}
