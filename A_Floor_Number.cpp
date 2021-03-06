#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
            sort(a[i],a[i]+m);
        }
        int dp[n][m];
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        int top[n] = {0};
        int tmp = 0;
        for(int i=0;i<m;i++){
            int mi=INT_MAX, idx;
            for(int j=0;j<n;j++){
                if(top[j]<m){
                    if(a[j][top[j]]<mi){
                        mi = a[j][top[j]];
                        idx = j;
                    }
                }
            }
            dp[idx][i] = a[idx][top[idx]];
            vis[idx][i] = 1;
            top[idx] += 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    dp[i][j] = a[i][top[i]];
                    top[i] += 1;
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
