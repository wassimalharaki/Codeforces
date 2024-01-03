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

vvi prep(10, vi());
vi sum(10);

void solve() {
    int n, m; cin >> n >> m;
    int c = n / m;
    m %= 10;
    if (m == 0) {
        cout << 0 nl;
        return;
    }
    int answ = (c / prep[m].size()) * sum[m];
    c %= prep[m].size();
    for (int i = 0; i < prep[m].size() and c--; i++)
        answ += prep[m][i];
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < 10; i++) {
        int x = i;
        prep[i].pb(x);
        while (x)
            x = (x + i) % 10, prep[i].pb(x);
        sum[i] = accumulate(all(prep[i]), 0ll);
    }

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}