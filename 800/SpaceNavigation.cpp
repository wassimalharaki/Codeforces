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
        int x, y; cin >> x >> y;
        string s; cin >> s;

        int u = 0, d = 0, l = 0, r = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'U')
                u++;
            else if (s[i] == 'D')
                d++;
            else if (s[i] == 'L')
                l++;
            else
                r++;
        
        x >= -l && x <= r && y >= -d && y <= u ?
            cout << "YES" nl:
            cout << "NO" nl;
    }

    return 0;
}