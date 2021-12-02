#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--)
    {
      ll n,m;
      cin>>n>>m;
      
      char arr[n][m];
      char arr1[n][m];
      char arr2[n][m];

      ll ans1=0,ans2=0;
      
      fo(i,n){
          fo(j,m)cin>>arr[i][j];
      }
      
    //  ll ans1=0,ans2=0;
     
      fo(i,n)
      {
          fo(j,m)
          {
              if(m%2==1)
              {
                  if(j%2==0)
                  arr1[i][j]='*';
                  
                  else
                  arr1[i][j]='.';
              }
              
              else
              {
                  if(i%2==0)
                  {
                      if(j%2==0)
                      arr1[i][j]='*';
                      
                      else 
                      arr1[i][j]='.';
                  }
                  
                  else
                  {
                      if(j%2==0)
                      arr1[i][j]='.';
                      
                      else
                      arr1[i][j]='*';
                  }
              }
          }
      }

      fo(i,n)
      {
          fo(j,m)
          {
              if(m%2==1)
              {
                  if(j%2==0)
                  arr2[i][j]='.';
                  
                  else
                  arr2[i][j]='*';
              }
              
              else
              {
                  if(i%2==0)
                  {
                      if(j%2==0)
                      arr2[i][j]='.';
                      
                      else 
                      arr2[i][j]='*';
                  }
                  
                  else
                  {
                      if(j%2==0)
                      arr2[i][j]='*';
                      
                      else
                      arr2[i][j]='.';
                  }
              }
          }
      }
      
      

       fo(i,n)
      {
          fo(j,m)
          {
              if(arr[i][j]!=arr1[i][j])
              ans1++;
          }
      }
      
      fo(i,n)
      {
          fo(j,m)
          {
              if(arr[i][j]!=arr2[i][j])
              ans2++;
          }
      }

      cout<<ans1<<" "<<ans2<<endl;
    }
    
    
    return 0;
}   