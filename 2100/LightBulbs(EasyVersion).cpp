#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 998244353;

void solve() {
    int n; cin >> n;

    v<int> a(2 * n);
    v<v<int>> b(n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        b[--a[i]].push_back(i);
    }

    v<array<int, 2>> r, curr;
    for (auto& x : b)
        r.push_back({x[0], x[1]});
    sort(r.begin(), r.end());

    v<int> works(n);
    int ansz = 0, anscnt = 1, rb = -1;
    for (int i = 0; i < n; i++) {
        if (r[i][0] == rb + 1 and curr.size()) {
            fill(works.begin(), works.end(), 0ll);

            stack<int> ok;
            ok.push(a[curr[0][0]]);

            while (ok.size()) {
                int j = ok.top();
                ok.pop();
                if (works[j]) continue;
                works[j] = 1;

                for (int k = b[j][0] + 1; k < b[j][1]; k++)
                    if (b[a[k]][0] < b[j][0] or b[a[k]][1] > b[j][1])
                        ok.push(a[k]);
            }

            int x = accumulate(works.begin(), works.end(), 0ll);
            anscnt = anscnt * 2 * x % mod;
            curr.clear();
        }
        curr.push_back(r[i]);
        ansz += r[i][0] == rb + 1;
        rb = max(rb, r[i][1]);
    }

    {
        fill(works.begin(), works.end(), 0ll);

        stack<int> ok;
        ok.push(a[curr[0][0]]);

        while (ok.size()) {
            int j = ok.top();
            ok.pop();
            if (works[j]) continue;
            works[j] = 1;

            for (int k = b[j][0] + 1; k < b[j][1]; k++)
                if (b[a[k]][0] < b[j][0] or b[a[k]][1] > b[j][1])
                    ok.push(a[k]);
        }

        int x = accumulate(works.begin(), works.end(), 0ll);
        anscnt = anscnt * 2 * x % mod;
        curr.clear();
    }
    cout << ansz << " " << anscnt << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}