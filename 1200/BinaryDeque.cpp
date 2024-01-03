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
    int n, s; cin >> n >> s;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    int max = 0, curr = 0, i = 0, j = 0;
    while (j < n) {
        curr += nums[j++];
        if (curr == s)
            max = std::max(max, j - i);
        while (i < n and curr > s)
            curr -= nums[i++];
    }
    cout << (max == 0 ? -1 : n - max) nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}