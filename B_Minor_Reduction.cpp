/* ॐ  */
/* aaravaki2125 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fo(i, a, b) for (ll i = a; i < b; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
//#define ss(s) scanf("%s", s)
#define setval(x, n) std::cout << std::setprecision(n) << x << '\n'
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define ff first
#define ss second
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
 
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
ll power(ll x, ll y, ll p) {x %= p;ll res = 1;while(y > 0) {if(y&1) res = (res*x)%p;y = y>>1;x = (x*x)%p;}return res;}
ll modInverse(ll x, ll p) {return power(x,p-2,p);}
ll power(ll x, ll y) {ll res = 1; while(y>0) {if(y&1) res = res*x; y = y>>1; x = x*x;}return res;}
 
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
 
 
/* Keep Working Hard Till you Reach Your Goal */
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;cin>>t;

    while(t--)
    {
        string s;
        cin>>s;
      
        ll sum=0,ind=-1;
        
        for(int i = s.size()-1;i>0;i--)
        {
            sum=(s[i]-'0')+(s[i-1]-'0');

            if(sum>=10)
            {
                ind = i-1;
                debug(sum);
                break;
            } 
            
        }

    if(ind!=-1)
    {
        cout<<s.substr(0,ind)<<to_string(sum)<<s.substr(ind+2,s.size())<<endl;
    }
    else{
        cout<<to_string(sum)<<s.substr(2,s.size())<<endl;
    }

    }  

    return 0;
}

