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
    string s; cin >> s;
    int n = s.size();

    vi zero(n + 1), one(n + 1);
    for (int i = 0; i < n; i++)
        zero[i + 1] = zero[i] + (s[i] == '1');
    for (int i = n - 1; i >= 0; i--)
        one[i] = one[i + 1] + (s[i] == '0');
    
    int ans = INF;
    for (int i = 0; i <= n; i++)
        ans = min(ans, zero[i] + one[i]);
    
    fill(all(one), 0ll);
    fill(all(zero), 0ll);

    for (int i = 0; i < n; i++)
        one[i + 1] = one[i] + (s[i] == '0');
    for (int i = n - 1; i >= 0; i--)
        zero[i] = zero[i + 1] + (s[i] == '1');

    for (int i = 0; i <= n; i++)
        ans = min(ans, zero[i] + one[i]);
    cout << ans << nl; 
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}