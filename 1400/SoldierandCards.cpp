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
    int n; cin >> n;
    int k; cin >> k;
    
    queue<int> a, b;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        a.push(x);
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        b.push(x);
    }

    int rounds = 0;
    while (1) {
        if (rounds == 1e6) break;
        int x = a.front(), y = b.front();
        a.pop(); b.pop();
        if (x > y) {
            a.push(y);
            a.push(x);
        }
        else {
            b.push(x);
            b.push(y);
        }
        rounds++;
        if (a.empty() or b.empty()) {
            cout << rounds << " " << a.empty() + 1;
            return;
        }
    }
    cout << -1;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}