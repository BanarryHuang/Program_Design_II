
int i,j,k;

......
............

int modl = (int)1e9+7;

int ans = 1;

for(i=2;i<k;i++)
{
    ans = ((long long int)ans) * i % modl;
    //
    // or, equivalently,
    //
    // ans = 1LL * i % modl;
}
