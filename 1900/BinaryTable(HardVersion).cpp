#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v a(n, v<int>(m));
    for (auto& x : a) {
        string s; cin >> s;
        for (int i = 0; i < m; i++)
            x[i] = s[i] == '1';
    }

    v<array<int, 6>> ans;

    auto front = [&](v<array<int, 3>>& b) -> void {
        array<int, 6> x;
        for (int i = 0; i < 3; i++) {
            x[2 * i] = b[i][1];
            x[2 * i + 1] = b[i][2];
            a[b[i][1]][b[i][2]] = b[i][0] = !b[i][0];
        }
        ans.push_back(x);
    };

    auto back = [&](v<array<int, 3>>& b) -> void {
        array<int, 6> x;
        for (int i = 3; i; i--) {
            x[2 * (3 - i)] = b[i][1];
            x[2 * (3 - i) + 1] = b[i][2];
            a[b[i][1]][b[i][2]] = b[i][0] = !b[i][0];
        }
        ans.push_back(x);
    };

    auto handle2x2 = [&](v<array<int, 3>>& b) -> void {
        sort(b.begin(), b.end());
        int cnt = 0;
        for (int i = 0; i < 4; i++)
            cnt += b[i][0];

        if (cnt == 4) {
            front(b);
            sort(b.begin(), b.end());
            cnt = 0;
            for (int i = 0; i < 4; i++)
                cnt += b[i][0];
        }

        if (cnt == 1) {
            back(b);
            sort(b.begin(), b.end());
            cnt = 0;
            for (int i = 0; i < 4; i++)
                cnt += b[i][0];
        }

        if (cnt == 2) {
            front(b);
            sort(b.begin(), b.end());
            cnt = 0;
            for (int i = 0; i < 4; i++)
                cnt += b[i][0];
        }

        if (cnt == 3) {
            back(b);
            sort(b.begin(), b.end());
            cnt = 0;
            for (int i = 0; i < 4; i++)
                cnt += b[i][0];
        }
    };

    auto push1x2 = [&](v<array<int, 3>>& b) -> void {
        if (b[0][0] == 1 and b[1][0] == 1)
            front(b);
        else if (b[0][0] == 0 and b[1][0] == 1)
            back(b);
        else if (b[0][0] == 1 and b[1][0] == 0)
            swap(b[0], b[1]), back(b);
    };

    auto get = [&](int i, int j) -> v<array<int, 3>> {
        v<array<int, 3>> b;
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    b.push_back({a[i + k][j + l], i + k, j + l});
        return b;
    };

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - (m & 1); j += 2) {
            v<array<int, 3>> b = get(i, j);
            push1x2(b);
        }
        if (m & 1)
            for (int j : {m - 2}) {
                v<array<int, 3>> b = get(i, j);
                push1x2(b);
            }
    }

    for (int i : {n - 2}) {
        for (int j = 0; j < m - 2; j++) {
            v<array<int, 3>> b = get(i, j);
            swap(b[1], b[2]);
            push1x2(b);
        }
        for (int j : {m - 2}) {
            v<array<int, 3>> b = get(i, j);
            handle2x2(b);
        }
    }

    cout << ans.size() << nl;
    for (auto& x : ans)
        for (int i = 0; i < 6; i++)
            cout << x[i] + 1 << " \n"[i == 5];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}