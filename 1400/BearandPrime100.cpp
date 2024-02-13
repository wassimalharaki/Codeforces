#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    vi nums{2, 3, 4, 5, 7, 9, 11, 13, 17, 19,
        23, 25, 29, 31, 37, 41, 43, 47, 49, 53};
    int a = 0;
    for (int i = 0; i < 20; i++) {
        cout << nums[i] << nl << flush;
        string s; cin >> s;
        if (s == "yes") a++;
    }
    cout << (a < 2 ? "prime" : "composite") << nl << flush;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}