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
    for (int& a : nums) cin >> a;
    sort(all(nums));

    vvi splits;
    v<bool> ok(n);
    for (int i = 0; i < n; i++) {
        if (ok[i]) continue;
        splits.pb({nums[i]});
        ok[i] = 1;
        for (int j = 0; j < n; j++)
            if (nums[j] == 2 * splits.back().back()) {
                splits.back().pb(nums[j]);
                ok[j] = 1;
            }
    }

    //front of one of the splits is back / 3 of another split
    //but which one should i start with?
    //i should start with the split st its front is not back / 3
    //of any other split
    vi start;
    for (vi& split : splits) {
        bool ok = 1;
        for (vi& other : splits)
            if (split.front() * 3 == other.back()) 
                ok = 0;
        if (ok)
            start = split;
    }

    for (int i = 0; i < splits.size(); i++) {
        for (int& a : start)
            cout << a << " ";
        for (vi& split : splits)
            if (split.front() * 3 == start.back()) {
                start = split;
                break;
            }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}