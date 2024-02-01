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
    int n, g, b; cin >> n >> g >> b;
    int l = (n + 1) / 2, k = (l + g - 1) / g;
    cout << k * (g + b) - b - (k * g - l) + max(n - l - (k - 1) * b, 0ll) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}