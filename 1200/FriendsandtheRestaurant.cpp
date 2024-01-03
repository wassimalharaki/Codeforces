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
    int n; cin >> n;

    vi x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];
    
    vi rich, poor;
    for (int i = 0; i < n; i++) {
        int net = y[i] - x[i];
        net >= 0 ? rich.pb(net) : poor.pb(- net);
    }
    sort(all(rich)); sort(all(poor));

    if (poor.size() == 0) {
        cout << n / 2 nl;
        return;
    }
    if (rich.size() == 0) {
        cout << 0 nl;
        return;
    }

    int k = 0, j = 0, answ = 0;
    for (int i = 0; i < poor.size() and j < rich.size(); i++) {
        while (j < rich.size() and rich[j] < poor[i])
            j++, k++;
        if (j < rich.size())
            answ++, j++;
    }
    cout << answ + (rich.size() - j + k) / 2 nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}