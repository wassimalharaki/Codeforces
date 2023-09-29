#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second


int32_t main() {
    fast;

    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;

        int f = INF, s = INF, b = INF;
        for (int i = 0; i < n; i++) {
            int m; cin >> m;
            string str; cin >> str;
            if (str == "10" && m < f)
                f = m;
            else if (str == "01" && m < s)
                s = m;
            else if (str == "11" && m < b)
                b = m;
        }

        if ((f == INF || s == INF) && b == INF)
            cout << -1 nl;
        else if (f == INF || s == INF)
            cout << b nl;
        else
            cout << min(b, f + s) nl;
    }

    return 0;
}