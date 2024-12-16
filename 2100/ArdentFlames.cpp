#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

struct line {
    int a = 0, b = 0;

    line() {}
    line(int _a, int _b) {
        a = _a, b = _b;
    }

    int operator()(int x) {
        return a * x + b;
    }
};

struct mountain {
    line a, b;
    int i = 0;
    int x = 0;
    mountain() {}
    mountain(line _a, line _b, int _x, int _i) {
        a = _a, b = _b, x = _x, i = _i;
    }

    bool belongs(int _x, int _y) {
        return _x < x ? _y <= a(_x) : _y <= b(_x);
    }

    friend bool operator<(const mountain& m1, const mountain& m2) {
        if (m1.x == m2.x)
            return m1.i < m2.i;
        return m1.x < m2.x;
    }

    friend bool operator==(const mountain& m1, const mountain& m2) {
        return m1.x == m2.x;
    }
};

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v<array<int, 2>> a(n);
    for (auto& [x, y] : a)
        cin >> y;
    for (auto& [x, y] : a)
        cin >> x;

    auto check = [&](int atk) -> bool {
        v<mountain> b;
        for (int i = 0; i < n; i++) {
            if (atk * m < a[i][1]) continue;
            {
                int lo = a[i][0], hi = 3e9, x = a[i][0];
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if (line(atk, atk * (m - mid))(a[i][0]) >= a[i][1])
                        x = mid, lo = mid + 1;
                    else
                        hi = mid - 1;
                }

                line l1(atk, atk * (m - x));
                line l2(- atk, atk * (m + x));
                b.push_back(mountain(l1, l2, x, 2 * i));
            }

            {
                int lo = -3e9, hi = a[i][0], x = a[i][0];
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if (line(- atk, atk * (m + mid))(a[i][0]) >= a[i][1])
                        x = mid, hi = mid - 1;
                    else
                        lo = mid + 1;
                }

                line l1(atk, atk * (m - x));
                line l2(- atk, atk * (m + x));
                b.push_back(mountain(l1, l2, x, 2 * i + 1));
            }
        }
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        if (b.empty()) return 0;

        int sz = b.size();
        v<int> diff(sz + 1);
        for (auto& [x, y] : a) {
            int j = lower_bound(b.begin(), b.end(), x, [](auto& m1, int _x) {
                return m1.x < _x;
            }) - b.begin();
            int w = -1;
            if (j == sz) {
                j--;
                if (b[j].belongs(x, y))
                    w = j;
            }
            else {
                if (b[j].belongs(x, y))
                    w = j;
                j--;
                if (j >= 0 and b[j].belongs(x, y))
                    w = j;
            }
            if (w == -1) continue;

            int l = w, r = w;
            {
                int lo = r + 1, hi = sz - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if (b[mid].belongs(x, y))
                        r = mid, lo = mid + 1;
                    else
                        hi = mid - 1;
                }
            }
            {
                int lo = 0, hi = l - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if (b[mid].belongs(x, y))
                        l = mid, hi = mid - 1;
                    else
                        lo = mid + 1;
                }
            }

            diff[l]++;
            diff[r + 1]--;
        }

        int curr = 0;
        for (int i = 0; i <= sz; i++) {
            curr += diff[i];
            diff[i] = curr;
        }

        return *max_element(diff.begin(), diff.end() - 1) >= k;
    };

    int lo = 1, hi = 1e9, ans = -1;
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
    cin >> T;
    while (T--) solve();
}