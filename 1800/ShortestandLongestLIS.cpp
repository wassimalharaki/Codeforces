#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    v<array<int, 2>> a{{s[0], 1}};
    for (int i = 1; i < n - 1; i++)
        if (s[i] == s[i - 1])
            a.back()[1]++;
        else
            a.push_back({s[i], 1});
    
    v<int> min(n);
    auto go_min = [&](int i, int j, int l, int r, auto&& go_min) -> void {
        if (i >= a.size())
            return;
        else if (i == a.size() - 1) {
            if (a[i][0] == '>')
                while (j < n)
                    min[j++] = r--;
            else
                while (j < n)
                    min[j++] = l++;
        }
        else if (a[i][0] == '<') {
            for (int k = a[i][1]; k >= 0; k--)
                min[k] = r--;
            j = a[i][1] + 1;
            go_min(i + 1, j, l, r, go_min);
        }
        else if (i == 0) {
            array<int, 2> sz{a[i][1] + 1, a[i + 1][1]};
            j = sz[0] + sz[1];
            for (int k = j - 1; k >= j - sz[1]; k--)
                min[k] = r--;
            for (int k = 0; k < sz[0]; k++)
                min[k] = r--;
            go_min(i + 2, j, l, r, go_min);
        }
        else {
            array<int, 2> sz{a[i][1], a[i + 1][1]};
            j += sz[0] + sz[1];
            for (int k = j - 1; k >= j - sz[1]; k--)
                min[k] = r--;
            j -= sz[0] + sz[1];
            for (int k = j; k < j + sz[0]; k++)
                min[k] = r--;
            j += sz[0] + sz[1];
            go_min(i + 2, j, l, r, go_min);
        }
    };
    go_min(0, 0, 1, n, go_min);

    v<int> max(n);
    auto go_max = [&](int i, int j, int l, int r, auto&& go_max) -> void {
        if (i >= a.size())
            return;
        else if (i == a.size() - 1) {
            if (a[i][0] == '>')
                while (j < n)
                    max[j++] = r--;
            else
                while (j < n)
                    max[j++] = l++;
        }
        else if (a[i][0] == '>') {
            for (int k = a[i][1]; k >= 0; k--)
                max[k] = l++;
            j = a[i][1] + 1;
            go_max(i + 1, j, l, r, go_max);
        }
        else if (i == 0) {
            array<int, 2> sz{a[i][1], a[i + 1][1] + 1};
            while (j < sz[0])
                max[j++] = l++;
            for (int k = j + sz[1] - 1; k >= j; k--)
                max[k] = l++;
            j = sz[0] + sz[1];
            go_max(i + 2, j, l, r, go_max);
        }
        else {
            array<int, 2> sz{a[i][1] - 1, a[i + 1][1] + 1};
            for (int k = j; k < j + sz[0]; k++)
                max[k] = l++;
            for (int k = j + sz[0] + sz[1] - 1; k >= j + sz[0]; k--)
                max[k] = l++;
            j += sz[0] + sz[1];
            go_max(i + 2, j, l, r, go_max);
        }
    };
    go_max(0, 0, 1, n, go_max);

    for (int& x : min)
        cout << x << " ";
    cout << nl;
    for (int& x : max)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}