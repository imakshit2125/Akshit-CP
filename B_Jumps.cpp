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

void solve(vector<int> &weights, vector<int> &values, int capacity)
{

    double ans;
    sort(weights.begin(), weights.end());

    for (int i = 0; i < weights.size(); i++)
    {
        if (capacity - weights[i] > 0)
        {
            ans += (capacity - weights[i]) * values[i];
            capacity -= weights[i];
        }

        else
        {
            ans += (weights[i] - capacity) * values[i];
            break;
        }
    }

    for (int i = 0; i < weights.size(); i++)
        cout << weights[i];
}

bool cmp(int w, int v)
{
    double r1 = (double)v / (double)w;
    double r2 = (double)v / (double)w;
    return r1 > r2;
}

// Driver program to test above function
int main()
{
    vector<int> nums;
    vector<int> values;
    int capacity;

    for (int i = 0; i < 3; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < 3; i++)
    {
        cin >> values[i];
    }

    cin >> capacity;

    cout << solve(vector<int> & nums, vector<int> & values, capacity);

    solve(nums);
    return 0;
}