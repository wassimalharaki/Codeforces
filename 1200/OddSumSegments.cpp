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
    int n, k; cin >> n >> k;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    vi answ;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr += nums[i];
        if ((curr & 1) and answ.size() != k - 1) {
            curr = 0;
            answ.pb(i + 1);
        }
    }

    if (!(curr & 1) or answ.size() != k - 1) {
        cout << "NO" nl;
        return;
    }
    answ.pb(n);

    cout << "YES" nl;
    for (int i = 0; i < answ.size(); i++)
        cout << answ[i] << " ";
    cout nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}