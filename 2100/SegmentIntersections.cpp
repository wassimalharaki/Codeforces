#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using ai2 = array<int, 2>;

int isectsz(ai2& a, ai2& b) {
    return max(0ll, min(a[1], b[1]) - max(a[0], b[0]));
}

bool isect(ai2& a, ai2& b) {
    return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
}

void solve() {
    int n, k; cin >> n >> k;
    
    v<ai2> a(n), b(n);
    cin >> a[0][0] >> a[0][1]
        >> b[0][0] >> b[0][1];
    
    if (a[0][0] > b[0][0])
        swap(a[0], b[0]);
    
    for (int i = 1; i < n; i++)
        a[i] = a[i - 1], b[i] = b[i - 1];
    
    if (isect(a[0], b[0])) {
        int sz = isectsz(a[0], b[0]) * n, ans = 0;
        for (int i = 0; i < n and sz < k; i++) {
            int l = a[i][0];
            int r = max(a[i][1], b[i][1]);

            {
                int have = a[i][0] + b[i][0] - 2 * l;
                int sub = min(k - sz, have);
                a[i][0] = max(a[i][0] - sub, l);
                b[i][0] = max(b[i][0] - sub, l);
                sz += sub;
                ans += sub;
            }

            {
                int have = 2 * r - a[i][1] - b[i][1];
                int sub = min(k - sz, have);
                a[i][1] = min(a[i][1] + sub, r);
                b[i][1] = min(b[i][1] + sub, r);
                sz += sub;
                ans += sub;
            }
        }
        cout << ans + max(0ll, (k - sz) * 2) << nl;
        return;
    }

    int ans = LLONG_MAX, curr = 0, sz = 0;
    for (int i = 0; i < n and sz < k; i++) {
        int l = a[i][0], r = b[i][1];

        curr += b[i][0] - a[i][1];
        b[i][0] = a[i][1];

        {
            int have = b[i][0] - l;
            int sub = min(k - sz, have);
            b[i][0] -= sub;
            sz += sub;
            curr += sub;
            ans = min(ans, curr + max(0ll, (k - sz) * 2));
        }

        {
            int have = r - a[i][1];
            int sub = min(k - sz, have);
            a[i][1] += sub;
            sz += sub;
            curr += sub;
            ans = min(ans, curr + max(0ll, (k - sz) * 2));
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