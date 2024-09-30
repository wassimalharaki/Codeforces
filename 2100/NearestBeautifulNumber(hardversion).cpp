#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

string go(int n, int k) {
    string s = to_string(n);

    while (1) {
        int m = s.size();

        set<char> good;
        int j = -1;
        for (int i = 0; i < m; i++) {
            if (good.size() == k and not good.count(s[i])) {
                j = i;
                break;
            }
            good.insert(s[i]);
        }
        if (j == -1) return s;

        auto it = good.lower_bound(s[j]);
        if (it == good.end()) {
            s[j - 1]++;
            while (j < m)
                s[j++] = '0';
            continue;
        }

        s[j++] = *it;
        while (j < m)
            s[j++] = *good.begin();
        return s;
    }
}

void solve() {
    int n, k; cin >> n >> k;
    cout << go(n, k) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}