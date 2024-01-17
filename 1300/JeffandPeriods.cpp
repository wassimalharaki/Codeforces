#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
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

    map<int, vi> map;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        map[a].pb(i);
    }

    vpii answ;
    for (auto& [key, nums] : map) {
        if (nums.size() == 1) {
            answ.pb(mp(key, 0));
            continue;
        }
        int diff = nums[1] - nums[0];
        bool ok = 1;
        for (int i = 2; i < nums.size(); i++)
            if (diff != nums[i] - nums[i - 1])
                ok = 0;
        if (ok) answ.pb(mp(key, diff));
    }

    cout << answ.size() nl;
    for (int i = 0; i < answ.size(); i++)
        cout << answ[i].F << " " << answ[i].S nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}