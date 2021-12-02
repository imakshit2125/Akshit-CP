#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fo(i, a, b) for (int i = a; i < b; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    scanf("%lld", &n);

    ll arr[n];

    fo(i, 0, n)
    {
        scanf("%lld", &arr[i]);
    }

    ll count = 0;

    fo(i, 1, n)
    {
        if (arr[i] >= arr[i - 1])
            continue;

        else if (arr[i] < arr[i - 1])
        {
            int m = (arr[i - 1] - arr[i]);
            count += m;
            arr[i] += m;
        }
    }
    printf("%lld", count);

    return 0;
}