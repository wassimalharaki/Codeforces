#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<array<int, 5>> nums(n, {0, 0, 0, 0});
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char& c : s)
            nums[i][c - 'a']++;
    }

    auto sum = [&](int i) -> int {
        int sum = 0;
        for (int j = 0; j < 5; j++)
            sum += nums[i][j];
        return sum;
    };

    auto get = [&](int j) -> int {
        v<bool> dead(n);
        
        int me = 0, you = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int x = sum(i);
            int y = nums[i][j];

            if (y > x - y) {
                dead[i] = 1;
                me += y;
                you += x - y;
                ans++;
            }
        }
        me -= you;

        v<int> choose;
        for (int i = 0; i < n; i++)
            if (not dead[i])
                choose.push_back(sum(i) - 2 * nums[i][j]);
        sort(all(choose));

        for (int i = 0; i < choose.size(); i++)
            if (me - choose[i] > 0) {
                me -= choose[i];
                ans++;
            }
            else break;
        return ans;
    };
    int ans = 0;
    for (int i = 0; i < 5; i++)
        ans = max(ans, get(i));
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}