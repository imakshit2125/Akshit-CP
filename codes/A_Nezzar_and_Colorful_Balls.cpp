#include <bits/stdc++.h>
using namespace std;
#define IM LLONG_MAX
#define Im LLONG_MIN
typedef long long int ll;
typedef long double ld;
#define fo(i, a, b) for (int i = a; i < b; i++)
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
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

ll e[100001] = {0};
void ans(ll n, ll k)
{
    e[0] = 1;
    e[1] = k;
    for (ll i = 2; i <= n; i++)
    {
        e[i] = (e[i - 1] * k) % mod;
    }
}

void solve()
{

    ll n, k;
    cin >> n >> k;
    ans(n, k);
    string str;
    cin >> str;
    ll cnt = 0;
    for (ll i = 0; i < (n + 1) / 2; i++)
    {
        ll temp = str[i] - 'a';
        cnt = (cnt + (temp * (e[(n + 1) / 2 - i - 1])) % mod) % mod;
    }
    bool flag = 1;
    string temp = str;
    for (ll i = 0; i < (n + 1) / 2; i++)
    {
        temp[n - i - 1] = str[i];
    }

    if (temp < str)
        cnt = (cnt + 1) % mod;
    cout << cnt << endl;
}

int32_t main()
{
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}