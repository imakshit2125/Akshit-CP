#include<bits/stdc++.h>
#define vi vector<ll>
#define pb push_back
typedef long long ll;
using namespace std;
const ll mod = 1000000007;

#define pi 3.1415926535
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x) ;  cerr<< "\n";
#else
#define debug(x)
#endif
#define          sz(a)               (int)a.size()


void _print(int a) {cerr << a;}
void _print(bool a) {cerr << a;}
void _print(ll a) {cerr << a;}

///////////////
template <class T> void _print(std::vector<T> v) {cerr << "[ "; for (T i  : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(std::set<T>s) {cerr << "[ "; for (T i  : s) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(std::multiset<T>s) {cerr << "[ "; for (T i  : s) {_print(i); cerr << " ";} cerr << "]";}
///////////////
ll mod_add(ll a, ll b, ll M) {a = a % M; b = b % M; return (((a + b) % M) + M) % M;}
ll mod_mul(ll a, ll b, ll M) {a = a % M; b = b % M; return (((a * b) % M) + M) % M;}
ll mod_sub(ll a, ll b, ll M) {a = a % M; b = b % M; return (((a - b) % M) + M) % M;}
//ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, modInverse(b, m), m) + m) % m;} //only for prime m



int main()
{

#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 freopen("Error.txt", "W", stderr);
#endif
 //fastio();
 //ll t = 1 ;
 int t;
 cin >> t;


 while (t--)
 {

  int n, k, sum = 0;
  string s;
  cin >> n >> k;
  cin >> s;

  for (int i = 1; i < n ; i++) {
   if (s[i] != s[i - 1])sum += 1;
   else sum += 2;
  }

  while (k--) {
   int ru;
   cin >> ru;
   --ru;

   s[ru] ^= 1;

   // cout<<s<<'\n';

   if (s[ru] != s[ru - 1] && ru >= 1)
    sum--;
   else if (s[ru] == s[ru - 1] && ru >= 1)
    sum++;

   if (s[ru] != s[ru + 1] && ru <= n - 2)
    sum--;
   else if (s[ru] == s[ru + 1] && ru <= n - 2)
    sum++;

   cout << sum << '\n';
  }






 }
}