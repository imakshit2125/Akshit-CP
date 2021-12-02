#include <bits/stdc++.h>
using namespace std;

int pref(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0, maxe = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxe = max(maxe, sum);
    }

    return maxe;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> r(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> r[i];
        }
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> b[i];
        }
        int x = pref(r);
        int y = pref(b);
        if (x + y > 0)
        {
            cout << x + y << "\n";
        }
        else
        {
            cout << "0\n";
        }
    }
    return 0;
}