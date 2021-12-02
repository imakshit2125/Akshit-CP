#include <bits/stdc++.h>
#include <sstream>
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

void decToBinary(int n,int arr[] ) 
{ 
    // array to store binary number 
    
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        arr[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    ll no =0;
    int ten=1;

    for(int i : arr)
    cout<<arr[i];

    cout<<endl;
   

  /*  for(int j=0;j<=i;j++)
    {
        no+=(arr[j]*ten);
        ten*=10;
        
    }

    return no; */
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;

        ll sum=0;

       // cout<<sum<<endl;

        int arr[32];
        decToBinary(n,arr);

      /*  for(int i=1;i<=n;i++){
            sum+=decToBinary(i,arr);
            cout<<sum<<endl;
        } */

       
        cout<<endl;

        
    }

    return 0;
}