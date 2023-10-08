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
        int x; cin >> x;

        string s;
        for (int i = 9; i > 0; i--)
            if (x - i >= 0) {
                s += to_string(i), x -= i;
                if (not x)
                    break;
            }
        reverse(all(s));
        x ? cout << -1 nl : cout << s nl;
    }

    return 0;
}