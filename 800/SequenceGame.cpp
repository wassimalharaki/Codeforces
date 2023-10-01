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

        vi b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];
        
        vi a{b[0]};
        for (int i = 1; i < n; i++)
            b[i] >= b[i - 1] ?
                a.pb(b[i]):
                a.pb(b[i]), a.pb(b[i]);
        
        cout << a.size() nl;
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout nl;
    }

    return 0;
}