#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

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

    vi count(n), nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        count[nums[i]]++;
    }

    while (count.back() == 0)
        count.pop_back();

    if (count[1] != 2) {
        cout << 0 << nl;
        return;
    }

    int a = 2;
    for (int i = 1; i < count.size(); i++) {
        if (count[i] == a) continue;
        if (a == 2) {
            if (count[i] != 1) {
                cout << 0 << nl;
                return;
            }
            a = 1;
        }
        else {
            cout << 0 << nl;
            return;
        }
    }

    int small = 0, big = count.size() - 1;
    for (int i = 1; i < n; i++)
        if (count[i] == 2)
            small = i;

    vpii ans;
    {
        vi first(small + 1);
        for (int i = 0; i < small; i++)
            if (nums[i] <= small)
                first[nums[i]]++;
        if (*min_element(1 + all(first)) == 1)
            ans.pb(mp(small, n - small));
    }

    if (big != small) {
        vi second(big + 1);
        for (int i = 0; i < big; i++)
            if (nums[i] <= big)
                second[nums[i]]++;
        if (*min_element(1 + all(second)) == 1)
            ans.pb(mp(big, n - big));
    }

    cout << ans.size() << nl;
    for (pii& p : ans)
        cout << p.F << ' ' << p.S << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}