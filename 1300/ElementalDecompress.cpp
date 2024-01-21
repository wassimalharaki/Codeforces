#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    int n; cin >> n;

    vi nums(n);
    map<int, vi> map;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        map[nums[i]].pb(i);
    }

    vi a(n), b(n);
    set<int> used;
    for (int i = 0; i < n; i++)
        used.insert(i + 1);
    for (auto& [key, ind] : map)
        if (ind.size() == 1) {
            a[ind[0]] = key;
            b[ind[0]] = key;
            used.erase(key);
        }
        else if (ind.size() == 2)
            used.erase(key);
        else {
            cout << "NO" << nl;
            return;
        }
    
    for (auto it = map.rbegin(); it != map.rend(); it++) {
        auto& [key, ind] = *it;
        if (ind.size() != 2) continue;
        int last = *used.rbegin();
        if (last > key) {
            cout << "NO" << nl;
            return;
        }
        a[ind[0]] = key, a[ind[1]] = last;
        b[ind[1]] = key, b[ind[0]] = last;
        used.erase(last);
    }

    cout << "YES" << nl;
    for (int& x : a) cout << x << " ";
    cout << nl;
    for (int& x : b) cout << x << " ";
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}