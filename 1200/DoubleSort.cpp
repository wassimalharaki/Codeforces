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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    vpii answ;
    for (int i = 0; i < n; i++) {
        unordered_set<int, custom_hash> options_a{i}, options_b{i};
        int min = i;

        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) {
                min = j;
                options_a.clear();
                options_a.insert(j);
            }
            else if (a[j] == a[min])
                options_a.insert(j);

        min = i;
        for (int j = i + 1; j < n; j++)
            if (b[j] < b[min]) {
                min = j;
                options_b.clear();
                options_b.insert(j);
            }
            else if (b[j] == b[min])
                options_b.insert(j);

        bool ok = 0;
        for (int x : options_a)
            if (options_b.count(x)) {
                ok = 1;
                if (i == x)
                    break;
                swap(a[i], a[x]);
                swap(b[i], b[x]);
                answ.pb(mp(i + 1, x + 1));
                break;
            }
        
        if (not ok) {
            cout << -1 nl;
            return;
        }
    }

    cout << answ.size() nl;
    for (int i = 0; i < answ.size(); i++)
        cout << answ[i].F << " " << answ[i].S nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}