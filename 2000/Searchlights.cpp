#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 2e6 + 2;

void solve() {
    int n, m; cin >> n >> m;

    v<array<int, 2>> a(n), b(m);
    for (auto& [x, y] : a)
        cin >> x >> y;
    for (auto& [x, y] : b)
        cin >> x >> y;
    
    {
        v<int> kill(m);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                if (i != j)
                    if ((b[i][0] <= b[j][0] and b[i][1] < b[j][1])
                            or (b[i][0] < b[j][0] and b[i][1] <= b[j][1]))
                        kill[i] = 1;

        v<array<int, 2>> c;
        for (int i = 0; i < m; i++)
            if (not kill[i])
                c.push_back(b[i]);
        c.swap(b);
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        b.insert(b.begin(), {-1, INT_MAX});
        m = b.size();
        b.push_back({INT_MAX, -1});
    }

    auto check = [&](int k) -> bool {
        v<int> diff(N);
        for (int i = 0; i < n; i++) {
            v<array<int, 2>> ranges;
            for (int j = 0; j < m; j++) {
                int right = max(0ll, b[j][0] - a[i][0] + 1);
                int up = max(0ll, b[j + 1][1] - a[i][1] + 1);
                if (right + up > k) continue;
                int free = k - (up + right);
                ranges.push_back({right, right + free});
            }
            if (a[i][1] > b[0][1]) ranges.push_back({0, k});
            if (ranges.empty()) return 0;
            v<array<int, 2>> clean{ranges[0]};
            for (int j = 1; j < (int) ranges.size(); j++)
                if (ranges[j][0] <= clean.back()[1])
                    clean.back()[1] = max(clean.back()[1], ranges[j][1]);
                else
                    clean.push_back(ranges[j]);
            for (auto& [l, r] : clean)
                diff[l]++, diff[r + 1]--;
        }
        
        int curr = 0;
        for (int i = 0; i < N; i++) {
            curr += diff[i];
            if (curr == n) return 1;
        }
        return 0;
    };

    int lo = 0, hi = 2e6 + 10, ans = 2e6 + 10;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}