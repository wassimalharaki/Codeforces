#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define nl '\n'
#define v vector

template<typename T>
using indexed_set = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

const int N = 26;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string t = s;
    reverse(t.begin(), t.end());

    array<v<int>, N> a;
    for (int i = 0; i < n; i++)
        a[s[i] - 'a'].push_back(i);
    for (int i = 0; i < N; i++)
        reverse(a[i].begin(), a[i].end());

    indexed_set<int> ok;
    for (int i = 0; i < n; i++)
        ok.insert(i);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto& b = a[t[i] - 'a'];
        ans += ok.order_of_key(b.back());
        ok.erase(b.back());
        b.pop_back();
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