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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vi letters(26);
    for (char& c : s)
        letters[c - 'A']++;
    sort(rall(letters));

    int ans = 0;
    for (int i = 0; i < 26 and k; i++) {
        int sub = min(k, letters[i]);
        ans += sub * sub;
        k -= sub;
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}