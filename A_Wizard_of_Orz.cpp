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

    int t;
    cin >> t;
    while (t--)
    {

        ll n;
        cin >> n;

        if (n <= 2)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << 9 - i + 1;
            }
            cout << endl;
        }

        else
        {
            cout << "98";

            int k = (n - 2) % 10;

            if (k == 0)
            {
                for (int i = 1; i <= (n - 2) / 10; i++)
                    cout << "9012345678";
            }

            else
            {
                for (int i = 1; i <= (n - 2) / 10; i++)
                    cout << "9012345678";

                cout << 9;

                for (int i = 2; i <= k; i++)
                    cout << i - 2;
            }

            cout << endl;
        }
    }
}
