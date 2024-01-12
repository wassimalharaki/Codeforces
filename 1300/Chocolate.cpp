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

    vi nums;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 0 and nums.empty())
            continue;
        nums.pb(a);
    }

    if (nums.empty()) {
        cout << 0 nl;
        return;
    }
    
    int answ = 1, curr = 1;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i])
            answ *= curr, curr = 1;
        else
            curr++;
    cout << answ;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}