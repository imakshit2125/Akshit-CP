#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll arr[n - 1];

    for (ll i = 0; i < n - 1; i++)
        cin >> arr[i];

    sort(arr, arr + (n - 1));

    ll k;
    if (n == 2)
    {
        if (arr[0] == 1)
            cout << 2 << endl;

        else
        {
            cout << 1 << endl;
        }
    }
    else
    {
        int flag = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            if (arr[i] != i + 1)
            {
                cout << i + 1 << endl;
                break;
            }
        }

        if (arr[n - 2] == n - 1)
        {
            cout << n << endl;
        }
    }

    return 0;
}