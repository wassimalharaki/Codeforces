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

bool contains(string& s, string& t) {
    int n = s.size(), m = t.size();
    vvi dp(n + 1, vi(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return dp[n][m] == m;
}

void solve() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    if (contains(s, t)) {
        cout << "automaton";
        return;
    }

    vi a(26), b(26);
    for (int i = 0; i < n; i++)
        a[s[i] - 'a']++;
    for (int i = 0; i < m; i++)
        b[t[i] - 'a']++;
    
    bool ok = 1;
    for (int i = 0; i < 26; i++)
        if (b[i] > a[i]) ok = 0;
    
    cout << (ok ? (n == m ? "array" : "both") : "need tree");
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}