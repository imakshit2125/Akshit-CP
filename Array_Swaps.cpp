#include <bits/stdc++.h>
using namespace std;
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
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define MOD 1000000007
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

    ll n, m;
    cin >> n >> m;

    ll a[n], b[n];

    fo(i, 0, n)
            cin >>
        a[i];

    fo(i, 0, m)
            cin >>
        b[i];

    sort(b, b + m);
    sort(a, a + n);

    ll cnt = 0;
    ll ans = 0;
    vector<ll> vec1;
    vector<ll> vec2;
    int k;
    for (int i = 0; i < m; i++)
    {
        if (b[m - 1] > a[i])
        {
            k = i;
            break;
        }
        else
        {
            vec2.push_back(a[i]);
        }
    }

    for (int i = 0; i < k; i++)
    {
        vec1.push_back(a[i]);
    }

    for (int i = k; i < n; i++)
        vec2.push_back(a[i]);

    for (int i = 0; i < vec2.size(); i++)
        vec1.push_back(vec2[i]);

    int l = 0;

    for (int i = 0; i < m; i++)
    {

        if (b[i] >= vec1[0])
            cnt = 0;

        if (b[i] < vec1[0])
        {
            cnt = cnt + vec1.size() + l;
            l++;
        }

        ans += cnt;
    }

    /*   for (int i = 0; i < vec1.size(); i++)
        cout << vec1[i] << " ";
    cout << endl; */
    cout << ans << endl;

    return 0;
}