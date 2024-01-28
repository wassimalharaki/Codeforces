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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n; cin >> n;

    vi a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    vvi unis(n + 1), prefix(n + 1);
    unordered_set<int, custom_hash> alive;
    for (int i = 0; i < n; i++) {
        alive.insert(a[i]);
        unis[a[i]].pb(b[i]);
    }

    for (int x : alive) {
        sort(rall(unis[x]));
        prefix[x].pb(0);
        for (int i = 0; i < unis[x].size(); i++)
            prefix[x].pb(prefix[x].back() + unis[x][i]);
    }
    
    for (int k = 1; k <= n; k++) {
        int sum = 0;
        vi kill;
        for (int x : alive) {
            int b = unis[x].size() / k * k;
            if (b == 0)
                kill.pb(x);
            sum += prefix[x][b];
        }
        for (int x : kill)
            alive.erase(x);
        cout << sum << " ";
    }
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}