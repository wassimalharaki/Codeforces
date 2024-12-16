#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void out(__int128 x) {
    string s;
    bool neg = x < 0;
    if (neg) x *= -1;
    while (x) {
        s += to_string((int) (x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    if (s.empty()) s = "0";
    cout << (neg ? "-" + s : s) << nl;
}

void solve() {
    int n; cin >> n;

    __int128 ans = 0, sum = 0, sz = 0;
    map<int, int> ok;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ok[x]++; sum += x, sz++;

        sum -= ok[x - 1] * (x - 1);
        sz -= ok[x - 1];

        sum -= ok[x] * x;
        sz -= ok[x];

        sum -= ok[x + 1] * (x + 1);
        sz -= ok[x + 1];

        ans += sz * x - sum;
        
        sum += ok[x - 1] * (x - 1);
        sz += ok[x - 1];

        sum += ok[x] * x;
        sz += ok[x];

        sum += ok[x + 1] * (x + 1);
        sz += ok[x + 1];
    }
    out(ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}