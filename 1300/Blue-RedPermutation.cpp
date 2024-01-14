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

    map<int, int> reds, blues;
    vi nums(n);
    for (int& a : nums) cin >> a;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        c == 'B' ? blues[nums[i]]++ : reds[nums[i]]++;
    }

    int sum = 0;
    for (auto& [key, val] : blues) {
        if (key >= n) break;
        sum += val;
        if (sum > key) {
            cout << "NO" nl;
            return;
        }
    }
    
    sum = 0;
    for (auto it = reds.rbegin(); it != reds.rend(); it++) {
        auto& [key, val] = *it;
        if (key <= 1) break;
        sum += val;
        if (sum > n - key + 1) {
            cout << "NO" nl;
            return;
        }
    }
    cout << "YES" nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}