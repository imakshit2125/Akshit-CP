#include <bits/stdc++.h>
using namespace std;

//const int N=100023;
int main()
{
    int N;cin>>N;

    int primefactor[N]; 
   
    for(int i=1;i<N;i++)
    {
        primefactor[i]=0;
    }
    for(int i=2;i<N;i++)
    {
        if(primefactor[i]==0)  
            primefactor[i]=i;

        for(int j=i;j<N;j+=i)
        {
            if(primefactor[j]==0)
            primefactor[j]=i;
        }
             
    }

    for(int i=1;i<N;i++)
    cout<<primefactor[i]<<" ";

   
}
