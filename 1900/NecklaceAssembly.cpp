#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 26;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    array<int, N> cnt; cnt.fill(0);
    for (char& c : s) cnt[c - 'a']++;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        v<int> dead(i), sz;
        int curr = 0;
        for (int j = 0; j < i; j++) {
            if (dead[j]) continue;
            curr = 0;
            int m = j;
            while (not dead[m]) {
                dead[m] = 1;
                curr++;
                m = (m + k) % i;
            }
            sz.push_back(curr);
        }

        sort(sz.rbegin(), sz.rend());
        multiset<int> have;
        for (int j = 0; j < N; j++)
            have.insert(cnt[j]);
        
        bool ok = 1;
        for (int& x : sz) {
            auto it = have.lower_bound(x);
            if (it == have.end()) {
                ok = 0;
                break;
            }
            int y = *it - x;
            have.erase(it);
            have.insert(y);
        }
        if (ok) ans = i;
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