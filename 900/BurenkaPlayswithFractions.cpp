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
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a == 0 and c == 0) {
            cout << 0 nl;
            continue;
        }
        else if (a == 0 or c == 0) {
            cout << 1 nl;
            continue;
        }

        int big = max(a * d, b * c);
        int small = min(a * d, b * c);

        big % small == 0 ?
            big / small == 1 ?
                cout << 0 nl:
                cout << 1 nl:
            cout << 2 nl;
    }

    return 0;
}