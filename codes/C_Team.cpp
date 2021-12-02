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

    int t;
    cin >> t;
    while (t--)
    {
      ll n,k;
      cin>>n>>k;
      ll arr[n];
      fo(i,n)cin>>arr[i];

      sort(arr,arr+n);

      int i = 0;
      int j= n-1;

      ll c=0; // 6 7 8

      while(i<j){
          if(arr[j]>=k)
          {
              c++;
              j--;
          }

          else if(arr[i]+arr[j]>=k)
          {
              i++;
              j--;
              c++;
          }

          else if(arr[i]+arr[j]<k)
          {
              i++;
          }

        //  cout<<i<<" "<<j<<endl;
      }

      if(i==j)
      {
          if(arr[i]>=k)
          c++;
      }


      cout<<c<<endl;
    }
}