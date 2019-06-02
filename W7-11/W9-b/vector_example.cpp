#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    vector<int> input_array;

    //
    //  Read an array of n elements and multiply each element by m

    cin >> n >> m;

    input_array.resize(n);

    for(int i=0;i<n;i++)
    {
        cin >> input_array[i];

        input_array[i] *= m;
    }

    //

    input_array.push_back(10);
    input_array.push_back(11);

    //

    return 0;
}
