#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define N 10000003
int partition(int arr[], int l, int r)
{
    int x = arr[r];
    int i = l,j;
    for (j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int k)
{

    if (k > 0 && k <= r - l + 1) {

        int index = partition(arr, l, r);


        if (index - l == k - 1)
            return arr[index];

        if (index - l > k - 1)
            return kthSmallest(arr, l, index - 1, k);

        return kthSmallest(arr, index + 1, r,
                            k - index + l - 1);
    }

    return INT_MAX;
}
int main(){
    int i,n,k;
    int num[N];

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",num+i);

    scanf("%d",&k);

    printf("%d\n",kthSmallest(num, 0, n-1, k));

    return 0;
}
