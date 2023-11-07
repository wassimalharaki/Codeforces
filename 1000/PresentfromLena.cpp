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

    int n; cin >> n;

    for (int i = 0; i < 2 * n + 1; i++) {
        int mxn = min(i, 2 * n - i);

        for (int j = 0; j < 2 * (n - mxn); j++)
            cout << ' ';
        if (mxn == 0) {
            cout << 0 nl;
            continue;
        }
        for (int j = 0; j <= mxn; j++)
            cout << j << ' ';
        for (int j = mxn - 1; j > 0; j--)
            cout << j << ' ';
        cout << 0 nl;
    }

    return 0;
}