#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 20;

void solve() {
    int n; cin >> n;

    v<int> a(n), cnt(n + 1);
    for (int& x : a)
        cin >> x, cnt[x]++;
    sort(a.begin(), a.end());
    v<int> pref(n + 2);
    partial_sum(cnt.begin(), cnt.end(), pref.begin() + 1);

    int ans = 1e9;
    for (int x = 0; x < N; x++) {
        int i = n, xans = 0;
        {
            int curr = 0;
            for (; i >= 0; i--)
                if (curr + cnt[i] <= (1 << x))
                    curr += cnt[i];
                else break;

            xans = (1 << x) - curr;
        }
        {
            for (int y = 0; y < N; y++) {
                int j = i, curr = 0, yans = 0;
                for(; j >= 0; j--)
                    if (curr + cnt[j] <= (1 << y))
                        curr += cnt[j];
                    else break;

                yans = (1 << y) - curr;
                curr = pref[j + 1];

                if (curr == 0)
                    yans++;
                else if ((curr & (curr - 1)) != 0)
                    yans += (1 << (__lg(curr) + 1)) - curr;
                ans = min(ans, xans + yans);
            }
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}