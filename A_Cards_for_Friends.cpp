#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

typedef long long int ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long int> vl;
typedef vector<char> vc;
typedef pair<int, int> pi;
typedef pair<long long int, long long int> pll;

#define endl "\n"
#define pb push_back
#define fo(i, a, b) for (ll i = a; i < b; i++)
#define fos(i, a, b) for (ll i = a; i >= b; i--)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
const ll N = 1e9 + 7;
set<ll> ss;
vi anss;
bool isPalindrome(string str)
{
    // Start from leftmost and rightmost corners of str
    ll l = 0;
    ll h = str.size() - 1;

    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return false;
        }
    }
    return true;
}

void prllAllKLengthRec(char set[], string prefix,
                       ll n, ll k, string check)
{

    // Base case: k is 0,

    static ll count = 0;
    if (k == 0)
    {
        // cout << prefix << endl;
        if (isPalindrome(prefix) && prefix < check)
        {
            // cout << prefix << endl;
            count++;
            count = count % N;
        }
        return;
    }

    // One by one add all characters
    // from set and recursively
    // call for k equals to k-1
    for (ll i = 0; i < n; i++)
    {
        string newPrefix;

        // Next character of input added
        newPrefix = prefix + set[i];

        // k is decreased, because
        // we have added a new character
        prllAllKLengthRec(set, newPrefix, n, k - 1, check);
    }

    ss.insert(count % N);
}

void prllAllKLength(char set[], ll k, ll n, string check)
{
    prllAllKLengthRec(set, "", n, k, check);
}

void solve(ll i)
{
    ll ans = 0;
    string check;
    ll n, k;
    cin >> n >> k;
    cin >> check;

    char set1[26];
    for (ll i = 0; i < k; i++)
    {
        set1[i] = i + 'a';
    }
    // cout << set1[0] << endl;
    // cout << set1[25] << endl;
    prllAllKLength(set1, n, k, check);
    for (auto it : ss)
    {
        ans = it;
    }
    anss.pb(ans);
    // cout << "Case #" << i << ": " << ans << endl;
    ss.clear();
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve(i);
    }
    for (ll i = 1; i <= t; i++)
    {
        if (i == 1)
        {
            cout << "Case #" << i << ": " << anss[i - 1] % N << endl;
        }
        else
        {
            cout << "Case #" << i << ": " << anss[i - 1] % N - anss[i - 2] % N << endl;
        }
    }

    return 0;
}