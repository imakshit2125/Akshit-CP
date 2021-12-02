#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fo(i, b) for (int i = 0; i < b; i++)
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

    ll t;
    cin >> t;
    while (t--)
    {

        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int u = 0, d = 0, r = 0, l = 0;
        if (x > 0)
        {
            r = x;
        }
        else
        {
            l = -x;
        }

        if (y > 0)
        {
            u = y;
        }
        else
        {
            d = -y;
        }

        ll cU = 0, cL = 0, cD = 0, cR = 0;

        fo(i, s.size())
        {
            if (s[i] == 'U')
                cU++;

            else if (s[i] == 'R')
                cR++;

            else if (s[i] == 'L')
                cL++;

            else if (s[i] == 'D')
                cD++;
        }

        if (cD >= d && cU >= u && cR >= r && cL >= l)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
