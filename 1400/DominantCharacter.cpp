#include <bits/stdc++.h>

using namespace std;

void dbg_out() { cerr << '\n'; }
template<typename T> void dbg_out(vector<T>& a) { for (auto& b : a) cerr << ' ' << b; cerr << '\n'; }
template<typename H, typename... T> void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#ifdef WASSIM
#define dbg(...) cerr << '[' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
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
    string s; cin >> s;

    vi pos;
    vvi pref(n + 1, vi(3));
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') pos.pb(i);
        pref[i + 1] = pref[i];
        pref[i + 1][s[i] - 'a']++;
    }
    
    int ans = INF;
    for (int i = 1; i < pos.size(); i++) {
        int l = pos[i - 1], r = pos[i];
        int b = pref[r][1] - pref[l + 1][1];
        int c = pref[r][2] - pref[l + 1][2];
        if (b < 2 and c < 2)
            ans = min(ans, r - l + 1);
    }

    for (int i = 2; i < pos.size(); i++) {
        int l = pos[i - 2], r = pos[i];
        int b = pref[r][1] - pref[l + 1][1];
        int c = pref[r][2] - pref[l + 1][2];
        if (b < 3 and c < 3)
            ans = min(ans, r - l + 1);
    }
    cout << (ans == INF ? -1 : ans) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}