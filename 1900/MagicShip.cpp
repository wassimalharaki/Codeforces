#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using ai2 = array<int, 2>;

ai2 operator+(const ai2& l, const ai2& r) {
    return {l[0] + r[0], l[1] + r[1]};
}

map<char, ai2> mapping {
    {'U', {0, 1}},
    {'D', {0, -1}},
    {'R', {1, 0}},
    {'L', {-1, 0}}
};

void solve() {
    ai2 src, dst;
    cin >> src[0] >> src[1];
    cin >> dst[0] >> dst[1];

    int n; cin >> n;
    string s; cin >> s;
    int dx = count(s.begin(), s.end(), 'R') - count(s.begin(), s.end(), 'L');
    int dy = count(s.begin(), s.end(), 'U') - count(s.begin(), s.end(), 'D');

    auto check = [&](int k) -> int {
        ai2 end {
            src[0] + dx * k,
            src[1] + dy * k
        };
        //i am allowed n * k moves
        if (abs(end[0] - dst[0]) + abs(end[1] - dst[1]) <= n * k)
            return n * k;
        for (int i = 0; i < n; i++) {
            end = end + mapping[s[i]];
            if (abs(end[0] - dst[0]) + abs(end[1] - dst[1]) <= n * k + i + 1)
                return n * k + i + 1;
        }
        return -1;
    };

    int lo = 0, hi = 1e14, ans = LLONG_MAX;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int k = check(mid);

        if (k != -1)
            hi = mid - 1, ans = min(ans, k);
        else
            lo = mid + 1;
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}