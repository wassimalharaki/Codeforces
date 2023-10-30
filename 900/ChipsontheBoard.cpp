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

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;

        int rows = 0, cols = 0;
        int mina = INF, minb = INF;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            rows += a;
            mina = min(mina, a);
        }
        for (int i = 0; i < n; i++) {
            int b; cin >> b;
            cols += b;
            minb = min(minb, b);
        }
        cout << min(rows + n * minb, cols + n * mina) nl;
    }

    return 0;
}